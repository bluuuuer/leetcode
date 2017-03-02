/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end(), comp);
        sort(nums2.begin(), nums2.end(), comp);
        int id_1 = 0;
        int id_2 = 0;
        while (id_1 < nums1.size() && id_2 < nums2.size()) {
            if (nums1[id_1] < nums2[id_2]) {
                id_1 ++;
            } else if (nums1[id_1] == nums2[id_2]) {
                res.push_back(nums1[id_1]);
                id_1 ++;
                id_2 ++;
            } else {
                id_2 ++;
            }
        }
        for (int i = 0; i < (int)res.size() - 1; i ++) {
            if (res[i] == res[i + 1]) {
                res.erase(res.begin() + i);
                i --;
            }
        }
        return res;
    }
private:
    static bool comp(int a, int b) {
        return a < b;
    }
};
