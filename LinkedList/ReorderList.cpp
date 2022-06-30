/*
Problem : You are given the head of a singly linked-list. The list can be represented as:
L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

https://leetcode.com/problems/reorder-list/

Time Compelxity : O(N)
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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return;
        
        ListNode* fast = head, *slow = NULL;
        bool flag = false;
        while(fast->next != NULL) {
            fast = fast->next;
            if (flag) { 
                if (slow != NULL)
                    slow = slow->next;
                else
                    slow = head;
            }
            flag = !flag;
        }
        if (flag)
            slow = slow->next;
        //Join the first and second reversed half
        slow->next = reverseList(slow->next); //O(N)
 
        ListNode* dummy = new ListNode();
        ListNode* itr1 = head, *itr2 = slow, *hold, *rHold;
        
        while (itr1 != itr2) { //O(N)
            dummy = itr2->next;
            hold = itr1->next;
            rHold = itr2->next->next;
            itr1->next = dummy;
            itr1->next->next = hold;
            itr1 = itr1->next->next;
            itr2->next = rHold;
        }
    }
    
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
