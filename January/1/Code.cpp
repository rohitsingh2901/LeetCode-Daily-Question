class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort the greed factors and cookie sizes
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0, j = 0;
        int res = 0; // Result variable to count content children
        
        // Iterate through both lists using two pointers
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                res++; // Increment the count if the cookie size satisfies the child's greed factor
                i++;   // Move to the next child
                j++;   // Move to the next cookie
            } else {
                j++;   // If the current cookie size doesn't satisfy the child, try the next cookie
            }
        }
        return res; // Return the count of content children
    }
};
