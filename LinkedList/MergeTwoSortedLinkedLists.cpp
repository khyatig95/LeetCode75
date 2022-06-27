/*
Problem : You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

https://leetcode.com/problems/merge-two-sorted-lists/

Time Complexity : O(N+M)
Space Complexity : O(N+M)
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        
        ListNode* head, *itr;
        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
        
        itr = head;
        while(list1 != NULL && list2 != NULL) {
            if (list2->val <= list1->val) {
                itr->next = list2;
                list2 = list2->next;
            } else {
                itr->next = list1;
                list1 = list1->next;
            }
            itr = itr->next;
        }        
        if (list2 != NULL) //We exited the while loop due to list1 end
            itr->next = list2;
        else 
            itr->next = list1;
        return head;
            
    }
};
