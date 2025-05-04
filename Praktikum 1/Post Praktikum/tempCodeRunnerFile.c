#include <stdio.h>

int main (){
    int N;
    scanf("%d", &N);
    int count = 1;
    if (N % 2 == 0){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (j == N - 1){
                    printf("%d", count);
                } else {
                    printf("%d ", count);
                }
                count++;
            } printf("\n");
        }
    } else {
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (j == N-1 && i != N-1){
                    printf("%d", (count + 1));
                } else if (j == N-1){
                    printf("%d", (count));
                } else if (j == 0 && i != 0){
                    printf("%d ", (count -1));
                } else {
                    printf("%d ", count);
                } count++;
            } printf("\n");
        }
    }
}