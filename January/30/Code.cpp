#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
            if((tokens[i]=="+" || tokens[i]=="*" ||tokens[i]=="-" ||tokens[i]=="/") && st.size()>1){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                 if (tokens[i]=="+")
                {
                    st.push(b+a);
                }
                if (tokens[i]=="*")
                {
                    st.push(b*a);
                }
                if (tokens[i]=="/")
                {
                    st.push(b/a);
                }
                if (tokens[i]=="-")
                {
                    st.push(b-a);
                }
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
    return st.top();

    }
};