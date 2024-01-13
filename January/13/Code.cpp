#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        // Initialize vectors to store character counts for each string
        vector<int> m1(26, 0), m2(26, 0);
        
        // Count occurrences of characters in string s
        for (auto c : s)
            m1[c - 'a']++;
        
        // Count occurrences of characters in string t
        for (auto c : t)
            m2[c - 'a']++;
        
        // Calculate the minimum number of steps needed
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (m1[i] > m2[i])
                ans += m1[i] - m2[i]; 
        }
        
        return ans;
    }
};
