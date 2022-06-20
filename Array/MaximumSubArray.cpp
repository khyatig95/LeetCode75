/*
Problem: Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.

https://leetcode.com/problems/maximum-subarray/
*/

#include <cstdlib>
#include <algorithm>
#include <limits.h>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums[0];
        }
        
        int running_sum = 0, res = INT_MIN;
        
        for(auto itr = nums.begin(); itr < nums.end(); itr++) { //Time : O(N)
            running_sum = max(*itr, running_sum + *itr); 
            res = max(res, running_sum);
        }
        
        return res;
    }
};
