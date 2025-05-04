/* File: PasienNimons.h */
/* Deskripsi: ADT kompleks untuk data pasien Nimons yang mencakup data vital, lokasi, dan identitas */

#ifndef OPERASI_H
#define OPERASI_H

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* ADT Vital: Menyimpan data vital pasien */
typedef struct {
    int tekananDarah;        // dalam mmHg
    int detakJantung;        // dalam bpm
    float saturasiOksigen;   // dalam persen (0.0 - 100.0)
} Vital;

/* ADT Lokasi: Menyimpan koordinat pasien dalam ruangan RS */
typedef struct {
    int x;  // Kolom (misal: 0 = IGD, 1 = ICU, dst)
    int y;  // Baris (misal: 0 = lantai 1, dst)
} Lokasi;

/* ADT Pasien */
typedef struct {
    char nama[50];
    Vital v;
    Lokasi l;
} Pasien;

/* --- Konstruktor --- */
Vital MakeVital(int tekanan, int detak, float saturasi){
    Vital V;
    V.tekananDarah = tekanan;
    V.detakJantung = detak;
    V.saturasiOksigen = saturasi;
    return V;
}
Lokasi MakeLokasi(int x, int y){
    Lokasi L;
    L.x = x;
    L.y = y;
    return L;
}
Pasien MakePasien(char nama[], Vital v, Lokasi l){
    Pasien P;
    strncpy(P.nama, nama, sizeof(P.nama)-1);
    P.nama[sizeof(P.nama)-1] = '\0';
    P.v = v;
    P.l = l;
    return P;
}

/* --- Aksesor --- */
int GetTekanan(Vital v){
    return v.tekananDarah;
}
int GetDetak(Vital v){
    return v.detakJantung;
}
float GetSaturasi(Vital v){
    return v.saturasiOksigen;
}
int GetX(Lokasi l){
    return l.x;
}
int GetY(Lokasi l){
    return l.y;
}
Vital GetVital(Pasien p){
    return p.v;
}
Lokasi GetLokasi(Pasien p){
    return p.l;
}

/* --- Mutator --- */
void SetTekanan(Vital *v, int tekanan){
    v->tekananDarah = tekanan;
}
void SetDetak(Vital *v, int detak){
    v->detakJantung = detak;
}
void SetSaturasi(Vital *v, float saturasi){
    v->saturasiOksigen = saturasi;
}
void SetX(Lokasi *l, int x){
    l->x = x;
}
void SetY(Lokasi *l, int y){
    l->y = y;
}
void SetVital(Pasien *p, Vital v){
    p->v = v;
}
void SetLokasi(Pasien *p, Lokasi l){
    p->l = l;
}

/* --- Operasi Vital --- */
bool IsSehat(Vital v){
    if ((v.tekananDarah >= 90 && v.tekananDarah <= 140) && (v.detakJantung >= 60 && v.detakJantung <= 100) && (v.saturasiOksigen >= 95.0f)){
        return true;
    }
    return false;
}
/* True jika:
   90 <= tekanan darah <= 140
   60 <= detak jantung <= 100
   saturasi >= 95.0 */

void ResetVital(Vital *v){
    v->tekananDarah = 120;
    v->detakJantung = 80;
    v->saturasiOksigen = 98.0;
}
/* Mengatur kembali semua nilai vital ke default (120/80/98.0) */

int CompareVital(Vital a, Vital b){
    float suma = a.detakJantung + a.saturasiOksigen + a.tekananDarah;
    float sumb = b.detakJantung + b.saturasiOksigen + b.tekananDarah;
    if (suma < sumb){
        return -1;
    } else if (fabs(suma - sumb) < 1e-6){
        return 0;
    } else {
        return 1;
    }
}
/* Mengembalikan:
   -1 jika a < b (tekanan + detak + saturasi total)
    0 jika sama
    1 jika a > b
*/

/* --- Operasi Lokasi --- */
void PindahPasien(Lokasi *l, int dx, int dy){
    l->x += dx;
    l->y += dy;
}
/* Memindahkan pasien ke koordinat baru berdasarkan delta */

/* --- Print --- */
void PrintVital(Vital v){
    printf("Tekanan: %d mmHg, Detak: %d bpm, Saturasi: %.2f%%\n", v.tekananDarah, v.detakJantung, v.saturasiOksigen);
}
/* Format: "Tekanan: xxx mmHg, Detak: xxx bpm, Saturasi: xx.xx%" */

void PrintLokasi(Lokasi l){
    printf("Lokasi: (%d, %d)\n", l.x, l.y);
}
/* Format: "Lokasi: (x, y)" */

void PrintPasien(Pasien p){
    printf("Nama: %s\n", p.nama);
    PrintVital (p.v);
    PrintLokasi(p.l);
}
/* Menampilkan semua info pasien:
   Nama
   Vital
   Lokasi
*/

#endif