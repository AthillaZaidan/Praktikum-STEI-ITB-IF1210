#include <stdio.h>
#include <stdlib.h>

void cetakarray(int x, int y){
    int *arr = (int*)malloc(x * sizeof(int));
    int *arrbaru = (int*)malloc(x * sizeof(int));
    int i, j, z, b;
    int k;
    int mutlak;

    for (i = 0; i < x; i++){
        scanf("%d", &arr[i]);
    } 
    // isi array baru;
    for (i = 0; i < x; i++){
        arrbaru[i] = arr[i];
    }
    for (j = 0; j < y; j++){
        mutlak = arrbaru[x-1];
        for (z = x-1; z > 0; z--){
            arrbaru[z] = arrbaru[z-1]; 
        } arrbaru[0] = mutlak;
    }
    // print array;
    for (b = 0; b < x; b++){
        if (b == x-1){
            printf("%d\n", arrbaru[b]);
        } else {
            printf("%d ", arrbaru[b]);
        }
    }
}

int main (){
    int x, y;
    scanf("%d %d", &x, &y);
    cetakarray(x,y);
    return 0;
}