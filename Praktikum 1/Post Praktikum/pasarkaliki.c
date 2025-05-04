#include <stdio.h>

// Function to calculate factorial
unsigned long factorial(int n) {
    if (n == 0) return 1;
    long long fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

// Function to calculate binomial coefficient
long long binomial_coefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    int N;
    scanf("%d", &N); // Read the number of rows
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%lld ", binomial_coefficient(i, j));
        }
        printf("\n");
    }
    
    return 0;
}