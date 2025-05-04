#include <stdio.h>
#include "TekaTeki.h"

long long kombinasi(int n, int k){
    long long a = k;
    long long b = n-k;
    long long maximal = a;
    long long minimal = b;
    long long i;
    long long ans = 1;
    if(b > a){
        maximal = b;
        minimal = a;
    }
    for(i = n; i > maximal; i--){
        ans *= i;
    }
    for(i = minimal; i >= 1; i--){
        ans /= i;
    }
    return ans;
}

long long catalan(int n){
    return kombinasi(2*n, n) / (n+1);
}
