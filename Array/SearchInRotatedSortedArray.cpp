/*
Problem : There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size(); 
       
        if (size == 1) {
            if (nums[0] == target)
                return 0;
            else 
                return -1;
        } 
        
        int mid = (size%2 == 0) ? size/2 : (size+1)/2 - 1;
        int index;
        if (nums[mid] == target)
            return mid;
        
        bool isArrayRotated = nums[0] > nums[size-1]; 
        bool pivotFirstHalf = nums[mid] < nums[0]; 
        
        bool secondHalf = isArrayRotated ? (                                   
                                pivotFirstHalf ? (target > nums[mid] && target <= nums[size-1])
                                                : !(target >= nums[0] && target < nums[mid])
                                            ) 
                                        : target > nums[mid]; 
        
        if (secondHalf) {           
            nums.erase(nums.begin(), nums.begin()+mid);
            index = search(nums, target);
            if (index != -1)
                return(mid + index);
            else 
                return -1;
        } else { //First half
            nums.erase(nums.begin()+mid, nums.end());
            return(search(nums, target));
        }
        return -1;
    }
};
