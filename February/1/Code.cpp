#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        // Sort the input array
        sort(nums.begin(), nums.end()); 

        // Check if the size of nums is a multiple of 3
        int n = nums.size();
        if (n % 3 != 0) { 
            return {};
        }

        // Initialize the result vector to store subarrays
        vector<vector<int>> result;
        int i = 0;
        while (i < n) {
            // Check if it's possible to create a subarray of size 3 with the given condition
            if (i + 2 < n && nums[i + 2] - nums[i] <= k) { 
                result.push_back({nums[i], nums[i + 1], nums[i + 2]});
                i += 3;
            } else {
                // If not possible, return an empty array
                return {}; 
            }
        }

        // Return the constructed result
        return result;
    }
};
