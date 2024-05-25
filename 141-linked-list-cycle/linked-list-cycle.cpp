/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        if(head == NULL || head->next == NULL)
        {
            return false;
        }

        if(head->next == head)
        {
            return true;
        }

        // Hare and tortoise algo
        ListNode* slow = head; // mai 1 kadam chalta hu
        ListNode* fast = head; // mai 2 kadam chalta hu

        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};