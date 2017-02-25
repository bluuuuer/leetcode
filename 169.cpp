/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> times;
        const int n = nums.size();
        if (n == 1)
            return nums[0];
        for (int i = 0; i < n; i ++) {
            const int val = nums[i];
            if (times.find(val) == times.end())
                times[val] = 1;
            else {
                times[val] ++;
                if (times[val] > n / 2)
                    return val;
            }
        }
    }
};
