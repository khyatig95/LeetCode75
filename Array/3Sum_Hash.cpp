/*
Problem : Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

https://leetcode.com/problems/3sum/

Time Complexity : O(N^2)
Space Complexity : O(N)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        if (size < 3)
            return {};
        
        sort(nums.begin(), nums.end()); //O(NlogN)
        vector<vector<int>> res;
        for (int i = 0; i<size; i++) { //O(N^2)
            if (i != 0 && nums[i] == nums[i-1]) //Want to avoid duplicates
                continue;
            
            unordered_set<int> uset;
            for (int j = i+1; j<size; j++) {
                if(uset.find(-nums[i] - nums[j]) != uset.end()) {
                    res.push_back({nums[i], nums[j], -nums[i] - nums[j]});
                    while (j+1 < size && nums[j] == nums[j+1]) {
                        j++;
                    }
                }  
                uset.insert(nums[j]);
            }
        }
        return res;
    }
    
};
