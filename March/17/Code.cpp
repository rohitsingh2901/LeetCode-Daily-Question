#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Initialize a vector to store the result
        vector<vector<int>> result;
        // Get the size of the intervals vector
        int n = intervals.size();
        // Initialize an index variable
        int index = 0;

        // Add all intervals that come before newInterval
        while (index < n && intervals[index][1] < newInterval[0]) {
            result.push_back(intervals[index]);
            index++;
        }

        // Merge overlapping intervals
        while (index < n && intervals[index][0] <= newInterval[1]) {
            // Update newInterval to merge with overlapping intervals
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index++;
        }
        // Add the merged interval to the result
        result.push_back(newInterval);

        // Add all remaining intervals
        while (index < n) {
            result.push_back(intervals[index]);
            index++;
        }

        // Return the result
        return result;
    }
};
