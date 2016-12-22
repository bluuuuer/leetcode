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
        int max = -100000;
        int min = 100000;
        for (int i = 0; i < nums.size(); i ++) {
            max = nums[i] > max ? nums[i] : max;
            min = nums[i] < min ? nums[i] : min;
            num_map[nums[i]] += 1;
        }
        if (num_map[0] >= 3)
            result.push_back({0,0,0});
        if (num_map[0] > 0) {
            for (int i = min; i < 0; i ++) {
                if (num_map[i] > 0 && num_map[-i] > 0) {
                    result.push_back({0, i, -i});
                }
            }
        } 
        for (int i = min; i < 0; i ++) {
            if (num_map[i] > 0)
                for (int j = i; j < 0; j ++) {
                    if ((j == i && num_map[i] > 1 && num_map[-i-j] > 0)
                        || (j != i && num_map[j] > 0 && num_map[-i-j] > 0)) {
                        result.push_back({i, j, -j-i});
                    }
                }
        }
        for (int i = max; i > 0; i --) {
            if (num_map[i] > 0)
                for (int j = i; j > 0; j --) {
                    if ((j == i && num_map[i] > 1 && num_map[-i-j] > 0)
                        || (j != i && num_map[j] > 0 && num_map[-i-j] > 0)) {
                        result.push_back({i, j, -j-i});
                    }
                }
        }
        return result;
    }
};
