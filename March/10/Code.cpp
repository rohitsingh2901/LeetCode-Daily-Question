#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Create a hash map to store elements from nums1
        unordered_map<int, int> m;
        
        // Iterate through nums1 and mark each element as present in the map
        for (auto x : nums1) {
            m[x] = 1;
        }
        
        // Create a vector to store the intersection elements
        vector<int> ans;
        
        // Iterate through nums2
        for (auto x : nums2) {
            // Check if the element exists in the map and its count is 1
            if (m.find(x) != m.end() && m[x] == 1) {
                ans.push_back(x); // Add the element to the intersection vector
                m[x]--; // Decrement the count to avoid duplicates
            }
        }
        
        return ans; // Return the intersection vector
    }
};
