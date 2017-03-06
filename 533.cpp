/*
Given a picture consisting of black and white pixels, and a positive integer N, find the number of black pixels located at some specific row R and column C that align with all the following rules:

Row R and column C both contain exactly N black pixels.
For all rows that have a black pixel at column C, they should be exactly the same as row R
The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

Example:
Input:                                            
[['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'W', 'B', 'W', 'B', 'W']] 

N = 3
Output: 6
Explanation: All the bold 'B' are the black pixels we need (all 'B's at column 1 and 3).
        0    1    2    3    4    5         column index                                            
0    [['W', 'B', 'W', 'B', 'B', 'W'],    
1     ['W', 'B', 'W', 'B', 'B', 'W'],    
2     ['W', 'B', 'W', 'B', 'B', 'W'],    
3     ['W', 'W', 'B', 'W', 'B', 'W']]    
row index

Take 'B' at row R = 0 and column C = 1 as an example:
Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels. 
Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row 2. They are exactly the same as row R = 0.
*/

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if (picture.size() == 0)
            return 0;
            
        int res = 0;
        for (int i = 0; i < picture[0].size(); i ++) {
            vector<char> row;
            int j;
            for (j = 0; j < picture.size(); j ++)
                if (picture[j][i] == 'B') {
                    if (compRow(row, picture[j]))
                        row = picture[j];
                    else
                        break;
                }
                
            int num_1 = 0;
            for (int k = 0; k < row.size(); k ++)
                if (row[k] == 'B')
                    num_1 ++;
                    
            int num_2 = 0;
            for (int k = 0; k < picture.size(); k ++) 
                if (picture[k][i] == 'B')
                    num_2 ++;
                    
            if (num_1 == N && num_2 == N && j == picture.size())
                res ++;
        }
        return res * N;
    }
    
private:
    bool compRow(vector<char> a, vector<char> b) {
        if (a.size() == 0)
            return true;
        for (int i = 0; i < a.size(); i ++)
            if (a[i] != b[i])
                return false;
        return true;
    }
};
