#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
   

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases
        ListNode* res = new ListNode();
        res->next = head;
        
        // Move the second pointer (s) n steps forward
        ListNode* s = res;
        while(n--){
            s = s->next;
        }
        
        // Move both pointers (s and f) simultaneously until the end
        ListNode* f = res;
        while(s && s->next){
            s = s->next;
            f = f->next;
        }
        
        // Remove the nth node from the end
        f->next = f->next->next;
        
        // Return the head of the updated list
        return res->next;
    }
};
