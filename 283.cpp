/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int x = nums.size();
        int i = 0;
        while (x > 0) {
            x --;
            if (nums[i] == 0) {
                nums.push_back(0);
                nums.erase(nums.begin() + i);
            } else
                i ++;
        }
    }
};
