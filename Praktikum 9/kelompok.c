#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int sum=0;
    for (int i=1; i<=n; i++){
        for (int j=0; j<=n-i; j++){
            int max=-999;
            for (int k=j; k<j+i; k++){
                if (arr[k] > max){
                    max = arr[k];
                }
            }
            sum += max;
        }
    }

    printf("%d\n", sum);

    return 0;
}