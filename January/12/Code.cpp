#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to determine if string halves are alike
    bool halvesAreAlike(string s) {
        // Set to store vowels
        unordered_set<char> vowels = {'a','A','e','E','i','I','o','O','u','U'};
        
        // Counters for vowels in the first and second halves
        int f = 0, l = 0;
        
        // Iterate through the string
        for(int i = 0; i < s.length(); i++) {
            // Check if the character is a vowel and in the first half
            if(vowels.find(s[i]) != vowels.end() && i < s.length() / 2) {
                f++;
            }
            // Check if the character is a vowel and in the second half
            else if(vowels.find(s[i]) != vowels.end() && i >= s.length() / 2) {
                l++;
            }
        }
        
        // Return true if the counts of vowels in both halves are equal
        return l == f;
    }
};
