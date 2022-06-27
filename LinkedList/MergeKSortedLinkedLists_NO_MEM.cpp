/*
Problem : You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

https://leetcode.com/problems/merge-k-sorted-lists/

Time Complexity : O(Nlogk) 
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
 
        int start = 0;
        int end = lists.size()-1;
        int i, j= end;
        while ( start < end) { //O(Nlogk)
            i = start;         
            while(i < j) {
                lists[i] = mergeTwoLists(lists[i], lists[j]); 
                j--;
                i++;
            }
            end = j; //Now we only process till k/2 as we have merged
        }
        return lists[0];
    }
    
    
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
