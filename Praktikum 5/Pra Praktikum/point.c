#ifndef POINT_H
#define POINT_H
#include <stdio.h>
#include <math.h>
#include "boolean.h"  

/* Definisi type POINT */
typedef struct {
    float X;  /* absis (sumbu X) */
    float Y;  /* ordinat (sumbu Y) */
} POINT;

/* Macro selektor komponen */
#define Absis(P)   (P).X
#define Ordinat(P) (P).Y

/* Membentuk POINT P dengan komponen X dan Y */
void CreatePoint(POINT *P, float X, float Y){
    P->X = X;
    P->Y = Y;
}
/* Membaca nilai POINT dari stdin: masukkan X Y */
void BacaPOINT(POINT *P){
    float x, y;
    scanf("%f %f", &x, &y);
    P->X = x;
    P->Y = y;
}
/* Menulis POINT ke stdout dalam format "(X,Y)" */
void TulisPOINT(POINT P){
    printf("(%f,%f)", P.X, P.Y);
}


/* Mengambil / mengubah komponen X dan Y */
float GetX(const POINT P){
    return P.X;
}
float GetY(const POINT P){
    return P.Y;
}
void  SetX(POINT *P, float X){
    P->X = X;
}
void  SetY(POINT *P, float Y){
    P->Y = Y;
}

/* Mengecek lokasi POINT pada sumbu atau kuadran */
boolean IsOrigin(POINT P){
    if (P.X == 0 && P.Y == 0){
        return true;
    }
    return false;
}     /* true jika P = (0,0) */
boolean IsOnSbX(POINT P){
    if (P.Y == 0){
        return true;
    }
    return false;
}      /* true jika Y = 0 */
boolean IsOnSbY(POINT P){
    if (P.X == 0){
        return true;
    }
    return false;
}     /* true jika X = 0 */
int     Kuadran(POINT P){
    /*
    1 = + +
    2 = - +
    3 = - -
    4 = + -
    */
   if (P.X > 0.0 && P.Y > 0.0) return 1;
   if (P.X < 0.0 && P.Y > 0.0) return 2;
   if (P.X < 0.0 && P.Y < 0.0) return 3;
   if (P.X > 0.0 && P.Y < 0.0) return 4;
   return 0;
}      /* 1..4; prekondisi: P bukan origin dan tidak di sumbu */

/* Membandingkan dua POINT */
boolean Equals(POINT P1, POINT P2){
    if (P1.X == P2.X && P1.Y == P2.Y){
        return true;
    }
    return false;
}   /* true jika X dan Y identik */
boolean NonEquals(POINT P1, POINT P2){
    return !Equals(P1,P2);
}/* negasi Equals */

/* Menghitung jarak Euclidean antara P1 dan P2, Gunakan fungsi sqrtf dari math.h untuk menghitung akar kuadrat */
float  Distance(POINT P1, POINT P2){
    float dx = P1.X - P2.X;
    float dy = P1.Y - P2.Y;
    return sqrtf(dx*dx + dy*dy);  
}
/* Menghasilkan titik tengah P1 dan P2 */
POINT  MidPoint(POINT P1, POINT P2){
    POINT mid;
    mid.X = (P1.X + P2.X) / 2.0f;
    mid.Y = (P1.Y + P2.Y) / 2.0f;
    return mid;
}

#endif  /* POINT_H */