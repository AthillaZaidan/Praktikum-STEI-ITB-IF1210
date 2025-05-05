#include <stdio.h>


int main (){
    int N;
    scanf("%d", &N);
    int Kebin[N];
    int Stewart[N];
    int Pop [N];
    int Luiy[N];
    int Toto[N];
    for (int i = 0; i < N; i++){
        scanf("%d %d %d %d %d", &Kebin[i], &Stewart[i], &Pop[i], &Luiy[i], &Toto[i]);
    }
    float sum1 = 0;
    float sum2 = 0;
    float sum3 = 0;
    float sum4 = 0;
    float sum5 = 0;
    for (int i = 1; i < N; i++){
        sum1 += Kebin[i]-Kebin[i-1];
        sum2 += Stewart[i] - Stewart[i-1];
        sum3 += Pop[i] - Pop[i-1];
        sum4 += Luiy[i] - Luiy[i-1];
        sum5 += Toto[i] - Toto[i-1];
    }

    float arr[5];
    arr[0] = sum1 /= N;
    arr[1] = sum2 /= N;
    arr[2] = sum3 /= N;
    arr[3] = sum4 /= N;
    arr[4] = sum5 /= N;
    
    float min = arr[0];
    int pos = 0;
    for (int i = 1; i < 5; i++){
        if (arr[i] < min){
            min = arr[i];
            pos = i;
        }
    }
    if (pos == 0){
        printf("Kebin\n");
    } else if (pos == 1){
        printf("Stewart\n");
    } else if (pos == 2){
        printf("Pop\n");
    } else if (pos == 3){
        printf("Luiy\n");
    } else if (pos == 4){
        printf("Toto\n");
    }
}