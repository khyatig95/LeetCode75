/*
Problem : Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.
A subarray is a contiguous subsequence of the array.

https://leetcode.com/problems/maximum-product-subarray/

Time Complexity : O(N)
Space Complexity : O(1)
*/

#include <limits.h>
#include <algorithm>
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() < 2) {
            return (nums.front());
        }
        
        int res = INT_MIN;
        int max_P = 1;
        int min_P = 1;
        
        for (auto itr = nums.begin(); itr < nums.end(); itr++) { //Time: O(N)
            if (*itr < 0) {
                swap(max_P, min_P);
            }
            //Storing max product of pos numbers
            max_P = max(max_P*(*itr), *itr);
            
            //Storing max product of neg numbers
            min_P = min(min_P*(*itr), *itr);
            res = max(res, max_P);
        }
        return res;
    }
};
