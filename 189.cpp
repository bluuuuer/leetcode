/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0)
            return;
        vector<int> temp;
        temp.insert(temp.end(), nums.begin(), nums.end());
        temp.insert(temp.end(), nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i ++)
            nums[i] = temp[i + nums.size() - k];
    }
};
