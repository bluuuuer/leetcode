/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int> > nums;
        for (int i = 0; i < 127; i ++)
            nums.push_back(make_pair((char)i, 0));
        
        for (int i = 0; i < s.length(); i ++)
            nums[(int)s[i]].second ++;
        
        sort(nums.begin(), nums.end(), MyComp);
        
        string result = "";
        for (int i = 0; i < nums.size(); i ++)
            for (int j = 0; j < nums[i].second; j ++)
                result += nums[i].first;
        
        return result;
    }
private:
    static bool MyComp(pair<char, int> a, pair<char, int> b) {
        return a.second > b.second;
    }
};
