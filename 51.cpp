/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > res;
        string temp = "";
        for (int i = 0; i < n; i ++)
            temp.push_back('a');
        vector<string> v(n, temp);
        res.push_back(v);
        
        res = solveNQ(res[0]);
        return res;
    }

private:
    vector<vector<string> > solveNQ(vector<string> board) {
        vector<vector<string> > res;
        for (int i = 0; i < board.size(); ) {
            if (board[i].find('Q') != string::npos) {
                if (i == board.size() - 1) {
                    res.push_back(board);
                    return res;
                }
                else
                    i ++;
            }
            else {
                for (int j = 0; j < board[i].length(); j ++)
                    if (board[i][j] == 'a') {
                        vector<string> new_b = board;
                        for (int m = i; m < new_b.size(); m ++)
                            for (int n = 0; n < new_b[m].length(); n ++) {
                                if (m == i)
                                    new_b[m][n] = (n == j) ? 'Q' : '.';
                                else if (n == j || abs(m - i) == abs(n - j))
                                    new_b[m][n] = '.';
                            }
                        
                        vector<vector<string> > new_board = solveNQ(new_b);
                        res.insert(res.end(), new_board.begin(), new_board.end());
                    }
                return res;
            }
        }
    }
};
