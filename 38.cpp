//The count-and-say sequence is the sequence of integers beginning as follows:
//1, 11, 21, 1211, 111221, ...

//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//Given an integer n, generate the nth sequence.

//Note: The sequence of integers will be represented as a string.

class Solution {
public:
    string countAndSay(int n) {
        string num = "1";
        for (int i = 0; i < n - 1; i ++) {
            num = extend(num);
        }
        return num;
    }
    
private:
    string extend(const string num) {
        if (num.length() == 1)
            return "1" + num;
            
        string result = "";
        int i = 0;
        int j = i + 1;
        while (j < num.length()) {
            if (num[i] == num[j] && j < num.length() - 1)
                j ++;
            else if (num[i] == num[j]){
                result += to_string(j - i + 1) + num[i];
                break;
            } else {
                result += to_string(j - i) + num[i];
                i = j;
                j = i;
            }
        }
        return result;
    }
};
