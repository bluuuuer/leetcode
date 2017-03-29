/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0)
            return 0;
        if (triangle.size() == 1)
            return triangle[0][0];
            
        const int N = triangle.size();
        cout << "N = " << N << endl;
        
        vector<vector<int> > pos(triangle);
        for (int i = 0; i < triangle[N - 1].size(); i ++)
            pos[N - 1][i] = triangle[N - 1][i];
            
        for (int i = N - 2; i >= 0; i --)
            for (int j = 0; j < pos[i].size(); j ++)
                pos[i][j] = triangle[i][j] + min(pos[i + 1][j], pos[i + 1][j + 1]);
                    
        return pos[0][0];
    }
};
