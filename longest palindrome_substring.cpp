class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        // Create a table to store results of subproblems
        int table[n][n];
        memset(table, 0, sizeof(table));

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++)
            table[i][i] = 1;

        int start = 0;  // Initialize the starting index of the longest palindrome
        int maxLength = 1;  // Initialize the maximum length of palindrome

        // Check for substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                table[i][i + 1] = 1;
                start = i;
                maxLength = 2;
            }
        }

        // Check for substrings of length 3 or more
        for (int k = 3; k <= n; k++) {
            for (int i = 0; i < n - k + 1; i++) {
                int j = i + k - 1;  // Ending index of substring

                // Check if the substring is palindrome
                if (table[i + 1][j - 1] && s[i] == s[j]) {
                    table[i][j] = 1;

                    // Update the starting index and maximum length if needed
                    if (k > maxLength) {
                        start = i;
                        maxLength = k;
                    }
                }
            }
        }

        // Extract the longest palindromic substring
        return s.substr(start, maxLength);
    }
    
};