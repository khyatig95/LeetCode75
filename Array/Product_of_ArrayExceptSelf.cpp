/*
Problem : Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

https://leetcode.com/problems/product-of-array-except-self/

Logic :
Have a forward array where fp[i] = product of all elements uptil i (not including i) in the input array
Have a reverse array where rp[i] = product of all elements uptil i (not including i) in the reversed input array
Result res[i] = reverse(rp[i]) * fp [i];

Example :
nums = [1,2,3,4]
fp   = [1,1,2,6]

reverse(nums) = [4,3,2,1]
rp            = [1,4,12,24]

fp          = [ 1, 1,2,6]
          *
reverse(rp) = [24,12,4,1]
res         = [24,12,8,6]

Time Complexity : O(N)
Space Complexity : O(N)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() < 2)
            return {-1};
        
        //Space : O(N)
        vector<int> res;
        vector<int> rp; 
        int i, prod; 
        res.reserve(nums.size()); 
        rp.reserve(nums.size()); //reverse products

        rp[nums.size()-1] = 1;
        for (i = nums.size() - 1; i > 0 ; i--) { //Time : O(N)
            rp[i-1] = rp[i] * nums[i];        
        }
        
        
        res.push_back(rp[0]); //pp[0] = 1 
        prod = 1;
        for (i = 1; i < nums.size() ; i++) { //Time : O(N)
            if (prod != 0) {
                prod *= nums[i-1];
                res.push_back(rp[i] * prod);
            } else 
                res.push_back(0);
        }
            
        return res;
    }
};
