#include <stdio.h>

int fattoriale(int n) {
    int result = 1;
    for(int i = n; i > 1; --i) {
        result *= i;
    }
    return result;
}

int fattoriale_ricorsivo(int n) {
    if(n == 1) {
        return 1;
    } else {
        return fattoriale_ricorsivo(n - 1) * n;
    }
}

int fibonacci(int i) {
    int prev = 1;
    int current = 1;
    for(int j = 2; j < i; ++j) {
        int new_current = prev + current;
        prev = current;
        current = new_current;
    }
    return current;
}

int fibonacci_ricorsivo(int i) {
    if(i <= 2) {
        return 1;
    } else {
        return fibonacci_ricorsivo(i - 1) + fibonacci_ricorsivo(i - 2);
    }
}

int main() {
    printf("%d\n", fibonacci_ricorsivo(30));
    printf("%d\n", fibonacci(30));
    return 0;
}