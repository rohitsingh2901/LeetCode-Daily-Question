#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(auto e: nums) sum+=e; // Calculating the sum of all elements in the array
        return (n*(n+1))/2 - sum; // Computing the missing number
    }
};
