#include <stdio.h>
#include <string.h>

int main (){
    char s[1001];
    int i;
    scanf("%s", s);
    int len = strlen(s);
    if (len % 2 != 0){
        // buat array counter
        int arr[26] = {0};
        
        for (i = 0; i < len; i++){
            arr[s[i] - 'a'] += 1;
        }

        int count = 0;
        for (i = 0; i < 26; i++){
            if (arr[i] % 2 != 0 && arr[i] != 0){
                count++;
            }
        }
        if (count > 1){
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    } else {
                // buat array counter
        int arr[26] = {0};
        
        for (i = 0; i < len; i++){
            arr[s[i] - 'a'] += 1;
        }

        int count = 0;
        for (i = 0; i < 26; i++){
            if (arr[i] % 2 != 0 && arr[i] != 0){
                count++;
            }
        }
        if (count > 0){
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
}