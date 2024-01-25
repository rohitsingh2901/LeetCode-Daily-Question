#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1005][1005];
    int lcs(int i,int j,string &t1, string &t2){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(t1[i]==t2[j]){
            return dp[i][j]=lcs(i-1,j-1,t1,t2)+1;
        }
        else{
            return dp[i][j]=max(lcs(i-1,j,t1,t2),lcs(i,j-1,t1,t2));
        }






    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return lcs(text1.length()-1,text2.length()-1,text1,text2);
    }
};