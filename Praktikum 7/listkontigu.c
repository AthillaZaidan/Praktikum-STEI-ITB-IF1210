#ifndef LISTKONTIGU_H
#define LISTKONTIGU_H

#include <stdbool.h>
#include <stdio.h>

/* Kamus Umum */
#define CAPACITY 100    /* Kapasitas penyimpanan */
#define IDX_MIN 0       /* Indeks minimum array fisik */
#define IDX_UNDEF -1    /* Indeks tak terdefinisi */
#define MARK -9999      /* Nilai elemen tak terdefinisi/penanda slot kosong */

/* Definisi elemen dan koleksi objek */
typedef int ElType; /* type elemen List */

/* List Kontigu varian alt-1b */
typedef struct {
    ElType contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} ListKontigu;
/* Indeks fisik yang valid untuk array adalah [0..CAPACITY-1] */
/* Jika l adalah ListKontigu, cara deklarasi dan akses: */
/* Deklarasi : l : ListKontigu */
/* Akses fisik: ELMT(l, i) untuk mengakses elemen array pada indeks fisik i */
/* Definisi List:
    List kosong: semua elemen fisik bernilai MARK.
    Elemen list valid: blok kontigu elemen fisik non-MARK.
    Indeks logis: 0..listLength(l)-1.
    Indeks fisik efektif: firstIdx(l)..lastIdx(l) (inklusif).
*/

/* ********** SELEKTOR FISIK ********** */
#define ELMT(l, i) (l).contents[(i)]
/* Macro ELMT digunakan untuk mengakses elemen pada indeks FISIK i dari array. */
/* Perhatian: Indeks fisik i belum tentu sama dengan indeks logis elemen list. */
/* Gunakan fungsi getElmt/setElmt untuk akses berdasarkan indeks logis. */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong */
void CreateList(ListKontigu *l){
    for (int i = 0; i < CAPACITY; i++){
        l->contents[i] = MARK;
    }
}
/* I.S. l sembarang */
/* F.S. Terbentuk ListKontigu l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen fisik ListKontigu l dengan MARK */

/* ********** SELEKTOR  ********** */

/* *** Pencari Indeks Fisik Batas Efektif *** */
int firstIdx(ListKontigu l){
    for (int i = 0; i < CAPACITY; i++){
        if (l.contents[i] != MARK){
            return i;
        }
    }
    return IDX_UNDEF;
}
/* Prekondisi : List l boleh kosong */
/* Mengirimkan indeks fisik elemen valid pertama dalam list l, */
/* atau IDX_UNDEF jika l kosong */

int lastIdx(ListKontigu l){
    for (int i = CAPACITY-1; i >= 0; i--){
        if (l.contents[i] != MARK){
            return i;
        }
    }
    return IDX_UNDEF;
}
/* Prekondisi : List l boleh kosong */
/* Mengirimkan indeks fisik elemen valid terakhir dalam list l, */
/* atau IDX_UNDEF jika l kosong */

/* *** Banyaknya elemen *** */
int listLength(ListKontigu l){
    if (firstIdx(l) == IDX_UNDEF) return 0;
    return lastIdx(l) - firstIdx(l) + 1;
}
/* Mengirimkan banyaknya elemen efektif ListKontigu */
/* Mengirimkan nol jika List kosong */

ElType getElmt(ListKontigu l, int i){
    int first = firstIdx(l);
    return l.contents[first + i];
}
/* Prekondisi : List l tidak kosong, i adalah indeks logis yang valid (0..listLength(l)-1) */
/* Mengirimkan elemen List yang ke-i (indeks logis) */

/* *** Mengubah elemen berdasarkan indeks logis *** */
void setElmt(ListKontigu *l, int i, ElType val){
    int first = firstIdx(*l);
    l->contents[first + i] = val;
}
/* I.S. List l tidak kosong, i adalah indeks logis yang valid (0..listLength(l)-1) */
/* F.S. Elemen List yang ke-i secara logis bernilai val */

/* ********** Test Indeks yang valid ********** */
bool isIdxValid(int i){
    if (i >= IDX_MIN && i <= CAPACITY-1){
        return true;
    }
    return false;
}
/* Mengirimkan true jika i adalah indeks fisik yang valid untuk array  */
/* yaitu antara IDX_MIN dan CAPACITY-1 */

bool isIdxEff(ListKontigu l, int i){
    if (i >= firstIdx(l) && i <= lastIdx(l)){
        return true;
    }
    return false;
}
/* Mengirimkan true jika i adalah indeks fisik yang efektif (valid secara fisik */
/* dan merupakan bagian dari elemen list yang valid). */
/* yaitu i >= firstIdx(l) dan i <= lastIdx(l). */
/* Mengembalikan false jika l kosong. */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
bool isEmpty(ListKontigu l){
    if (firstIdx(l) == IDX_UNDEF) return true;
    return false;
}
/* Mengirimkan true jika List l kosong (tidak memiliki elemen efektif) */


