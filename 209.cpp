/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums[0] > s)
            return 1;
        
        int i = 0;
        int res = nums.size();
        int sum = nums[0];
        int cur_len = 1;
        for (int j = 1; j < nums.size(); j ++) {
            if (j == nums.size() - 1 && cur_len == nums.size() - 1 && sum + nums[j] < s)
                return 0;
                
            if (nums[j] <= nums[i]) {
                cur_len ++;
                sum += nums[j];
                if (sum >= s) {
                    res = min(res, cur_len);
                    sum -= nums[i];
                    i ++;
                }
            } else {
                if (sum + nums[j] - nums[i] >= s) {
                    sum += nums[j] - nums[i];
                    i ++;
                    while (sum >= s) {
                        sum -= nums[i];
                        i ++;
                    }
                    cur_len = j - i + 2;
                    res = min(res, cur_len);
                    cur_len --;
                } else if (sum + nums[j] >= s) {
                    cur_len ++;
                    sum += nums[j] - nums[i];
                    res = min(res, cur_len);
                    i ++;
                } else {
                    sum += nums[j];
                    cur_len ++;
                }
            }
        }
        return res;
    }
};
