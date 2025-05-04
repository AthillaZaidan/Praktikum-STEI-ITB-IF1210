#include <stdio.h>

/**
 * Fungsi untuk mengecek apakah tahun kabisat
 * Untuk tahun kelipatan 100, tahun kabisat harus habis dibagi 400
 * Untuk tahun selain kelipatan 100, tahun kabisat harus habis dibagi 4
 * @param year Tahun
 * @return Mengembalikan 1 jika tahun kabisat, 0 jika tidak
 */
int isLeapYear(int year)
{
  if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)){
    return 1;
  } else {
    return 0;
  }
}

/**
 * Fungsi untuk mendapatkan jumlah hari dalam suatu bulan
 * @param month Bulan (dalam rentang 1-12)
 * @param year Tahun
 * @return Mengembalikan jumlah hari dalam bulan tersebut
 */
int getDaysInMonth(int month, int year)
{
  if (month == 2){
    if (isLeapYear(year)) {
      return 29;
    } else {
      return 28;
    }
  } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
    return 31;
  } else {
    return 30;
  }
}

/**
 * Mengembalikan apakah tanggal valid
 * Tanggal yang valid mengikuti aturan berikut:
 * - 1 <= day <= jumlah hari dalam bulan
 * - 1 <= month <= 12
 * - year >= 1
 * @param day The day
 * @param month The month
 * @param year The year
 * @return mengembalikan 1 jika tanggal valid, 0 jika tidak
 */
int isValidDate(int day, int month, int year)
{
  int hari = getDaysInMonth(month, year);
  if ((day >= 1 && day <= hari) && (month >= 1 && month <= 12) && (year >= 1)){
    return 1;
  } else {
    return 0;
  }
}

/**
 * Fungsi untuk menghitung jumlah hari sejak awal, yaitu day = 1, month = 1, year = 1
 * @param day Hari
 * @param month Bulan
 * @param year Tahun
 * @return Mengembalikan jumlah hari sejak awal
 */
int daysFromBeginning(int day, int month, int year)
{
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
 * Fungsi untuk menghitung perbedaan hari dari dua tanggal yang valid (tanggal 2 - tanggal 1)
 * Note: input tanggal sudah valid
 * @param d1 Hari dari tanggal pertama
 * @param m1 Bulan dari tanggal pertama
 * @param y1 Tahun dari tanggal pertama
 * @param d2 Hari dari tanggal kedua
 * @param m2 Bulan dari tanggal kedua
 * @param y2 Tahun dari tanggal kedua
 * @return Mengembalikan perbedaan hari dari tanggal 2 - tanggal 1
 */
int dateDifference(int d1, int m1, int y1, int d2, int m2, int y2)
{
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
 * Program utama:
 * - Menerima input d1,m1,y1
 * - Validasi tanggal pertama sampai input valid
 * - Menerima input d2,m2,y2
 * - Validasi tanggal kedua sampai input valid dan tanggal kedua lebih besar atau sama dengan dari tanggal pertama
 * - Mengeluarkan output selisih hari dari tanggal kedua - tanggal pertama
 */
int main()
{
  int d1, m1, y1, d2, m2, y2;
  scanf("%d %d %d", &d1, &m1, &y1);
  while (!isValidDate(d1,m1,y1)){
    printf("Tanggal tidak valid\n");
    scanf("%d %d %d", &d1, &m1, &y1);
  }
  scanf("%d %d %d", &d2, &m2, &y2);
  int selisih = dateDifference(d1, m1, y1, d2, m2, y2);
  while (!isValidDate(d2,m2,y2) || selisih < 0){
    if (!isValidDate(d2, m2, y2)){
      printf("Tanggal tidak valid\n");
    } else if (isValidDate(d2, m2, y2) && selisih < 0){
      printf("Tanggal kedua lebih dulu\n");
    }
    scanf("%d %d %d", &d2, &m2, &y2);
    selisih = dateDifference(d1, m1, y1, d2, m2, y2);
  }
  printf("%d\n", selisih);
}