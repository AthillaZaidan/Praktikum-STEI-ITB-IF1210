#include <stdio.h>
#include <math.h>
#include "listdin.h"

int GCD (int a, int b){
    if (b == 0){
        return a;
    }
    return GCD(b, a % b);
}


int main (){
    ListDin patapim;
    CreateListDin(&patapim, 100000);

    readList(&patapim);

    int result = 0;
    for (int i = 0; i < listLength(patapim)-1; i++){
        int diff = abs(ELMT(patapim, i+1) - ELMT(patapim, 0));
        if (diff == 0){
            result = diff;
        } else {
            result = GCD(result, diff);
        }
    }
    printf("%d\n", result);
    dealocateList(&patapim);
    return 0;
}