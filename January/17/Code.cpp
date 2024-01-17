#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Step 1: Create an unordered_map to store the occurrences of each value
        unordered_map<int, int> occ;

        // Step 2: Iterate through the array and update the counts in the 'occ' map
        for(int i = 0; i < arr.size(); i++) {
            occ[arr[i]]++;
        }

        // Step 3: Create an unordered_set to store unique counts
        unordered_set<int> s;

        // Step 4: Iterate through the values in the 'occ' map
        for(auto e : occ) {
            // Check if the count is already in the set
            if(s.find(e.second) != s.end()) {
                // If it is, return false (not unique)
                return false;
            }

            // Otherwise, insert the count into the set
            s.insert(e.second);
        }

        // Step 5: If the loop completes without returning false, return true
        return true;
    }
};
