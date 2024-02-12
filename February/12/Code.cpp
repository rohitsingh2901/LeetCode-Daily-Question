
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;  // Variable to store the majority element
        int count = 0;  // Counter for the majority element
        
        // Iterate through the vector
        for(int i = 0; i < nums.size(); i++) {
            // If count is zero, set the current element as the potential majority element
            if(count == 0) {
                ele = nums[i];
            }
            
            // If the current element matches the potential majority element, increment count
            if(ele == nums[i]) {
                count++;
            } else {  // Otherwise, decrement count
                count--;
            }
        }
        
        // Return the majority element
        return ele;
    }
};
