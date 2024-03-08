#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i:nums){
            m[i]++;
        }
        int ma=0,res=0;
        for(auto i:m){
            ma=max(ma,i.second);
        }
        for(auto i:m){
            if(i.second==ma){
                res+=i.second;
            }
        }
        return res;
    }
};