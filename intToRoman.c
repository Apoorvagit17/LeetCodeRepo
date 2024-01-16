/*Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

 

Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 */


#include<stdio.h>
#include <stdlib.h>

char* intToRoman(int num) {
    // Arrays to store the Roman numeral symbols and their corresponding values
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    // Allocate memory for the Roman numeral string
    char* result = (char*)malloc(20 * sizeof(char));
    if (result == NULL) {
        // Handle memory allocation failure
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    result[0] = '\0'; // Initialize the result string

    // Iterate through the values and build the Roman numeral representation
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            // Append the symbol to the result string
            strcat(result, symbols[i]);
            num -= values[i];
        }
    }

    return result;
}
int main() {
    int num;

    // Input the integer
    printf("Enter an integer: ");
    scanf("%d", &num);

    if (num < 1 || num > 3999) {
        printf("Invalid input. Please enter an integer between 1 and 3999.\n");
        return 1;  // Exit with an error code
    }

    // Convert and print the Roman numeral
    char* result = intToRoman(num);
    printf("Roman numeral: %s\n", result);

    // Free the allocated memory
    free(result);

    return 0;
}