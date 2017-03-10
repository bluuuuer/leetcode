/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        if (numRows < 1)
            return res;
        vector<int> f_row;
        for (int i = 0; i < numRows; i ++) {
            vector<int> row;
            if (i == 0)
                row.push_back(1);
            else if (i == 1) {
                row.push_back(1);
                row.push_back(1);
                f_row = row;
            } else {
                row.push_back(1);
                for (int j = 1; j < i; j ++) {
                    row.push_back(f_row[j - 1] + f_row[j]);
                }
                row.push_back(1);
                f_row = row;
            }
            res.push_back(row);
        }
        return res;
    }
};
