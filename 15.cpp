//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

//Note: The solution set must not contain duplicate triplets.

//For example, given array S = [-1, 0, 1, 2, -1, -4],

//A solution set is:
//[
//  [-1, 0, 1],
//  [-1, -1, 2]
//]

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        
        map<int, int> num_map;
        vector<int> mins_num;
        vector<int> pos_num;
        for (int i = 0; i < nums.size(); i ++) {
            num_map[nums[i]] += 1;
            if (nums[i] < 0)
                mins_num.push_back(nums[i]);
            else if (nums[i] > 0)
                pos_num.push_back(nums[i]);
        }
        
        sort(mins_num.begin(), mins_num.end());
        mins_num.erase(unique(mins_num.begin(), mins_num.end()), mins_num.end());
        
        sort(pos_num.begin(), pos_num.end());
        pos_num.erase(unique(pos_num.begin(), pos_num.end()), pos_num.end());
        
        if (num_map[0] >= 3)
            result.push_back({0,0,0});
            
        if (num_map[0] > 0)
            for (int i = 0; i < mins_num.size(); i ++) {
                const int temp = mins_num[i];
                if (num_map[-temp] > 0)
                    result.push_back({0, temp, -temp});
            }
        
        for (int i = 0; i < mins_num.size(); i ++) {
            for (int j = i; j < mins_num.size(); j ++) {
                const int temp_i = mins_num[i];
                const int temp_j = mins_num[j];
                if ((i == j && num_map[temp_i] > 1 && num_map[-temp_i-temp_j] > 0)
                    || (j != i  && num_map[-temp_i-temp_j] > 0))
                    result.push_back({temp_i, temp_j, -temp_i-temp_j});
            }
        }
        
        for (int i = 0; i < pos_num.size(); i ++) {
            for (int j = i; j < pos_num.size(); j ++) {
                const int temp_i = pos_num[i];
                const int temp_j = pos_num[j];
                if ((j == i && num_map[temp_i] > 1 && num_map[-temp_i-temp_j] > 0)
                    || (j != i && num_map[-temp_i-temp_j] > 0))
                    result.push_back({temp_i, temp_j, -temp_i-temp_j});
            }
        }
        
        return result;
    }
};
