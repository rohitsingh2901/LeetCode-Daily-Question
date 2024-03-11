#include <bits/stdc++.h>
using namespace std;


using namespace std;

string customSortString(string order, string s) {
    // Create an unordered_map to store the frequency of characters in s
    unordered_map<char, int> m;
    
    // Populate the map with the frequency of characters in s
    for (int i = 0; i < s.length(); i++) {
        m[s[i]]++;
    }
    
    // Initialize an empty string to store the result
    string ans = "";
    
    // Iterate through the characters in order
    for (int i = 0; i < order.length(); i++) {
        // While the frequency of the character in the map is greater than 0,
        // append the character to the result string and decrement its frequency
        while (m[order[i]]-- > 0) {
            ans.push_back(order[i]);
        }
    }
    
    // Iterate through the remaining characters in the map
    for (auto e : m) {
        // While the frequency of the character is greater than 0,
        // append the character to the result string
        while (e.second-- > 0) {
            ans.push_back(e.first);
        }
    }
    
    // Return the result string
    return ans;
}
