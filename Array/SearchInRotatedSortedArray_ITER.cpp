/*
Problem : There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

https://leetcode.com/problems/search-in-rotated-sorted-array/

Time Complexity : O(logN)
Space Complexity : O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int end = nums.size()-1; 
        int start = 0;
        int mid;
        
        bool isArrayRotated; 
        bool pivotFirstHalf; 
        bool secondHalf; 
            
        while (start <= end) {
            mid = (end-start+1)/2 + start;
            if (nums[mid] == target)
                return mid;
        
            isArrayRotated = nums[start] > nums[end];
            pivotFirstHalf = nums[mid] < nums[start]; 
            secondHalf = isArrayRotated ? (                                   
                                pivotFirstHalf ? (target > nums[mid] && target <= nums[end])
                                                : !(target >= nums[start] && target < nums[mid])
                                            ) 
                                        : (
                                            target > nums[mid]
                                          );
            if (secondHalf)
                start = mid+1;
            else 
                end = mid-1;
        } 
        return -1;
    }
};
