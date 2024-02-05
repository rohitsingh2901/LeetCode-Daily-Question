
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m; // Create an unordered_map to store character frequencies
        for (int i = 0; i < s.length(); i++)
            m[s[i]]++; // Count the frequency of each character in the string
        
        for (int i = 0; i < s.length(); i++) {
            if (m[s[i]] == 1) // If the frequency of the character is 1, it's the first unique character
                return i; // Return its index
        }

        return -1; // If no unique character is found, return -1
    }
};
