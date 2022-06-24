/*
Problem : Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time.

https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

Time Complexity : O(logN)
Space Complexity : due to stack for recursive calls - O(logN)

*/

#include <math.h>
#include <algorithm>
class Solution {
public:
    int findMin(vector<int>& nums) {   
        int size = nums.size();
        return(BinarySearch(nums, 0, size-1));     
    }
    
    int BinarySearch(vector<int>& nums, int start, int end) {
        if (end-start+1 == 2) {
            return min(nums[start], nums[end]);
        } else if (end-start < 2) {
            return nums[start];
        }   
        
        int mid = (end-start+1)/2 + start;
        if ((nums[start] < nums[end] && nums[mid] > nums[start]) || (nums[start] > nums[end] && nums[mid] < nums[start]))  //Pick front part of array
            return(BinarySearch(nums, start, mid));
        else //Pick latter part of the array
            return(BinarySearch(nums, mid, end));
    }
};
