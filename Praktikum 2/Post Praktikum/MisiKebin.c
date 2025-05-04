#include <stdio.h>
#include <stdbool.h>

// TODO: Perbaiki prosedur agar variabel total bisa diperbarui secara langsung
void countPrime(int A, int B, int* total)
{
    int i, j;
    *total = 0;
    for (i = A; i <= B; i++){
        if (i <= 1){
            continue;
        }
        bool prime = true;
        for (j = 2; j * j <= i; j++){
            if (i % j == 0){
                prime = false;
                break;
            }
        }
        if (prime){
            (*total)++;
        }
    }
}

int main()
{
    int A, B, total;
    scanf("%d %d", &A, &B);
    countPrime(A, B, &total);

    printf("%d\n", total);

    return 0;
}