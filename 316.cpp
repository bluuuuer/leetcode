// Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

// Example:
// Given "bcabc"
// Return "abc"

// Given "cbacdcbc"
// Return "acdb"

class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.length() <= 1)
            return s;
            
        int start_id = 96;
        while (start_id < 123) {
            int min_word = 123;
            for (int i = 0; i < s.length(); i ++)
                if (s[i] > start_id)
                    min_word = min(min_word, (int)s[i]);
            
            vector<int> poses;
            for (int i = 0; i < s.length(); i ++)
                if (s[i] == min_word)
                    poses.push_back(i);
                    
            appear.resize(26);
            for (int i = 0; i < poses.size(); i ++)
                if (Able(s, poses[i])) {
                    string s_left = s.substr(poses[i] + 1, s.length() - poses[i] - 1);
                    for (int j = 0; j < s_left.length(); j ++)
                        if (s_left[j] == min_word) {
                            s_left.erase(s_left.begin() + j);
                            j --;
                        }
                    string result = s.substr(poses[i], 1) + removeDuplicateLetters(s_left);
                    return result;
                }
            start_id ++;
        }
    }
private:
    vector<bool> appear;
    
    bool Able(string s, int pos) {
        if (pos == 0)
            return true;
            
        for (int i = 0; i < 26; i ++)
            appear[i] = false;
        
        for (int i = s.length() - 1; i >= 0; i --) {
            if (i > pos)
                appear[s[i] - 97] = true;
            else if (i < pos && !appear[s[i] - 97])
                return false;
        }
        return true;
    }
};
