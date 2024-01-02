class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // Declare an unordered_map to store number frequency
        unordered_map<int, int> mp;
        int cnt = 0;

        // Count the frequency of each number and find the maximum frequency
        for (auto a : nums) {
            mp[a]++;
            cnt = max(cnt, mp[a]);
        }

        // Create a 2D vector with cnt number of rows
        vector<vector<int>> v(cnt);

        // Populate the 2D vector with numbers based on their frequency
        for (auto a : mp) {
            int num = a.first;  // Get the number
            int freq = a.second; // Get the frequency of the number

            for (int i = 0; i < freq; i++) {
                v[i].push_back(num); // Add the number to its corresponding row
            }
        }

        return v; // Return the resulting 2D vector
    }
};
