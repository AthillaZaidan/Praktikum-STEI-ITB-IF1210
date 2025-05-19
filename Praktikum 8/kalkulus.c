#include "Boolean.h"
#include "matrix.h"

Matrix dilate(Matrix v, int scale){
    for (int i = 0; i < v.rowEff; i++){
        for (int j = 0; j < v.colEff; j++){
            v.mem[i][j] *= scale;
        }
    }
}
/* Setiap titik (x, y) menjadi (x*scale, y*scale) */

Matrix translate(Matrix v, int dx, int dy){
    for (int i = 0; i < v.rowEff; i++){
        for (int j = 0; j < v.colEff; j++){
            if (j==0){
                v.mem[i][j] += dx;
            } else {
                v.mem[i][j] += dy;
            }
        }
    }
}
/* Setiap titik (x, y) menjadi (x+dx, y+dy) */

Matrix reflect(Matrix v, char axis){
    for (int i = 0; i < v.rowEff; i++){
        for (int j = 0; j < v.colEff; j++){
            if (axis == 'x'){
                if (j==1){
                    v.mem[i][j] *= -1;
                }
            } else {
                if (j==0){
                    v.mem[i][j] *= -1;
                }
            }
        }
    }
}
/* 'x' → y = -y, 'y' → x = -x */

Matrix rotate(Matrix v, int degree){
    for (int i = 0; i < v.rowEff; i++){
        for (int j = 0; j < v.colEff; j++){
            if (degree == 0){
                if (j == 0){
                    v.mem[i][j] = v.mem[i][j] * 1;
                } else {
                    v.mem[i][j] = -1 * v.mem[i][j-1] * 0 + v.mem[i][j] * 1;
                }
            } else if (degree == 90){
                if (j == 0){
                    v.mem[i][j] = v.mem[i][j] * 0 + v.mem[i][j + 1] * 1;
                } else {
                    v.mem[i][j] = -1 * v.mem[i][j-1];
                }
            } else if (degree == 180){
                if (j == 0){
                    v.mem[i][j] = v.mem[i][j] * -1;
                } else {
                    v.mem[i][j] = -1 * v.mem[i][j-1] * 0 + v.mem[i][j] * -1;
                }
            } else if (degree == 270){
                if (j == 0){
                    v.mem[i][j] = v.mem[i][j+1] * -1;
                } else {
                    v.mem[i][j] = -1 * v.mem[i][j-1] * -1;
                }
            }
        }
    }
}
/* Memutar setiap titik (x, y) sebesar degree derajat searah jarum jam dari (0,0) */
/* Gunakan rumus rotasi:
   x' = x * cosθ + y * sinθ
   y' = -x * sinθ + y * cosθ
   degree hanya 0, 90, 180, 270 (bisa pakai konstanta tanpa trigonometri float) */
/* cos0 = 1, sin0 = 0*/
/* cos90 = 0, sin90 = 1*/
/* cos180 = -1, sin180 = 0*/
/* cos270 = 0, sin270 = -1*/
/* DEGREE SUDAH PASTI 4 JENIS, HARDCODE SAJA, TIDAK PERLU PAKE <math.h> */
