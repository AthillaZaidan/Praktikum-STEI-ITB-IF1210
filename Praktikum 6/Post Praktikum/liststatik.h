/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#ifndef LISTSTATIK_H
#define LISTSTATIK_H

#include <stdio.h>
#include <stdbool.h>

/*  Kamus Umum */
#define CAPACITY 100
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define MARK -9999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int ElType;  /* type elemen List */
typedef int IdxType;
typedef struct {
   ElType contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} ListStatik;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListStatik, cara deklarasi dan akses: */
/* Deklarasi : l : ListStatik */
/* Maka cara akses: 
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi : 
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define ELMT(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l){
    for (int i = 0; i < CAPACITY; i++){
        l->contents[i] = MARK;
    }
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l){
    int i;
    int count = 0;
    for (i = 0; i < CAPACITY; i++){
        if (l.contents[i] != MARK){
            count++;
        }
    }
    return count;
}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l){
    for (int i = 0; i < CAPACITY; i++){
        if (l.contents[i] != MARK){
            return i;
        }
    }
    return IDX_UNDEF;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListStatik l){
    for (int i = CAPACITY - 1; i >= 0; i++){
        if (l.contents[i] != MARK){
            return i;
        }
    }
    return IDX_UNDEF;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
bool isIdxValid(ListStatik l, IdxType i){
    if (i >= IDX_MIN && i < CAPACITY){
        return true;
    }
    return false;
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
bool isIdxEff(ListStatik l, IdxType i){
    if (i >= IDX_MIN && i < listLength(l)){
        return true;
    }
    return false;
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
bool isEmpty(ListStatik l){
    if (listLength(l) == 0){
        return true;
    }
    return false;
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
bool isFull(ListStatik l){
    if (listLength(l) == CAPACITY){
        return true;
    }
    return false;
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l){
    int n;
    scanf("%d", &n);
    while (!(n >= IDX_MIN && n <= CAPACITY)){
        scanf("%d", &n);
    }
    if (n == 0){
        CreateListStatik(l);
        return;
    } else {
        CreateListStatik(l);
        for (int i = 0; i < n; i++){
            scanf("%d", &l->contents[i]);
        }
    }
}
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
void printList(ListStatik l){
    if (listLength(l) == 0){
        printf("[]");
        return;
    }
    for (int i = 0; i < listLength(l); i++){
        if (i == 0){
            printf("[%d,", l.contents[i]);
        } else if (i == listLength(l) -1){
            printf("%d]", l.contents[i]);
        } else {
            printf("%d,", l.contents[i]);
        }
    }
}
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, bool plus){
    ListStatik l3;
    CreateListStatik(&l3);
    if (plus){
        for (int i = 0; i < listLength(l1); i++){
            l3.contents[i] = l1.contents[i] + l2.contents[i];
        }
    } else {
        for (int i = 0; i < listLength(l1); i++){
            l3.contents[i] = l1.contents[i] - l2.contents[i];
        }
    }
    return l3;
}
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
bool isListEqual(ListStatik l1, ListStatik l2){
    if (listLength(l1) != listLength(l2)){
        return false;
    }
    for (int i = 0; i < listLength(l1); i++){
        if (l1.contents[i] != l2.contents[i]){
            return false;
        }
    }
    return true;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val){
    int pos = IDX_UNDEF;
    for (int i = 0; i < listLength(l); i++){
        if (l.contents[i] == val){
            return i;
        }
    }
    return IDX_UNDEF;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min){
    *max = l.contents[0];
    *min = l.contents[0];
    for (int i = 1; i < listLength(l); i++){
        if (l.contents[i] > *max) *max = l.contents[i];
        if (l.contents[i] < *min) *min = l.contents[i];
    }
}
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val){
    int len = listLength(*l);
    for (int i = len; i > 0; i++){
        l->contents[i] = l->contents[i-1];
    }
    l->contents[0] = val;
}
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
void insertAt(ListStatik *l, ElType val, IdxType idx){
    int len = listLength(*l);
    for (int i = len; i > idx; i++){
        l->contents[i] = l->contents[i-1];
    }
    l->contents[idx] = val;
}
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListStatik *l, ElType val){
    int len = listLength(*l);
    l->contents[len] = val;
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val){
    *val = l->contents[0];
    int len = listLength(*l);


    for (int i = 0; i < len-1; i++){
        l->contents[i] = l->contents[i+1];
    }
    l->contents[len-1] = MARK;
}
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, ElType *val, IdxType idx){
    *val = l->contents[idx];
    int len = listLength(*l);
    for (int i = idx; i < len -1; i++){
        l->contents[i] = l->contents[i+1];
    }
    l->contents[len-1] = MARK;
}
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElType *val){
    int len = listLength(*l);
    *val = l->contents[len-1];
    l->contents[len-1] = MARK;
}
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********** SORTING ********** */
void sortList(ListStatik *l, bool asc){
    if (asc){
        for (int i = 0; i < listLength(*l) -1; i++){
            for (int j = 0; j < listLength(*l) - 1 - i; j++){
                if (l->contents[j] > l->contents[j + 1]){
                    ElType temp = l->contents[j];
                    l->contents[j] = l->contents[j+1];
                    l->contents[j+1] = temp;
                }
            }
        }
    } else {
        for (int i = 0; i < listLength(*l) -1; i++){
            for (int j = 0; j < listLength(*l) - 1 - i; j++){
                if (l->contents[j] < l->contents[j + 1]){
                    ElType temp = l->contents[j];
                    l->contents[j] = l->contents[j+1];
                    l->contents[j+1] = temp;
                }
            }
        }
    }
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

#endif