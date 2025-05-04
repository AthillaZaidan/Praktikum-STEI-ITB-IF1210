#include <stdio.h>
#include <math.h>

int main (){
    int N;
    scanf("%d", &N);
    int kiri = (N+1)/2;
    int kanan = (N+1)/2;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if (j == kanan || j == kiri){
                printf("*");
            } else {
                printf(".");
            }
        }
        kiri -= 1;
        kanan += 1;
        if (kiri == 1 && kanan == N){
            int temp;
            temp = kiri;
            kiri = kanan;
            kanan = temp; 
        }
        printf("\n");
    }

    return 0;
}