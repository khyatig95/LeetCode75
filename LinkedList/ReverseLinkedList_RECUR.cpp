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
        ListNode* revHead = nullptr;
        return(Reverse(revHead, head));
    }
    
    ListNode* Reverse(ListNode* revHead, ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            if (revHead != nullptr) 
                head->next = revHead;
            return head;
        }
            
        ListNode* prev = revHead;
        revHead = head;
        head = revHead->next;
        revHead->next = prev;
        return(Reverse(revHead, head));
    }   
};
