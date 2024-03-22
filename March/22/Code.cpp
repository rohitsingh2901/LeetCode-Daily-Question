#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseLL(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;
        while (curr)
        {
            ListNode *nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return 1;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *start = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseLL(slow->next);
        slow = slow->next;
        while (slow)
        {
            if (slow->val != start->val)
            {
                return 0;
            }
            slow = slow->next;
            start = start->next;
        }
        return 1;
    }
};