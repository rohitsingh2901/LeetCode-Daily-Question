
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using info = pair<long long, int>; // Define a pair type for storing end time and room number
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end()); // Sort meetings based on start times
        vector<int> count(n, 0); // Vector to store the count of meetings in each room
        vector<int> freeR(n); // Vector to represent availability of rooms
        iota(freeR.begin(), freeR.end(), 0); // Initialize freeR with room numbers
        priority_queue<int, vector<int>, greater<int>> freeRoom(freeR.begin(), freeR.end()); // Priority queue for available rooms
        priority_queue<info, vector<info>, greater<info>> used; // Priority queue for ongoing meetings

        for (auto& meet : meetings) { // Iterate through meetings
            int room;
            while (!used.empty() && used.top().first <= meet[0]) { // Check ongoing meetings ending before current meeting
                room = used.top().second; // Get the room number of the meeting that ended
                freeRoom.push(room); // Add the room back to available rooms
                used.pop(); // Remove the meeting from ongoing meetings
            }
            long long start, m_time = meet[1] - meet[0]; // Calculate meeting duration
            if (freeRoom.empty()) { // If no available rooms
                tie(start, room) = used.top(); // Get the room number with earliest ending meeting
                used.pop(); // Remove the meeting from ongoing meetings
            } else {
                room = freeRoom.top(); // Get the available room with lowest number
                start = meet[0]; // Meeting starts at its scheduled start time
                freeRoom.pop(); // Remove the room from available rooms
            }
            count[room]++; // Increment count of meetings in selected room
            used.push({start + m_time, room}); // Add current meeting to ongoing meetings
        }
        int idx = max_element(count.begin(), count.end()) - count.begin(); // Find room with maximum meetings

        return idx; // Return the index of the room with maximum meetings
    }
};
