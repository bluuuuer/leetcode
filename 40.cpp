/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) 
    {
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        vector<int> local;
        findCombination(res, 0, target, local, num);
        return res;
    }
    void findCombination(vector<vector<int>>& res, const int order, const int target, vector<int>& local, const vector<int>& num) {
        if(target == 0) {
            res.push_back(local);
            return;
        } else {
            for(int i = order; i < num.size(); i ++) { // iterative component
                if(num[i] > target) 
                    return;
                if(i && num[i] == num[i - 1] && i > order) 
                    continue; // check duplicate combination
                local.push_back(num[i]),
                findCombination(res, i + 1, target - num[i], local, num); // recursive componenet
                local.pop_back();
            }
        }
    }
};
