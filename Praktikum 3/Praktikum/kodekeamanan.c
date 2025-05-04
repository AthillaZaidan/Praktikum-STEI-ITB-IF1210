#include <stdio.h>

void cari(int N, int arr[], int target){
    int i, j;
    int x = -1, y = -1;
    for (i = 0; i < N-1; i++){
        for (j = i+1; j < N; j++){
            if (arr[i] + arr[j] == target){
                x = i;
                y = j;
                printf("[%d, %d]\n", x, y);
                return;
            }
        }
    }
}

int main (){
    int N, i, j, target;
    scanf("%d", &N);
    int arr[N];
    for (i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &target);
    cari(N, arr, target);
}