/*
Problem: Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

https://leetcode.com/problems/contains-duplicate/

Time Complexity : O(N)
Space Complexity : O(N)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() < 2)
            return false;
        
        unordered_set<int> uset; //Space : O(N)
        for (auto itr = nums.begin(); itr < nums.end(); itr++) { //Time: O(N)
            auto temp = uset.find(*itr);
            if (temp != uset.end()) 
                return true;
            
            uset.insert(*itr);
        }
        return false;
    }
};
