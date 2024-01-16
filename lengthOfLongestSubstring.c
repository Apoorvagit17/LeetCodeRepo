/*Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.*/ 

#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int maxLength = 0;
    int* lastIndex = (int*)calloc(256, sizeof(int));

    for (int i = 0, j = 0; j < n; j++) {
        i = fmax(i, lastIndex[(int)s[j]]);
        maxLength = fmax(maxLength, j - i + 1);
        lastIndex[(int)s[j]] = j + 1;
    }

    free(lastIndex);

    return maxLength;
}

int main() {
    char s1[] = "abcabcbb";
    char s2[] = "bbbbb";

    printf("Example 1: %d\n", lengthOfLongestSubstring(s1));  
    printf("Example 2: %d\n", lengthOfLongestSubstring(s2)); 

    return 0;
}