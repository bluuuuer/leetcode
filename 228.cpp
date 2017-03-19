/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        for (int i = 0; i < nums.size();) {
            stringstream ss;
            ss << nums[i];
            
            i ++;
            if (i < nums.size() && nums[i] - nums[i - 1] > 1)
                res.push_back(ss.str());
            else if (i < nums.size()) {
                while (i < nums.size() && nums[i] - nums[i - 1] == 1)
                    i ++;
                ss << "->" << nums[i - 1];
                res.push_back(ss.str());
            } else {
                res.push_back(ss.str());
            }
        }
        return res;
    }
};
