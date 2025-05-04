#include <stdio.h>
#include <math.h>
#include "time.h"

int main (){
    int N;
    scanf("%d", &N);
    TIME T1, T4;
    printf("[%d]\n", 1);
    BacaTIME(&T1);
    BacaTIME(&T4);
    long t1 = TIMEToDetik(T1);
    long t4 = TIMEToDetik(T4);
    long awal = t1;
    long akhir = t4;
    if (t4 < t1){
        awal = t4;
        akhir = t1;
    }
    printf("%ld\n", akhir - awal);
    long min = awal;
    long max = akhir;
    if (N > 1){
        for (int i = 2; i <= N; i++){
            printf("[%d]\n", i);
            BacaTIME(&T1);
            BacaTIME(&T4);

            t1 = TIMEToDetik(T1);
            t4 = TIMEToDetik(T4);
            awal = t1;
            akhir = t4;
            if (t4 < t1){
                awal = t4;
                akhir = t1;
            }
            printf("%ld\n", akhir - awal);
            if (awal < min) min = awal;
            if (akhir > max) max = akhir;
        }
    }
    TulisTIME(DetikToTIME(min));
    printf("\n");
    TulisTIME(DetikToTIME(max));
    printf("\n");
    return 0;
}