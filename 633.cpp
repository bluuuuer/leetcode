/*
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:
Input: 3
Output: False
*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = floor(sqrt(c)); i >= floor(sqrt(c / 2)); i --) {
            if (c == i * i)
                return true;
            else {
                int b = c - i * i;
                int a = floor(sqrt(b));
                if (a * a == b) {
                    return true;
                }
            }
        }
        return false;
    }
};
