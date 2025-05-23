#include <stdio.h>

int min (int a, int b){
    if (a < b){
        return a;
    }
    return b;
}

int max (int a, int b){
    if (a > b){
        return a;
    } return b;
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++){
        int leftmax = arr[i];
        int rightmax = arr[i];
        
        for (int j = 0; j < i; j++){
            leftmax = max(leftmax, arr[j]);
        }
        
        for (int j = i+1; j < n; j++){
            rightmax = max(rightmax, arr[j]);
        }
        
        sum += min(leftmax, rightmax) - arr[i];
    }
    printf("%d\n", sum);
}