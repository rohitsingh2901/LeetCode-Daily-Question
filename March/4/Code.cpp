#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1;
        int maxScore = 0,score=0;
        while(i<=j){
            if(tokens[i]<=power){
                power-=tokens[i++];
                score++;
                maxScore=max(maxScore,score);
            }
            else if(score>0){
                score--;
                power+=tokens[j--];
            }
            else{
                break;
            }
        }
        return maxScore;
    }
};