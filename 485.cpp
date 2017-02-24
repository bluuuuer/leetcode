/*
Given a binary array, find the maximum number of consecutive 1s in this array.
Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int temp = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == 0)
                temp = 0;
            else
                res = max(++ temp, res);
        }
        return res;
    }
};
