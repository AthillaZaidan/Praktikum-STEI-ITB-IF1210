#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double konversi(double x, char a, char b) {
    double hasil = 0.0;

    if (a == 'C' && b == 'F') {
        hasil = (x * 9.0 / 5.0) + 32.0;
    } else if (a == 'C' && b == 'K') {
        hasil = x + 273.15;
    } else if (a == 'F' && b == 'C') {
        hasil = (x - 32.0) * 5.0 / 9.0;
    } else if (a == 'F' && b == 'K') {
        hasil = (x - 32.0) * 5.0 / 9.0 + 273.15;
    } else if (a == 'K' && b == 'C') {
        hasil = x - 273.15;
    } else if (a == 'K' && b == 'F') {
        hasil = (x - 273.15) * 9.0 / 5.0 + 32.0;
    }

    return floor(hasil * 100) / 100;
}

int main() {
    int N;
    scanf("%d", &N);
    double x[N];
    char a[N], b[N];
    for (int i = 0; i < N; i++) {
        scanf("%lf %c %c", &x[i], &a[i], &b[i]);
    }
    for (int i = 0; i < N; i++){
        printf("%.2lf\n", floor(konversi(x[i], a[i], b[i])));
    }

    return 0;
}