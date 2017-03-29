/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res = sswd(nums);
        for (int i = 0; i + 1 < res.size(); i ++) {
            if (compV(res[i], res[i + 1])) {
                res.erase(res.begin() + i);
                i --;
            }
        }
        return res;
    }
    
private:
    bool compV(vector<int> a, vector<int> b) {
        if (a.size() != b.size())
            return false;
        for (int i = 0; i < a.size(); i ++)
            if (a[i] != b[i])
                return false;
        return true;
    }

    static bool compVV(vector<int>& a, vector<int>& b) {
        if (a.size() < b.size())
            return true;
        else if (a.size() > b.size())
            return false;
        else {
            for (int i = 0; i < a.size(); i ++) {
                if (a[i] < b[i])
                    return true;
                else if (a[i] > b[i])
                    return false;
            }
            return true;
        }
    }
    
    vector<vector<int> > sswd(vector<int> nums) {
        vector<vector<int> > result;
                
        if (nums.size() == 0)
            return {};
        if (nums.size() == 1)
            return {{}, {nums[0]}};
        else {
            int temp = nums[0];
            vector<int> nums_ = nums;
            nums_.erase(nums_.begin());
            vector<vector<int> > temp_v = sswd(nums_);
            for(int j = 0; j < temp_v.size(); j ++) {
                result.push_back(temp_v[j]);
                temp_v[j].push_back(temp);
                result.push_back(temp_v[j]);
            }
        }
        for (int i = 0; i < result.size(); i ++)
            sort(result[i].begin(), result[i].end());
        cout << result.size() << endl;
        sort(result.begin(), result.end(), compVV);
        return result;
    }
};
