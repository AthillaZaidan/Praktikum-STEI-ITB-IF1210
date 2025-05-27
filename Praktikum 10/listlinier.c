#include "listlinier.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType val) {
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    l = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
    return FIRST(l) == NULL;
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx) {
    Address p = FIRST(l);
    int count = 0;
    while (count < idx) {
        p = NEXT(p);
        count++;
    }
    return INFO(p);
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val) {
    Address p = FIRST(*l);
    int count = 0;
    while (count < idx) {
        p = NEXT(p);
        count++;
    }
    INFO(p) = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val) {
    Address p = FIRST(l);
    int idx = 0;
    while (p != NULL) {
        if (INFO(p) == val) {
            return idx;
        }
        p = NEXT(p);
        idx++;
    }
    return IDX_UNDEF;
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
    Address p = newNode(val);
    if (p != NULL) {
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val) {
    Address p = newNode(val);
    if (p != NULL) {
        if (isEmpty(*l)) {
            FIRST(*l) = p;
        } else {
            Address last = FIRST(*l);
            while (NEXT(last) != NULL) {
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx) {
    if (idx == 0) {
        insertFirst(l, val);
    } else {
        Address p = newNode(val);
        if (p != NULL) {
            Address current = FIRST(*l);
            int count = 0;
            while (count < idx - 1) {
                current = NEXT(current);
                count++;
            }
            NEXT(p) = NEXT(current);
            NEXT(current) = p;
        }
    }
}

/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val) {
    Address p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val) {
    if (NEXT(FIRST(*l)) == NULL) {
        deleteFirst(l, val);
    } else {
        Address current = FIRST(*l);
        Address prev = NULL;
        while (NEXT(current) != NULL) {
            prev = current;
            current = NEXT(current);
        }
        *val = INFO(current);
        NEXT(prev) = NULL;
        free(current);
    }
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val) {
    if (idx == 0) {
        deleteFirst(l, val);
    } else {
        Address current = FIRST(*l);
        Address prev = NULL;
        int count = 0;
        while (count < idx) {
            prev = current;
            current = NEXT(current);
            count++;
        }
        *val = INFO(current);
        NEXT(prev) = NEXT(current);
        free(current);
    }
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
    printf("[");
    if (!isEmpty(l)) {
        Address p = FIRST(l);
        while (p != NULL) {
            printf("%d", INFO(p));
            p = NEXT(p);
            if (p != NULL) {
                printf(",");
            }
        }
    }
    printf("]");
}
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l) {
    int count = 0;
    Address p = FIRST(l);
    while (p != NULL) {
        count++;
        p = NEXT(p);
    }
    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
    List l3;
    CreateList(&l3);

    if (isEmpty(l1)) {
        l3 = l2;
    } else {
        l3 = l1;
        Address current = FIRST(l3);
        while (NEXT(current) != NULL) {
            current = NEXT(current);
        }
        NEXT(current) = l2;
    }
    CreateList(&l1);
    CreateList(&l2);
    return l3;
}
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */