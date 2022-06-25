/*
Problem : Given two integers a and b, return the sum of the two integers without using the operators + and -.

https://leetcode.com/problems/sum-of-two-integers/

Time Complexity ?? 
Space Complexity : O(1)
*/

class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0)
            return b;
        int carry;
        while (b!=0) {
            carry = a&b;
            a = a^b;
            b = (unsigned)(carry) << 1;
        }
        return a;
    }
};
