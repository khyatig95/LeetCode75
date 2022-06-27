/*
Problem : You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

https://leetcode.com/problems/merge-k-sorted-lists/

Time Complexity : O(klogk + Nlogk) = O(Nlogk) if k<N
Space Complexity : O(k)
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        
        ListNode* head = NULL, *curr;
        ListNode* temp = NULL;
        multimap<int, ListNode*> hmap; //We need multimap as different linked list could have nodes with same val - Space Complexity : O(k) as no more than k elements in the map at a time
        for (auto itr : lists) { //O(klogk) to insert heads of all Linked Lists
            if (itr != NULL)
                hmap.insert( pair<int,ListNode*> (itr->val, itr) );
        }

        while (!hmap.empty()) {  //O(N*logk) where N=total number of elements but only k elements in the map at a time. Therefore to insert/delete each element, only O(k) needed
            auto h_itr = hmap.begin(); //Sorted based on keys = val
            curr = h_itr->second;

            if (head == NULL) {
                temp = new ListNode(curr->val);
                head = temp;            
            } else {
                temp->next = new ListNode(curr->val);
                temp = temp->next;
            }
            
            //Delete the element processed
            hmap.erase(hmap.begin());
            
            if (curr->next != NULL) //Insert the next element from the linked list whose element got picked
                hmap.insert( pair<int,ListNode*> (curr->next->val, curr->next) );
        }
        return head;
    }
};
