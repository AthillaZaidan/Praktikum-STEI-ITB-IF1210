#include <stdio.h>
#include "Boolean.h"

int main(){
    int N;
    scanf("%d", &N);
    int arr1[100];
    for (int i = 0; i < N; i++){
        scanf("%d", &arr1[i]);
    }
    int M;
    scanf("%d", &M);
    int arr2[100];
    for (int i = 0; i < M; i++){
        scanf("%d", &arr2[i]);
    }
    int arr3[250];
    int i = 0;
    int j = 0;
    int z = 0;
    
    while (j < N && z < M){
        if (arr1[j] <= arr2[z]){
            arr3[i] = arr1[j];
            j++;
        } else {
            arr3[i] = arr2[z];
            z++;
        }
        i++;
    }
    while (j < N){
        arr3[i] = arr1[j];
        j++;
        i++;
    }
    
    while (z < M){
        arr3[i] = arr2[z];
        z++;
        i++;
    }

    for (int k = 0; k < M+N; k++) {
        if (k == 0) {
            printf("[%d", arr3[k]);
        } else {
            printf(",%d", arr3[k]);
        }
    }
    printf("]\n");
    return 0;
}