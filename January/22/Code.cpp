#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int missing, repeat;

        // Mark visited elements by negating their values
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] < 0)
                repeat = abs(nums[i]);
            else
                nums[abs(nums[i]) - 1] *= -1;
        }

        // Find the missing element
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                missing = i + 1;
        }

        return {repeat, missing};
    }
};
