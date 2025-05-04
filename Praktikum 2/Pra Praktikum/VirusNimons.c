#include <stdio.h>

int main (){
    int N, T, X;
    scanf("%d %d %d", &N, &T, &X);
    unsigned long sum = N;
    for (int i = 0; i < T; i++){
        sum = sum * X + N;
    }
    printf("Terdapat %lld Virus Nimons Gila pada jam ke-%d\n", sum, T);
}