/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.size() == 0)
		    return 0;

        sort(words.begin(), words.end(), compSL);
        int res = 0;
        vector<string> temp_words = { words[0] };

        for (int i = 1; i < words.size(); i++)
        	addWord(temp_words, res, words[i]);

        return res;
    }

private:
    static bool compSL(string& a, string& b)  {
        return a.length() > b.length();
    }
	
    void addWord(vector<string>& words, int& res, string word) {
        for (int i = 0; i < words.size(); i++) {
        	if (words[i].length() * word.length() <= res)
            	break;
          	else {
            	bool overlap = false;
            	for (int j = 0; j < words[i].length(); j++) {
              		for (int k = 0; k < word.length(); k++)
                		if (words[i][j] == word[k]) {
                    		overlap = true;
                  			break;
                		}
              		if (overlap)
                		break;
            	}
            	if (!overlap)
              		res = words[i].length() * word.length();
          	}
        }
        words.push_back(word);
    }
};
