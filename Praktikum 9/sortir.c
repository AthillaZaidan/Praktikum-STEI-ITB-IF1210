#include "queue.h"
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-1-i; j++){
            if (arr[j] < arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    Queue q1;
    CreateQueue(&q1);
    for (int i=0; i<n; i++){
        enqueue(&q1, arr[i]);
    }

    displayQueue(q1);

    return 0;
}