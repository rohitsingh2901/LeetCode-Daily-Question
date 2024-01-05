#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[2502]; // Array to store memoized results

    int lis(int s, vector<int> &a) {
        int ans = 1;
        if (dp[s] != -1) return dp[s]; // If LIS at index s is already calculated, return memoized value
        for (int i = 0; i < s; i++) {
            if (a[i] < a[s])
                ans = max(ans, lis(i, a) + 1); // Recursively calculate LIS
        }
        return dp[s] = ans; // Memoize and return the LIS for index s
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp)); // Initialize dp array with -1
        int len = 0;
        for (int i = 0; i < nums.size(); i++) {
            len = max(len, lis(i, nums)); // Compute LIS for each index and update the maximum length
        }
        return len; // Return the length of the longest increasing subsequence
    }
};
