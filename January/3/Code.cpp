#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> c(bank.size()); // Vector to store counts of security devices in each row

        // Calculate counts of security devices in each row
        for(int i = 0; i < bank.size(); i++) {
            int ct = 0;
            
            // Iterate through each cell in the current row
            for(int j = 0; j < bank[0].size(); j++) {
                if(bank[i][j] == '1') {
                    ct++; // Increment the count for each security device in the row
                }
            }
            
            if(ct) {
                c.push_back(ct); // Store the count of security devices for the current row
            }
        }
        
        int ans = 0;
        
        // Calculate the total number of laser beams based on counts per row
        for(int i = 1; i < c.size(); i++) {
            ans += c[i] * c[i - 1]; // Accumulate the number of beams based on adjacent rows' counts
        }
        
        return ans; // Return the total number of laser beams
    }
};
