/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int N = nums.size();
        vector<int> res(N, 1);
        if (N <= 1)
            return res;
        
        vector<int> g(N, 1);
        g[N - 1] = nums[N - 1]; 
        for (int i = N - 2; i >= 0; i --)
            g[i] = nums[i] * g[i + 1];
            
        vector<int> f(N, 1);
        f[0] = nums[0];
        for (int i = 1; i < N; i ++)
            f[i] = f[i -1] * nums[i];
            
        res[0] = g[1];
        res[N - 1] = f[N - 2];
        for (int i = 1; i < N - 1; i ++)
            res[i] = f[i - 1] * g[i + 1];
            
        return res;
    }
};
