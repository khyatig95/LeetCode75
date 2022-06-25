/*
Problem : Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
Follow up:
It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?

https://leetcode.com/problems/counting-bits/

Time Complexity : O(N)
Space Complexity : O(N)
*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        for (int i = 1; i <= n; i++) 
            res[i] = res[i>>1] + (i&1); //Only if LSB is 1 then number has an extra 1 than number/2  
        return res;
    }
};
