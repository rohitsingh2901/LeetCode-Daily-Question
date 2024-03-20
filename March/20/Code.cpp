
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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        int x = b - a;
        ListNode *temp = list1;
        while (a > 1 && temp && temp->next)
        {
            temp = temp->next;
            a--;
        }
        ListNode *end = temp->next ? temp->next : NULL;
        temp->next = list2;
        while (x-- && end && end->next)
        {
            end = end->next;
        }
        while (temp && temp->next)
        {
            temp = temp->next;
        }
        temp->next = end->next;
        return list1;
    }
};