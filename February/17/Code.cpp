
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        // Creating a min heap to store height differences
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        // Iterating through the buildings
        for (; i + 1 < h.size(); i++) {
            int diff = h[i + 1] - h[i];
            // If there's a positive height difference
            if (diff > 0) {
                // Add the height difference to the heap
                pq.push(diff);
                // If the number of height differences exceeds the available ladders
                if (pq.size() > ladders) {
                    // Use a ladder (replace it with a brick)
                    bricks -= pq.top();
                    pq.pop(); // Remove the used ladder from the heap
                    // If bricks are not enough to replace the ladder, stop
                    if (bricks < 0)
                        break;
                }
            }
        }
        // Return the farthest building reached
        return i;
    }
};
