/*
Problem : Given two integers a and b, return the sum of the two integers without using the operators + and -.

https://leetcode.com/problems/sum-of-two-integers/

Time Complexity /Space Complexity ??. Stack will be sued for recursion
*/

class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0)
            return b;
        else if (b == 0)
            return a;
        
        int xor1 = a^b;
        int or1 = a|b;
        int and1 = (unsigned)(a&b) << 1; //We move it to the left as it is a carry

        if (xor1 == or1)
            return(xor1|and1);
        else
            return(getSum(xor1, and1));
    }
};
