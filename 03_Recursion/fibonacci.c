#include <stdio.h>


long long fibonacci(int n) {
   
    if (n <= 0) return 0;
    if (n == 1) return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {
    int n = 10;
    printf("Fibonacci(%d) = %lld\n", n, fibonacci(n));
    return 0;
}