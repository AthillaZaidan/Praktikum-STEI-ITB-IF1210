#include <stdio.h>
#include <string.h>

int main (){
    char string[10000];
    scanf("%s", string);
    int len = strlen(string);
    int i = 0;
    int j = len-1;
    while (j>-1 && string[i] == string[j]){
        j-=1;
        i+=1;
    }
    if (j == -1){
        printf("1\n");
    } else {
        printf("0\n");
    }
    return 0;
}