/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0)
            return 0;
            
        vector<vector<bool> > visit;
        for (int i = 0; i < grid.size(); i ++) {
            vector<bool> temp_v(grid[i].size(), false);
            visit.push_back(temp_v);
        }
        
        int res = 0;
        stack<pair<int, int> > s;
        for (int i = 0; i < grid.size(); i ++)
            for (int j = 0; j < grid[i].size(); j ++)
                if (grid[i][j] == '1' && !visit[i][j]) {
                    res ++;
                    s.push(make_pair(i, j));
                    visit[i][j] = true;
                    while (!s.empty()) {
                        int ii = s.top().first;
                        int jj = s.top().second;
                        s.pop();
                        if (ii > 0 && grid[ii - 1][jj] == '1' && !visit[ii - 1][jj]) {
                            s.push(make_pair(ii - 1, jj));
                            visit[ii - 1][jj] = true;
                        }
                        if (ii + 1 < grid.size() && grid[ii + 1][jj] == '1' && !visit[ii + 1][jj]) {
                            s.push(make_pair(ii + 1, jj));
                            visit[ii + 1][jj] = true;
                        }
                        if (jj > 0 && grid[ii][jj - 1] == '1' && !visit[ii][jj - 1]) {
                            s.push(make_pair(ii, jj - 1));
                            visit[ii][jj - 1] = true;
                        }
                        if (jj + 1 < grid[ii].size() && grid[ii][jj + 1] == '1' && !visit[ii][jj + 1]) {
                            s.push(make_pair(ii, jj + 1));
                            visit[ii][jj + 1] = true;
                        }
                    }
                }
        
        return res;
    }
};
