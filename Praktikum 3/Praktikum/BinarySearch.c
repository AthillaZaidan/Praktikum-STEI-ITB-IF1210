#include <stdio.h>
#include <string.h>

int BinarySearch (int arr[], int left, int right, int target){
    int i;
    int x = -1;
    if (left == right){
        if (arr[left] == target){
            x = left;
        }
        return x;
    }
    while (left <= right){
        if (arr[left] == target || arr[right] == target){
            if (arr[left] == target){
                x = left;
            } else {
                i = right-1;
                if (i >= right && arr[i] == arr[right]){
                    while (i >= left && arr[i] == arr[right]){
                        x = i;
                        i--;
                    }                    
                } else {
                    x = right;    
                }
            }
            break;
        }
        left++;
        right--;
    }
    return x;
}


int main (){
    int N, i, Q;
    scanf("%d", &N);
    int arr[N];
    for (i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &Q);
    int target[Q];
    for (i = 0; i < Q; i++){
        scanf("%d", &target[i]);
    }
    int right = N-1;
    int left = 0;
    int jawab[Q];
    for (i = 0; i < Q; i++){
        jawab[i] = BinarySearch(arr, left, right, target[i]);
    }
    // print array jawab
    for (i = 0;i < Q; i++){
        if (Q == 1){
            printf("[%d]\n", jawab[i]);
        } else {
            if (i == 0){
                printf("[%d,", jawab[i]);
            } else if (i == Q-1){
                printf(" %d]\n", jawab[i]);
            } else {
                printf(" %d,", jawab[i]);
            }
        }
    }
}