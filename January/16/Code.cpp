#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
    unordered_set<int> s;

public:
    RandomizedSet() {
        // Constructor: Initializes the RandomizedSet object.
    }

    bool insert(int val) {
        if (s.find(val) != s.end())
            return false; // Returns false if the item is already present.

        s.insert(val);
        return true; // Returns true as the item was inserted successfully.
    }

    bool remove(int val) {
        if (s.find(val) == s.end())
            return false; // Returns false if the item is not present.

        s.erase(val);
        return true; // Returns true as the item was removed successfully.
    }

    int getRandom() {
        int pos = rand() % s.size();
        return *next(s.begin(), pos);
        // Generates a random element from the current set of elements.
        // It's guaranteed that at least one element exists when this method is called.
        // Each element must have the same probability of being returned.
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
