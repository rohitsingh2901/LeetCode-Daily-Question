#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int>& arr, int k, vector<int>& dp, int i) {
        int n = arr.size();
        // Base case: if i reaches the end of the array, return 0
        if (i == arr.size())
            return 0;
        
        // If dp[i] is already computed, return it
        if (dp[i] != -1)
            return dp[i];
        
        int ans = INT_MIN; // Initialize ans with the minimum possible integer value
        int maxans = INT_MIN; // Initialize maxans with the minimum possible integer value
        int len = 0; // Initialize length of current partition to 0

        // Iterate through the next k elements or until the end of the array
        for (int j = i; j < min(i + k, n); j++) {
            len++; // Increment length of current partition
            ans = max(ans, arr[j]); // Update ans with the maximum value in the current partition
            // Calculate the sum of current partition and recursively call solve for the next partition
            int sum = len * ans + solve(arr, k, dp, j + 1);
            maxans = max(maxans, sum); // Update maxans with the maximum sum obtained so far
        }
        // Store the maximum sum for the current index in dp array and return it
        return dp[i] = maxans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // Initialize dp array with -1 (indicating that the value is not computed yet)
        vector<int> dp(arr.size() + 1, -1);
        // Call solve function to compute maximum sum after partitioning
        return solve(arr, k, dp, 0);
    }
};
