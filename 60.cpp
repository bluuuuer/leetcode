/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 0)
            return "";
        if (n == 1)
            return "1";
            
        string res;
        vector<int> nums;
        for (int i = 0; i < n; i ++)
            nums.push_back(i + 1);
        
        res = getP(nums, k - 1);
        return res;
    }
    
private:
    string getP(vector<int> nums, int k) {
        const int N = nums.size();
        if (k == 0) {
            stringstream ss;
            for (int i = 0; i < N; i ++)
                ss << nums[i];
            return ss.str();
        }
        
        int F_n_1 = 1;
        for (int i = 1; i < N; i ++)
            F_n_1 *= i;
        int x = k / F_n_1; 
        int c = nums[x];
        nums.erase(nums.begin() + x);
        stringstream ss;
        ss << c << getP(nums, k % F_n_1);
        return ss.str();
    }
};
