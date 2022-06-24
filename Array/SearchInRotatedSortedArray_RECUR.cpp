/*
Problem : There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

https://leetcode.com/problems/search-in-rotated-sorted-array/

Time Complexity : O(logN)
Space Complexity : due to stack for recursive calls - O(logN)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size(); 
       
        return (BinarySearch(nums, 0, size-1, target));
    }
    
    int BinarySearch(vector<int>& nums, int start, int end, int target) {
        
        if ((end-start+1) == 1) {
            if (nums[start] == target)
                return start;
            else 
                return -1;
        } 
        
        int mid = (end-start+1)/2 + start;
        
        if (nums[mid] == target)
            return mid;
        
        bool isArrayRotated = nums[start] > nums[end]; 
        bool pivotFirstHalf = nums[mid] < nums[start]; 
        
        bool secondHalf = isArrayRotated ? (                                   
                                pivotFirstHalf ? (target > nums[mid] && target <= nums[end])
                                                : !(target >= nums[start] && target < nums[mid])
                                            ) 
                                        : (
                                            target > nums[mid]
                                          ); 
        
        if (secondHalf && (mid+1 <= end)) { //Second half           
            return(BinarySearch(nums, mid+1, end, target));
        } else if (mid-1 >= start) { //First half
            return(BinarySearch(nums, start, mid-1, target));
        }
        return -1;
    }
};