/* *** Test List penuh *** */
bool isFull(ListKontigu l){
    if (listLength(l) == CAPACITY){
        return true;
    }
    return false;
}
/* Mengirimkan true jika List l penuh (jumlah elemen efektif == CAPACITY) */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListKontigu *l){
    CreateList(l);
    int n;
    scanf("%d", &n);
    while (!(n > 0 && n <= CAPACITY)){
        scanf("%d", &n);
    }
    for (int i = 0; i < n; i++){
        scanf("%d", &l->contents[i]);
    }
}
/* I.S. l sembarang */
/* F.S. ListKontigu l terdefinisi  */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya secara kontigu dalam list, seluruh elemen fisik lain di luar blok efektif di-set MARK.  */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */

void printList(ListKontigu l){
    int len = listLength(l);
    printf("[");
    for(int i = 0; i < len; i++){
        printf("%d",getElmt(l,i));
        if(i < len-1){
            printf(",");
        }
    }   
    printf("]");
}
/* Proses : Menuliskan isi list efektif dengan traversal. */
/* List ditulis di antara kurung siku; antara dua elemen dipisahkan dengan separator "koma". */
/* Tanpa tambahan karakter di depan, di tengah, atau di belakang. */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] (e adalah elemen pada indeks logis) */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
bool isListEqual(ListKontigu l1, ListKontigu l2){
    if (listLength(l1) != listLength(l2)) return false;
    for (int i = firstIdx(l1); i < listLength(l1); i++){
        if (l1.contents[i] != l2.contents[i]) return false;
    }
    return true;
}
/* Mengirimkan true jika l1 sama dengan l2 */
/* yaitu jika panjangnya sama dan elemen pada indeks logis yang sama juga sama */

