// Given a set of distinct integers, nums, return all possible subsets. 
// Note: The solution set must not contain duplicate subsets. 
// For example,
// If nums = [1,2,3], a solution is: 
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;
                
        if (nums.size() == 0)
            result.push_back(nums);
        else {
            int temp = nums[0];
            vector<int> nums_ = nums;
            nums_.erase(nums_.begin());
            vector<vector<int> > temp_v = subsets(nums_);
            for(int j = 0; j < temp_v.size(); j ++) {
                result.push_back(temp_v[j]);
                temp_v[j].push_back(temp);
                result.push_back(temp_v[j]);
            }
        }
        return result;
    }
};
