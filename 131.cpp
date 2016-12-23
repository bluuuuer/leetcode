//Given a string s, partition s such that every substring of the partition is a palindrome.

//Return all possible palindrome partitioning of s.

//For example, given s = "aab",
//Return

/[
//  ["aa","b"],
//  ["a","a","b"]
//]

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > result;
        if (s.size() == 1 || (s.size() > 1 && isPali(s))) {
            vector<string> temp_v;
            temp_v.push_back(s);
            result.push_back(temp_v);
            if (s.size() == 1)
                return result;
        }
        
        for (int i = 1; i < s.size(); i ++) {
            string temp_1 = s.substr(0, i);
            string temp_2 = s.substr(i, s.size() - i);
            //printf ("%s [%s, %s]\n", s.c_str(), temp_1.c_str(), temp_2.c_str());
            
            vector<vector<string> > temp_result;
            if (
                (i == 1 && isPali(temp_1)) ||
                (i != 1 && s[i - 1] == s[0] && isPali(temp_1.substr(1, temp_1.size() - 2)))
                ) {
                temp_result = partition(temp_2);
                for (int j = 0; j < temp_result.size(); j ++)
                    temp_result[j].insert(temp_result[j].begin(), temp_1);
                result.insert(result.end(), temp_result.begin(), temp_result.end());
            }
        }
        return result;
    }
private:
    bool isPali(string s) {
        if (s == "")
            return true;
            
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                i ++;
                j --;
            } else {
                return false;
            }
        }
        return true;
    }
};
