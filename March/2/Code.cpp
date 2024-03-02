#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int l = 0, r=n-1;
        for(int i=n-1;i>=0;i--){
            int val;
            if(abs(nums[l])<abs(nums[r])){
                val = nums[r];
                r--;
            }
            else{
                val = nums[l];
                l++;
            }
            ans[i] = val*val;
        }
        return ans;        
    }
};