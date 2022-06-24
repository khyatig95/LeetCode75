/*
Problem : Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time.

https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

Time Complexity : O(logN)
Space Complexity : O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {        
        int l=0, r=nums.size()-1;
        if(nums[l]<=nums[r]) //Unrotated sorted array
          return nums[l];
        while(l<=r) {
            int m = (r+l)/2;
            if(nums[m] > nums[m+1]) //Found point of rotation
              return nums[m+1]; 
            if(nums[m] > nums[l]) //First half is sorted => second half will have point of rotation and hence, the min
              l=m+1;
            else 
              r=m;
        }
        return nums[0];
    }
};
