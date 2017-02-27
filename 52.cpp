/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/

class Solution {
public:
    int totalNQueens(int n) {
        string temp = "";
        for (int i = 0; i < n; i ++)
            temp.push_back('a');
        vector<string> board(n, temp);
        int res = solveNQ(board);
        return res;
    }

private:
    int solveNQ(vector<string> board) {
        int res = 0;
        for (int i = 0; i < board.size(); ) {
            if (board[i].find('Q') != string::npos) // i'th layer filled
                i ++;
            else {
                if (i == board.size() - 1) {
                    int temp_res = 0;
                    for (int j = 0; j < board[i].length(); j ++)
                        if (board[i][j] == 'a')
                            temp_res ++;
                    return temp_res;
                } else {
                    for (int j = 0; j < board[i].length(); j ++) {
                        if (board[i][j] == 'a') {
                            vector<string> new_b = board;
                            for (int m = i; m < new_b.size(); m ++)
                                for (int n = 0; n < new_b[m].length(); n ++) {
                                    if (m == i)
                                        new_b[m][n] = (n == j) ? 'Q' : '.';
                                    else if (n == j || abs(m - i) == abs(n - j))
                                        new_b[m][n] = '.';
                                }
                            
                            res += solveNQ(new_b);
                        }
                    }
                    return res;
                }
            }
        }
    }
};
