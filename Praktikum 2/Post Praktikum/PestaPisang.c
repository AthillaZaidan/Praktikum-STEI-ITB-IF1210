#include <stdio.h>

int total (int a, int b, int c, int d, int e){
    return a+b+c+d+e;
}

double rerata (int a, int b, int c, int d, int e){
    return (a+b+c+d+e)/5.0;
}

void cetak (double rerata){
    if (rerata >= 10){
        printf("Pesta Nimons Sukses!\n");
    } else {
        printf("Pesta Nimons Gagal, kumpulkan lebih banyak pisang!\n");
    }
}

int main (){
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    int x;
    double y;
    x = total (a, b, c, d, e);
    y = rerata (a, b, c, d, e);
    printf("%d\n", x);
    printf("%f\n", y);
    cetak(y);
}