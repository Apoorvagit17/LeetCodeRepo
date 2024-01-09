#include<stdio.h>
#include <stdlib.h>

// Function to compare two integers (used for sorting)
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int findContentChildren(int *g, int gSize, int *s, int sSize) {
    // Sort the arrays in ascending order
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);

    int i = 0;  // Pointer for greed factor array
    int j = 0;  // Pointer for cookie size array
    int count = 0;  // Count of content children

    while (i < gSize && j < sSize) {
        if (s[j] >= g[i]) {
            count++;  // Increment the count of content children
            i++;      // Move to the next child
        }
        j++;  // Move to the next cookie
    }

    return count;
}

int main() {
    // Example input
    int g[] = {1, 2, 3};
    int gSize = sizeof(g) / sizeof(g[0]);
    int s[] = {1, 1};
    int sSize = sizeof(s) / sizeof(s[0]);

    int result = findContentChildren(g, gSize, s, sSize);
    printf("Maximum number of content children: %d\n", result);

    return 0;
}