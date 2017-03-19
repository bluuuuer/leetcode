/*
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
*/

class Solution {
public:
    string reverseStr(string s, int k) {
        if (s.length() < k)
            revS(s, 0, s.length() - 1);
        else {
            revS(s, 0, k - 1);
            if (s.length() > 2 * k) {
                string s_1 = s.substr(0, 2 * k);
                string s_2 = s.substr(2 * k, s.length() - 2 * k);
                s_2 = reverseStr(s_2, k);
                s_1.insert(s_1.end(), s_2.begin(), s_2.end());
                s = s_1;
            }
        }
        return s;
    }
    
private:
    void revS(string& s, int b, int e) {
        while (b < e) {
            const char c = s[b];
            s[b] = s[e];
            s[e] = c;
            b ++;
            e --;
        }
    }
};
