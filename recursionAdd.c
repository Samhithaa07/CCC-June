#include <stdio.h>

int recursionAdd(int n) {
    if (n < 2){
        return 0;
    }

    if (n % 2 != 0){
        return recursionAdd(n - 1);
    }
    
    return n + recursionAdd(n - 2);  // only even numbers
}


int main() {
    int sum = recursionAdd(100);
    printf("%d", &sum);
    return 0;
}
