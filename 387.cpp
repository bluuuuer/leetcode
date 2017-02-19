// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

// Examples:

// s = "leetcode"
// return 0.

// s = "loveleetcode",
// return 2.
// Note: You may assume the string contain only lowercase letters.

class Solution {
public:
    int firstUniqChar(string s) {
        int* pos = new int[26];
        memset(pos, -1, 26 * sizeof(int));
        for (int i = 0; i < s.length(); i ++) {
            if (pos[s[i] - 97] == -1)
                pos[s[i] - 97] = i;
            else if (pos[s[i] - 97] > -1)
                pos[s[i] - 97] = -2;
        }
        int num = -1;
        for (int i = 0; i < 26; i ++)
            if (pos[i] >= 0 && (num < 0 || (num >= 0 && pos[i] < num)))
                num = pos[i];
        return num;
    }
};
