/*
Problem : Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

https://leetcode.com/problems/missing-number/

Time Complexity : O(N)
Space Complexity : O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = size*(size+1)/2; //Sum is n*(n+1)/2 but here size also includes 0!
        
        for (int i=0; i<size; i++)
            sum -= nums[i];
        
        return sum;
    }
};
