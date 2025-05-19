#include <stdio.h>
#include "matrix.h"
#include <stdbool.h>

int main (){
    int N, M;
    Matrix MT;
    scanf("%d %d", &N, &M);
    readMatrix(&MT, N, M);
    int count = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            int a = 0;
            int b = 0;
            bool pelana = true;
            while (a < M && pelana){
                if (MT.mem[i][j] > MT.mem[i][a]) {
                    pelana = false;
                }
                a++;
            }
            while (b < N && pelana){
                if (MT.mem[i][j] < MT.mem[b][j]){
                    pelana = false;
                }
                b++;
            }
            if (pelana){
                printf("(%d,%d,%d)\n", i, j, MT.mem[i][j]);
                count++;
            }
        }
    }
    printf("%d\n", count);
}