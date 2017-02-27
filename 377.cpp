/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return 0;
        
        this->func[0] = 1;
        sort(nums.begin(), nums.end());
        this->func[nums[0]] = 1;
        for (int i = 1; i < nums[0]; i ++)
            this->func[i] = 0;
        
        if (this->func.find(target) != this->func.end())
            return this->func[target];
        else 
            return CalcuNum(nums, target);
    }
    
private:
    map<int, int> func;
    
    int CalcuNum(vector<int> nums, int target) {
        int res = 0;
        for (int i = 0; i < nums.size(); i ++)
            if (nums[i] <= target) {
                if (this->func.find(target - nums[i]) != this->func.end())
                    res += this->func[target - nums[i]];
                else
                    res += CalcuNum(nums, target - nums[i]);
            }
        this->func[target] = res;
        //cout << "func(" << target << ") = " << res << endl;
        return res;
    }
};
