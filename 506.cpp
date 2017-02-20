/*
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.
*/


class Solution {
public:
    static bool sort_by_val(pair<int, int>& val_pos_1, pair<int, int>& val_pos_2) {
        return (val_pos_1.first > val_pos_2.first);
    }
    
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> s(nums.size(), "");
        list<pair<int, int>> val_pos;
        for (int i = 0; i < nums.size(); i ++)
            val_pos.push_back(make_pair(nums[i], i));
            
        val_pos.sort(sort_by_val);
        
        list<pair<int, int> >::iterator it = val_pos.begin();
        int idx = 1;
        while (it != val_pos.end()) {
            if (idx == 1)
                s[(*it).second] = "Gold Medal";
            if (idx == 2)
                s[(*it).second] = "Silver Medal";
            if (idx == 3)
                s[(*it).second] = "Bronze Medal";
            if (idx > 3) {
                stringstream ss;
                ss << idx;
                string s_temp = "";
                ss >> s_temp;
                s[(*it).second] = s_temp;
            }
            idx ++;
            it ++;
        }
        return s;
    }
};
