#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate the sum of integers from 1 to n
    int Nsum(int n){
        return (n*(n+1))/2;
    }

    // Function to find the pivot integer
    int pivotInteger(int n) {
        // Iterate through possible values of x from 1 to n
        for(int i = 1; i <= n; i++) {
            // Check if the sum of elements before x equals the sum of elements after x
            if(Nsum(i) == (Nsum(n) - Nsum(i - 1))) {
                return i; // If found, return the pivot integer
            }
        }
        return -1; // If no such integer exists, return -1
    }
};
