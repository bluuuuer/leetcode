// Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.


// American keyboard


// Example 1:
// Input: ["Hello", "Alaska", "Dad", "Peace"]
// Output: ["Alaska", "Dad"]
// Note:
// You may use one character in the keyboard more than once.
// You may assume the input string will only contain letters of alphabet.

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        
        if (words.size() == 0)
            return result;
            
        Init();
        
        for (int i = 0; i < words.size(); i ++)
            if (findWord(words[i]))
                result.push_back(words[i]);
        
        return result;
    }
    
private:
    map<char, int> line_1;
    map<char, int> line_2;
    map<char, int> line_3;
    
    void Init() {
        string s_1 = "qwertyuiop";
        string s_2 = "asdfghjkl";
        string s_3 = "zxcvbnm";
        for (int i = 0; i < s_1.length(); i ++)
            line_1[s_1[i]] = i;
        for (int i = 0; i < s_2.length(); i ++)
            line_2[s_2[i]] = i;
        for (int i = 0; i < s_3.length(); i ++)
            line_3[s_3[i]] = i;
    }
    
    bool findWord(string word) {
        map<char, int> m_map;
        if (word[0] < 97)
            word[0] += 32;
            
        if (line_1.find(word[0]) != line_1.end())
            m_map = line_1;
        else if (line_2.find(word[0]) != line_2.end())
            m_map = line_2;
        else
            m_map = line_3;
            
        for (int i = 1; i < word.length(); i ++) {
            if (word[i] < 97)
                word[i] += 32;
            if (m_map.find(word[i]) == m_map.end())
                return false;
        }
        return true;
    }
};
