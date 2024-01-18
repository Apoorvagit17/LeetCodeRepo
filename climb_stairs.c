#include <stdio.h>

int climbStairs(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }

    int ways[n + 1];
    ways[1] = 1;
    ways[2] = 2;

    for (int i = 3; i <= n; i++) {
        ways[i] = ways[i - 1] + ways[i - 2];
    }

    return ways[n];
}

int main() {
    int n = 2;
    int result = climbStairs(n);
    printf("The number of distinct ways to climb %d steps is: %d\n", n, result);

    return 0;
}