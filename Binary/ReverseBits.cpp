/*
Problem : Reverse bits of a given 32 bits unsigned integer.
Follow up: If this function is called many times, how would you optimize it?  =>Hash the solutions

https://leetcode.com/problems/reverse-bits/

Time Complexity : O(N) where N=size of integer
Space Complexity : O(1)
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int reverse = 0;
        int count = 0;
        
        reverse = reverse | (n&1);
        while (count < 32) {
            reverse = (unsigned)reverse << 1;
            reverse = reverse | (n&1);
            n = n >> 1;
            count ++;
        }

        return reverse;
    }
};
