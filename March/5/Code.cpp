#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        // Initialize two pointers, i at the beginning and j at the end of the string
        int i = 0;
        int j = s.length() - 1;
        
        // Loop until the pointers meet or cross each other and while characters at the corresponding indices are equal
        while (i < j && s[i] == s[j]) {
            // Store the common character in the prefix or suffix
            char c = s[i];
            
            // Move the left pointer until a different character is encountered or until it reaches the right pointer
            while (i <= j && s[i] == c)
                i++;
            
            // Move the right pointer until a different character is encountered or until it reaches the left pointer
            while (i <= j && s[j] == c)
                j--;
        }   
        
        // Return the length of the remaining substring
        return j - i + 1;
    }
};
