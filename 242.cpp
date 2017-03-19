/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> ms;
        for (int i = 0; i < s.length(); i ++)
            ms[s[i]] ++;
        for (int i = 0; i < t.length(); i ++) {
            if (ms.find(t[i]) != ms.end())
                ms[t[i]] --;
            else
                return false;
        }
        for (auto mms : ms)
            if (mms.second != 0)
                return false;
        return true;
    }
};
