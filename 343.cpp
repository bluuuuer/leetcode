/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
*/

class Solution {
public:
    int integerBreak(int n) {    
        res[1] = 1;
        res[2] = 1;
        return intB(n);
    }
    
private:
    map<int, int> res;
    
    int intB(const int n) {
        if (res.find(n) != res.end())
            return res[n];
        int max_s = 0;
        for (int i = 1; i < n; i ++) {
            max_s = max(max_s, i * max(n - i, intB(n - i)));
        }
        res[n] = max_s;
        return max_s;
    }
};
