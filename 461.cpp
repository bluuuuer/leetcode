/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.
Note:
0 ≤ x, y < 231. 
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int res = 0;
        while (n > 0) {
            if (n % 2 != 0)
                res ++;
            n /= 2;
        }
        return res;
    }
};
