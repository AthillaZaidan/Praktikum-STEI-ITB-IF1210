#include <stdio.h>
#include "matrix.h"
#include <stdbool.h>

int main (){
    int N, M, K, X;
    Matrix MT;
    scanf("%d %d %d %d", &N, &M, &K, &X);
    readMatrix(&MT, N, M);
    int count = 0;
    for (int i = 0; i <= N-K; i++){
        for (int j = 0; j <= M-K; j++){
            int sum = 0;
            for (int a = i; a < i + K; a++){
                for (int b = j; b < j + K; b++){
                    sum += MT.mem[a][b];
                }
            }
            if (sum <= X){
                    count++;
                }
        }
    }
    printf("%d\n", count);
}