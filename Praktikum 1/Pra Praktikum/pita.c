#include <stdio.h>
#include <string.h>
int main (){
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if (i == 1 || i == N){
                if (j == (N+1)/2){
                    printf("*");
                } else {
                    printf(".");
                }
            }
            else if (i == (N+1)/2){
                if (j == 1 || j == N){
                    printf("*");
                } else {
                    printf(".");
                }
            } else {
                if (j == i || j == (N+1-i)){
                    printf("*");
                } else {
                    printf(".");
                }
            }
        } printf("\n");
    }
    return 0;
}