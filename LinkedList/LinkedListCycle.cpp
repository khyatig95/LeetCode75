/*
Problem : Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.

https://leetcode.com/problems/linked-list-cycle/

Time Complexity : O(N)
Space Complexity : O(1)
*/

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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        
        ListNode* fR = head, *sR = head;
        int count = 0;
        do {
            //If there is an end to LL, no cycle
            if (sR->next == NULL || fR->next == NULL)
                return false;
            if (fR->next->next == NULL)
                return false;

            fR = fR->next->next;
            sR = sR->next;
        } while (fR != sR);
        return true;
    }
};
