/*
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return nums.size() - removeE(nums, 0, nums.size(), val);
    }
    
private:
    int removeE(vector<int>& nums, const int s, const int N, const int val) {
        if (s == N)
            return 0;
        for (int i = s; i < N; i ++) {
            if (nums[i] == val) {
                
                for (int j = i; j + 1 < N; j ++) 
                    nums[j] = nums[j + 1];
                return removeE(nums, i, N - 1, val) + 1;
            }
        }
        return 0;
    }
};
