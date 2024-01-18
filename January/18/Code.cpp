#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Initialize an array to store computed results, considering the constraint 1 <= n <= 45
    int dp[46];

    int climbStairs(int n) {
        // Base case: if n is 1, 2, or 3, the result is n
        if (n <= 3) return dp[n] = n;

        // If the result for n is already computed, return it
        if (dp[n] != 0) return dp[n];

        // Recursive calls to climbStairs for n-1 and n-2, with memoization
        return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};
