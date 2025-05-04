#include <stdio.h>


long long Total(long long a, long long b, long long c, long long d, long long e){
    return (a+b+c+d+e);
}

double Rerata(double a, double b, double c, double d, double e){
    return (a+b+c+d+e)/5;
}

int main(){
    long long a, b, c, d, e;
    scanf("%lld", &a);
    scanf("%lld", &b);
    scanf("%lld", &c);
    scanf("%lld", &d);
    scanf("%lld", &e);
    long long total = Total(a, b, c, d, e);
    double rerata = Rerata(a, b, c, d, e);
    printf("%lld\n", total);
    printf("%lf\n", rerata);
    if(rerata >= 10.0){
        printf("Pesta Nimons Sukses!\n");
    }
    else{
        printf("Pesta Nimons Gagal, kumpulkan lebih banyak pisang!\n");
    }
}