#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        // Count the frequency of each number in nums using an unordered_map
        for (auto a : nums) {
            mp[a]++;
        }

        int count = 0;
        // Iterate through the elements and their counts in the unordered_map
        for (auto a : mp) {
            int t = a.second; // Get the count (frequency) of the current number
            if (t == 1)
                return -1; // If there's only 1 occurrence of a number, return -1 as it can't be paired
            count += t / 3; // Calculate the number of groups of three elements and add to count
            if (t % 3)
                count++; // If there are remaining elements that cannot form a group of three, add one more operation
        }
        return count; // Return the total count of operations required to empty the array
    }
};
