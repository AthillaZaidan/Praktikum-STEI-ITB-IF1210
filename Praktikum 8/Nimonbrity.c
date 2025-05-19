#include <stdio.h>
#include "matrix.h"
#include <stdbool.h>

int main (){
    int N;
    scanf("%d", &N);
    Matrix M;
    readMatrix(&M, N, N);
    int dikenal[N];
    int kenal[N];
    for (int i = 0; i < N; i++){
        dikenal[i] = 0;
        kenal[i] = 0;
    }

    for (int i = 0; i < M.rowEff; i++){
        for (int j = 0; j < M.colEff; j++){
            if (i != j){
                if (M.mem[i][j] == 1){
                    dikenal[j]++;
                    kenal[i]++;
                }
            }
        }
    }
    bool ketemu = false;
    for (int i = 0; i < N; i++){
        if (dikenal[i] == N-1 && kenal[i] == 0){
            printf("%d\n", i);
            ketemu = true;
            return 0;
        }
    }
    if (!ketemu){
        printf("-1\n");
        return 0;
    }
}