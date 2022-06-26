/*
Problem : Given the head of a singly linked list, reverse the list, and return the reversed list.

https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* prev = nullptr, *curr = head, *nex;
        while(curr->next != nullptr) {
            nex = curr->next; //Store the next of LL as you will manipulate it
            curr->next = prev;
            prev = curr;      //Store the Reverse LL
            curr = nex;
        }
        curr->next = prev;
        return curr;
    }
};
