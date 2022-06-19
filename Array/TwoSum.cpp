/*
Problem: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. 
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

https://leetcode.com/problems/two-sum/
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> hash;  //key = value, val = index
        for (int i=0; i<nums.size(); i++) {  //O(N) ; Space O(N)
            auto temp = hash.find(target-nums[i]);
            if (temp != hash.end()) 
                return {i, hash[target-nums[i]]};
            hash[nums[i]] = i;   
        }
        return {-1, -1};

    }
    
};
