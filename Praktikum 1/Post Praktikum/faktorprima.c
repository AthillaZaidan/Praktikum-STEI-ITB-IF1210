#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int isprime(int N) {
    for (int i = 2; i < N; i++) {
        if (N % i == 0) {
            return 0;
        }
    }

    return 1;
}
int main (){
    int N;
    scanf("%d", &N);
    int faktor;
    // cari faktor prima terkecil
    for (int i = 2; i <= N; i++){
        if (i > 2){
            if (isprime(i)){
                faktor = i;
                break;
            }
        } else if (N == 1 && i == 1){
            faktor = i;
        } 
        else {
            if (N % i == 0){
                faktor = i;
                break;
            }
        }
    }
    // cari pangkatnya
    bool masih = true;
    int pangkat = 1;
    int x =pow (faktor, pangkat);
    while (masih){
        if (x >= N || N % x != 0){
            masih = false;
        } else {
            pangkat+=1;
            x = pow(faktor, pangkat);
        }
    }
    pangkat-=1;
    x = pow (faktor, pangkat);
    int hasilbagi = N / x;
    printf("%d^%d * %d\n", faktor, pangkat, hasilbagi);
}