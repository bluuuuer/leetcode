/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.length() <= 1)
            return true;
          
        int i = 0;  
        if (word[0] >= 'A' && word[0] <= 'Z')
            i ++;
            
        int j = i + 1;
        if (word[i] >= 'a' && word[i] <= 'z') {
            while (j < word.length()) {
                if (word[j] >= 'A' && word[j] <= 'Z')
                    return false;
                j ++;
            }
        } else {
            while (j < word.length()) {
                if (word[j] >= 'a' && word[j] <= 'z')
                    return false;
                j ++;
            }
        }
        return true;
    }
};