/* ********** SEARCHING ********** */
/* *** Mencari elemen berdasarkan nilai *** */
int indexOf(ListKontigu l, ElType val){
    for (int i = firstIdx(l); i < listLength(l); i++){
        if (l.contents[i] == val) return i - firstIdx(l);
    }
    return IDX_UNDEF;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks LOGIS (0..length-1) elemen pertama yang bernilai val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */


/* ********** OPERASI LAIN ********** */
void copyList(ListKontigu lIn, ListKontigu *lOut){
    CreateList(lOut);
    for (int i = 0; i < CAPACITY; i++){
        lOut->contents[i] = lIn.contents[i];
    }
}
/* I.S. lIn terdefinisi, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (elemen efektif disalin, */
/*      dimulai dari indeks fisik 0 di lOut, sisanya MARK). */


void shiftBlock(ListKontigu *l, int startPhys, int endPhys, int delta){
        if (delta > 0){
            for (int i = endPhys; i >= startPhys; i--){
                l->contents[i+1] = l->contents[i];
                l->contents[i] = MARK;
            }
        } else {
            for (int i = startPhys; i <= endPhys; i++){
                l->contents[i-1] = l->contents[i];
                l->contents[i] = MARK;
            }
        }
}
/* I.S. List l terdefinisi, ada cukup ruang MARK di arah pergeseran */
/* F.S. Elemen fisik dari startPhys hingga endPhys digeser ke kanan (delta > 0) */
/* atau ke kiri (delta < 0), elemen yang kosong dijadikan MARK. */

/* ********** PENAMBAHAN ELEMEN ********** */
/* *** Menambahkan elemen berdasarkan nilai *** */
void insertFirst(ListKontigu *l, ElType val){
    int len = listLength(*l);
    int first = firstIdx(*l);
    if(len == 0){
        l->contents[0] = val;
    } else {
        if(first > 0){
            l->contents[first-1] = val;
        } else {
            shiftBlock(l,first,lastIdx(*l),1);
            l->contents[first] = val;
        }
    }

}
/* Menambahkan val sebagai elemen pertama List l (indeks logis 0) */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val menjadi elemen pertama l, list mungkin bergeser secara fisik. */
/* Proses:
   1. Jika list kosong, tempatkan val di indeks fisik 0.
   2. Jika tidak kosong dan ada ruang di indeks fisik firstIdx(l)-1, tempatkan val di sana.
   3. Jika tidak kosong dan tidak ada ruang di kiri (firstIdx=0) tapi ada ruang di kanan,
      geser semua elemen efektif [firstIdx..lastIdx] ke kanan satu posisi,
      lalu tempatkan val di firstIdx fisik yang lama. */

void insertLast(ListKontigu *l, ElType val){
    int len = listLength(*l);
    int first = firstIdx(*l);
    int last = lastIdx(*l);
    if(isEmpty(*l)){
        l->contents[0] = val;
    } else if(last+1 < CAPACITY){
        l->contents[last + 1] = val;
    } else {
        shiftBlock(l,first,last,-1);
        l->contents[last] = val;
    }

}
/* Menambahkan val sebagai elemen terakhir List l (indeks logis length) */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val menjadi elemen terakhir l, list mungkin bergeser secara fisik. */
/* Proses: Mirip insertFirst, tapi di ujung kanan (lastIdx).
   1. Jika list kosong, tempatkan val di indeks fisik 0.
   2. Jika tidak kosong dan ada ruang di indeks fisik lastIdx(l)+1, tempatkan val di sana.
   3. Jika tidak kosong dan tidak ada ruang di kanan  tapi ada ruang di kiri,
      geser semua elemen efektif [firstIdx..lastIdx] ke kiri satu posisi,
      lalu tempatkan val di lastIdx fisik yang lama. */

void insertAt(ListKontigu *l, ElType val, int i){
    int len = listLength(*l);
    int first = firstIdx(*l);
    int last = lastIdx(*l);
    if(isEmpty(*l) && i == 0){
        l->contents[0] = val;
    } else {
        int idx = first+i;
        if(last+1 < CAPACITY){
            shiftBlock(l,idx,last,1);
            l->contents[idx] = val;
        } else {
            shiftBlock(l, first, idx-1,-1);
            l->contents[idx-1] = val;
        }
    }

}
/* Menambahkan val sebagai elemen pada indeks logis ke-i */
/* I.S. List l tidak penuh, mungkin kosong. */
/*      Jika l tidak kosong, i adalah indeks logis yang valid untuk penambahan (0..listLength(l)). */
/* F.S. val disisipkan pada indeks logis ke-i, elemen setelahnya digeser. List mungkin bergeser secara fisik. */
/* Proses:
   1. Jika list kosong (i harus 0), sama seperti insertFirst/Last.
   2. Jika 0 < i < listLength(l):
      a. Tentukan indeks fisik target: physTarget = firstIdx(l) + i.
      b. Cek ruang: Prioritaskan menggeser ke kanan jika ada ruang setelah lastIdx.
         Geser elemen dari physTarget hingga lastIdx ke kanan satu posisi.
      c. Jika tidak ada ruang kanan, coba geser ke kiri jika ada ruang sebelum firstIdx.
         Geser elemen dari firstIdx hingga physTarget-1 ke kiri satu posisi.
         physTarget sekarang menjadi physTarget-1.
      d. Tempatkan val di ELMT(*l, physTarget). */


/* ********** PENGHAPUSAN ELEMEN ********** */
void deleteFirst(ListKontigu *l, ElType *val){
    *val = l->contents[firstIdx(*l)];
    l->contents[firstIdx(*l)] = MARK;
}
/* Menghapus elemen pertama List l (indeks logis 0) */
/* I.S. List l tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum dihapus. */
/*      Elemen pertama fisik (di firstIdx) di-set menjadi MARK. */

void deleteLast(ListKontigu *l, ElType *val){
    *val = l->contents[lastIdx(*l)];
    l->contents[lastIdx(*l)] = MARK;
}
/* Menghapus elemen terakhir list (indeks logis length-1) */
/* I.S. List l tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum dihapus. */
/*      Elemen terakhir fisik (di lastIdx) di-set menjadi MARK. */

void deleteAt(ListKontigu *l, int i, ElType *val){
    int idx = i + firstIdx(*l);
    int last = lastIdx(*l);
    *val = ELMT(*l,idx);
    shiftBlock(l,idx+1,last,-1);
    l->contents[last] = MARK;
}
/* Menghapus elemen pada indeks logis ke-i */
/* I.S. List l tidak kosong, i adalah indeks logis yang valid (0..listLength(l)-1) */
/* F.S. val adalah nilai elemen pada indeks logis i sebelum dihapus. */
/*      Elemen pada indeks logis i dihapus dari list, elemen setelahnya digeser ke kiri */
/*      secara fisik untuk menjaga kontiguitas blok. */
/* 
    Jika 0 < i < listLength(l)-1:
      a. Tentukan indeks fisik target: physTarget = firstIdx(l) + i.
      b. Simpan ELMT(l, physTarget) ke val.
      c. Geser elemen dari physTarget+1 hingga lastIdx(l) ke kiri satu posisi.
      d. Set ELMT(*l, lastIdx(l)) = MARK (posisi fisik terakhir yang lama). */


/* ********** OPERASI PENGGABUNGAN ********** */
void concat(ListKontigu l1, ListKontigu l2, ListKontigu *l3){
    CreateList(l3);
    int i = 0;
    while(i < listLength(l1) && i < CAPACITY){
        l3->contents[i] = l1.contents[i];
        i++;
    }
    int j = 0;
    while(j < listLength(l2) && i < CAPACITY){
        l3->contents[i] = l2.contents[j];
        i++;
        j++;
    }
}
/* I.S. l1 dan l2 terdefinisi, boleh kosong. l3 sembarang. */
/* F.S. l3 adalah hasil penggabungan elemen efektif l1 dan l2. */
/*      Elemen l1 disalin terlebih dahulu, diikuti elemen l2. */
/*      Hasilnya ditempatkan di l3 mulai dari indeks fisik 0. */
/*      Jika total elemen > CAPACITY, hanya elemen yang muat yang disalin. */

#endif