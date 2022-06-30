/*
Problem : Given the head of a singly linked list, reverse the list, and return the reversed list.
https://leetcode.com/problems/reverse-linked-list/
Time Complexity : O(N)
Space Complexity : O(N) stack for N recursive calls
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
            if (revHead != nullptr) {
                if (head == nullptr)
                    head = revHead;
                else
                    head->next =  revHead;
            }
            return head;
        }
            
        ListNode* prev = revHead;
        revHead = head;
        head = head->next;
        revHead->next = prev;
        return(Reverse(revHead, head));
    }   
};
