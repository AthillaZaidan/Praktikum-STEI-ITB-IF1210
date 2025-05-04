#include <stdio.h>
#include <stdlib.h>
// #include "tester.h"

/* Tulis kode disini jika perlu */

int main() {
    init();
    /* Tulis kode dibawa ini */
    // TODO: baca file input.txt
    FILE *f;
    int retval;
    int id, status, value;
    int m = 0, b = 0, n = 0; 
    f = fopen("input.txt", "r");
    retval = fscanf(f, "%d %d %d", &id, &status, &value);
    while (!(id == -1 && status == 0 && value == 0)){
        m++;
        if (status == 1){
            b++;
            n += value;
        }
        retval = fscanf(f, "%d %d %d", &id, &status, &value);
    }
    printf("Total Misi: %d\n", m);
    printf("Misi Berhasil: %d\n", b);
    printf("Total Nilai Misi: %d\n", n);
    // TODO: tulis kode untuk algoritma utama
    // TODO: close file input.txt
    fclose(f);
    return 0;
}