/*
Problem : Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

https://leetcode.com/problems/3sum/

Time Complexity : O(N^2)
Space Complexity : O(1)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        if (size < 3)
            return {};
        
        sort(nums.begin(), nums.end()); //O(NlogN)
        vector<vector<int>> res;
        int l, r;
        for (int i = 0; i<size-1; i++) {
            if (i != 0 && nums[i] == nums[i-1]) //Want to avoid duplicates
                continue;
            l = i+1;
            r = size-1;
            while (l<r) {
                if (nums[i] + nums[l] + nums[r] == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while(l < size && nums[l] == nums[l-1])
                        l++;
                } else if (nums[i] + nums[l] + nums[r] > 0) {
                    r--;
                    while(r >= 0 && nums[r] == nums[r+1])
                        r--;
                } else {
                    l++;
                    while(l < size && nums[l] == nums[l-1])
                        l++;
                }

            }

        }
        return res;
    }  
};
