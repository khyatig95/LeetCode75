/*
Problem : Given the head of a linked list, remove the nth node from the end of the list and return its head.

https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Time Complexity : O(N)
Space Complexity : O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || n < 0)
            return head;
        
        ListNode* fast = head, *slow = NULL;
        int count = 1;
        
        while(fast->next != NULL) {
            fast = fast->next;
            if (count >= n) { //Find element n+1 from last so we can just alter its next Node.
                if (slow != NULL)
                    slow = slow->next;
                else
                    slow = head;
            }
            count++;

        }
        if (slow == NULL) { //n+1 from last is head
            return head->next;
        }
        if (slow->next->next != NULL)
            slow->next = slow->next->next;
        else
            slow->next = NULL;
        return head;
    }
};
