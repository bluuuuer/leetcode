/*
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string. 
Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"


Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"

Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.
*/

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), compV);
        for (int i = 0; i < d.size(); i ++) {
            string sub = d[i];
            int j, k = 0;
            for (j = 0; j < s.length(); j ++)
                if (s[j] == sub[k]) {
                    if (k == sub.length() - 1)
                        return sub;
                    k ++;
                }
        }
        return "";
    }
    
private:
    static bool compV(string a, string b) {
        if (a.length() != b.length())
            return a.length() > b.length();
        else
            return a < b;
    }
};
