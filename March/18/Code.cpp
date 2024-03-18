#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        // Sort balloons by their end points
        sort(p.begin(), p.end(), [](vector<int>& a, vector<int>& b) {
            // Custom comparator:
            // If two balloons have the same end point, sort them by their start points.
            if (a[1] == b[1]) return a[0] < b[0];
            // Otherwise, sort them by their end points.
            return a[1] < b[1];
        });

        int ans = 0, n = p.size();
        if (n == 0) return 0; // If there are no balloons, return 0.
        ans = 1; // Initialize arrow count with 1, as at least one arrow is needed.
        int prev = p[0][1]; // Initialize prev with the end point of the first balloon.

        // Iterate through balloons
        for (int i = 1; i < n; i++) {
            // If the previous end point is greater than or equal to the current balloon's start point,
            // continue without shooting another arrow.
            if (prev >= p[i][0]) continue;
            // Otherwise, increment arrow count and update the previous end point.
            ans++;
            prev = p[i][1];
        }
        return ans; // Return the minimum number of arrows needed.
    }
};
