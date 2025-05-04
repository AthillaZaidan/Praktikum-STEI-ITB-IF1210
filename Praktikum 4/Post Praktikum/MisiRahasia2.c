#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include "tester.h"

/* Tulis kode disini jika perlu */

void swapping (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    // init();
    /* Tulis kode dibawa ini */
    // TODO: baca file input.txt
    FILE *f, *fq;
    bool benar = true;
    int retval, retval2;
    int NimonID, status, value;
    f = fopen("input.txt", "r");
    int misi [1000][3];
    retval = fscanf(f, "%d %d %d", &NimonID, &status, &value);
    if (NimonID == -1 && status == 0 && value == 0) benar = false;
    int i = 0;
    while (benar){
        misi[i][0] = NimonID;
        misi[i][1] = status;
        misi[i][2] = value;

        retval = fscanf(f, "%d %d %d", &NimonID, &status, &value);
        if (NimonID == -1 && status == 0 && value == 0) {
            benar = false;
            break;
        }
        i++;
    }
    int max = i + 1;
    /*
    urutan sorting :
    1. status, sukses dlu baru gagal dengan kata lain 1 1 1 1 0 0 0 0
    2. value,
    3. id
    */
   int j;
   for (i = 0; i < max-1; i++){
    for (j = 0; j < max-1-i; j++){
        bool swap = false;
        if (misi[j][1] > misi[j+1][1]){
            swap = true;
        } else if (misi[j][1] == misi[j+1][1]){
            if (misi[j][2] > misi[j+1][2]){
                swap = true;
            } else if (misi[j][2] == misi[j+1][2]){
                if (misi[j][0] > misi[j+1][0]){
                    swap = true;
                }
            }
        }
        if (swap){
            swapping (&misi[j][0], &misi[j+1][0]);
            swapping (&misi[j][1], &misi[j+1][1]);
            swapping (&misi[j][2], &misi[j+1][2]);
        }
    }
   }
//    for (i = 0; i < max; i++){
//     printf("%d %d %d\n", misi[i][0], misi[i][1],  misi[i][2]);
//    }
   fclose (f);

   fq = fopen("query.txt", "r");
   int z;
   retval2 = fscanf(fq, "%d", &z);
   int read;
   for (i = 0; i < z; i++){
    retval2 = fscanf(fq, "%d", &read);
    printf("%d %d\n", misi[read-1][0], misi[read-1][2]);
   }
   fclose(fq);
   return 0;
}