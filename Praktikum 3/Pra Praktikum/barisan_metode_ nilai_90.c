#include <stdio.h>

int euclid (int a, int b){
    if (b == 0){
        return a;
    }
    return euclid(b,a % b);
}

int kpk (int a, int b){
    int penyebut = euclid(a,b);
    return a*b/penyebut;
}

void bubblesort (int arr[], int N){
    int i, j, temp;
    for (i = 0; i < N-1; i++){
        for (j = 0; j < N-1-i; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main (){
    long long N, i, a, b;
    scanf("%lld", &N);
    int arr[N];
    for (i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    bubblesort(arr, N);
    if (N == 1){
        printf("%lld\n", arr[0] * arr[0]);
    } else if (N == 0){
        printf("0\n");
    } else if (N == 2){
        long long max1;
        a = euclid(arr[0], arr[1]);
        b = kpk (arr[0], arr[1]);
        max1 = a * b;
        long long max2 = arr[1] * arr[1];
        if (max1 > max2){
            printf("%lld\n", max1);
        } else {
            printf("%lld\n", max2);
        }
    } else {
        // cek tanpa invis
        long long max1, max2;
        long long kpkawal, fpbawal;
        fpbawal = euclid(arr[0], arr[1]);
        kpkawal = kpk(arr[0], arr[1]);
        for (i = 2; i < N; i++){
            fpbawal = euclid(fpbawal, arr[i]);
            kpkawal = kpk(kpkawal, arr[i]);
        }
        max1 = fpbawal * kpkawal;
        
        // cek dengan invis
        fpbawal = euclid(arr[1], arr[2]);
        kpkawal = kpk(arr[1], arr[2]);
        for (i = 3; i < N; i++){
            fpbawal = euclid(fpbawal, arr[i]);
            kpkawal = kpk(kpkawal, arr[i]);
        }
        max2 = fpbawal * kpkawal;
        
        if (max1 > max2){
            printf ("%lld\n", max1);
        } else {
            printf("%lld\n", max2);
        }
    }
    return 0;
}