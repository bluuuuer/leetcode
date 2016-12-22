//You are given an n x n 2D matrix representing an image.

//Rotate the image by 90 degrees (clockwise).

//Follow up:
//Could you do this in-place?

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transp(matrix);
        flip(matrix);
    }
    
private:
    
    void transp(vector<vector<int> >& matrix) {
        const int n = matrix.size();
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                matrix[i][j] = matrix[i][j] + matrix[j][i];
                matrix[j][i] = matrix[i][j] - matrix[j][i];
                matrix[i][j] -= matrix[j][i];
            }
        }
    }
    
    void flip(vector<vector<int> >& matrix) {
        const int n = matrix.size();
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n / 2; j ++) {
                matrix[i][j] = matrix[i][j] + matrix[i][n - j - 1];
                matrix[i][n - j - 1] = matrix[i][j] - matrix[i][n - j - 1];
                matrix[i][j] -= matrix[i][n - j - 1];
            }
        }
    }
};
