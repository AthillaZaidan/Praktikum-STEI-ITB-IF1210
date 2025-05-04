#ifndef TEKATEKI_H
#define TEKATEKI_H

#include <stdio.h>

/**
 * Fungsi untuk menghitung kombinasi C(n, k) = n! / (k! * (n - k)!)
 * Note: jangan menggunakan perhitungan faktorial secara langsung, 
 * tetapi sederhanakan bentuk perhitungan kombinasi
 * @param n int
 * @param k int
 * @return Mengembalikan hasil kombinasi C(n, k) dalam bentuk long long
 */
long long kombinasi(int n, int k){
    long long a, b, sum, i, max, min;
    a = k;
    b = n-k;
    max = a;
    min = b;
    sum = 1;
    if (b > a){
        max = b;
        min = a;
    }
    for (i = n; i > max; i--){
        sum *= i;
    }
    for (i = min; i >= 1; i--){
        sum /= i;
    }
    return sum;
}
/**
 * Fungsi untuk menghitung bilangan Catalan ke-N
 * Catalan(N) = C(2N, N) / (N + 1)
 * @param n int
 * @return Mengembalikan Catalan(n)
 */
long long catalan(int n){
    return kombinasi(2*n, n)/(n+1);
}
#endif