#include <stdio.h>
#include <string.h>

 
/**
 * Fungsi untuk mengecek apakah tahun kabisat
 * @param int year
 * @return 1 jika tahun kabisat, 0 jika bukan
 */
int isLeapYear(int year) {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)){
        return 1;
      } else {
        return 0;
      }
}

/**
 * Fungsi untuk mendapatkan jumlah hari dalam bulan tertentu
 * @param int month, year
 * @param int year
 * @return total hari dalam bulan tertentu
 */
int getDaysInMonth(int month, int year) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year) && month == 2){
        return 29;
    } else {
        return daysInMonth[month];
    }
}


/**
 * Fungsi untuk mengecek apakah suatu tanggal valid
 * @param int day
 * @param int month
 * @param int year
 * @return 1 jika valid, 0 untuk sebaliknya
 */
int isValidDate(int day, int month, int year) {
    int hari = getDaysInMonth(month, year);
    if ((day >= 1 && day <= hari) && (month >= 1 && month <= 12) && (year >= 1)){
      return 1;
    } else {
      return 0;
    }
}


/**
 * Fungsi untuk mendapatkan hari dalam seminggu menggunakan Zeller’s Congruence
 * @param int day
 * @param int month
 * @param int year
 * @return string berupa hari apa pada tanggal tersebut
 */
const char* getDayOfWeek(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int K = year % 100;
    int J = year / 100;
    int h = (day + (13 * (month + 1)) / 5 + K + (K / 4) + (J / 4) - (2 * J)) % 7;
    
    const char* days[] = {"Sabtu", "Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat"};
    return days[h];
}

/**
 * Fungsi untuk mendapatkan zodiak berdasarkan tanggal
 * @param int day
 * @param int month
 * @return string berupa zodiak dari tanggal tersebut
 */
const char* getZodiac(int day, int month) {
    const char* zodiacSigns[] = {
        "Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini",
        "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn"
    };
    int zodiacStartDays[] = {20, 19, 21, 20, 21, 21, 23, 23, 23, 23, 22, 22, 20};

    if (day < zodiacStartDays[month - 1]) return zodiacSigns[month - 1];
    return zodiacSigns[month];
}

/**
 * Fungsi untuk menghitung jumlah hari sejak 01-01-0001
 * @param int day
 * @param int month
 * @param int year
 * @return total hari sejak 01-01-0001 sampai tanggal yang diberikan
 */
long long daysFromBeginning(int day, int month, int year) {
    int sum = 0;
    // cek apakah year kabisat
    if (isLeapYear(year)){
      sum += (year-1) * 366;
    } else {
      sum += (year-1) * 365;
    }
    for (int i = 1; i < month; i++){
      sum += getDaysInMonth(i, year);
    }
    // tambahkan day di month itu
    sum += day;
    return sum;
}

/**
 * Fungsi untuk menghitung selisih hari antara dua tanggal
 * @param int d1
 * @param int m1
 * @param int y1
 * @param int d2
 * @param int m2
 * @param int y2
 * @return total selisih hari dari tanggal ke 1 menuju tanggal ke 2
 */
long long dateDifference(int d1, int m1, int y1, int d2, int m2, int y2) {
    int i;
    int total = 0;
    if (y2 < y1) {
      return -1;
    }
    if (y2 == y1 && m2 < m1){
      return -1;
    }
    if (y2 == y1 && m2 == m1 && d2 < d1){
      return -1;
    }
    if (y2 == y1){
      if (m2 == m1){
        total = d2-d1;
      } else {
        total += getDaysInMonth(m1, y1) - d1;
        for (i = m1+1; i <= m2-1; i++){
          total += getDaysInMonth(i,y1);
        }
        total += d2;
      }
    } else {
      total += getDaysInMonth(m1, y1) - d1;
      for (i = m1+1; i <= 12; i++){
        total += getDaysInMonth(i, y1);
      }
      for (i = y1+1; i < y2; i++){
        if (isLeapYear(i)){
          total += 366;
        } else {
          total += 365;
        }
      }
      for (int i = 1; i < m2; i++){
        total += getDaysInMonth(i, y2);
      }
      total += d2;
    }
    return total;
}

/**
 * Fungsi untuk menghitung hari pasaran Jawa
 * @param int day
 * @param int month
 * @param int year
 * @return string hari pasaran jawa berdasarkan tanggal yang diberikan
 */
const char* getPasaran(int day, int month, int year) {
    const char* pasaran[] = {"Legi", "Pahing", "Pon", "Wage", "Kliwon"};
    //continue here...

}

/**
 * Gunakan strcmp(string1, string2) untuk mengecek apakah kedua string sama
 * Contoh:
 * strcmp("sabtu", "sabtu") --> 0
 * strcmp("senin", "sabtu") --> 1
 */
int main() {
    // type your code here...
    return 0;
}