//Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

//For example, given
//s = "leetcode",
//dict = ["leet", "code"].

//Return true because "leetcode" can be segmented as "leet code".

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (wordDict.size() == 0) 
            return false;
        
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= s.size(); i ++)
            for (int j = i - 1; j >= 0; j --)
                if (dp[j]){
                    string word = s.substr(j, i - j);
                    if (wordDict.find(word) != wordDict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
        
        return dp[s.size()];
    }
};
