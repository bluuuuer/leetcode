//Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

//For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

class Solution {
public:
    int numSquares(int n) {
        int* m = new int[n + 1];
        memset(m, 0, (n + 1) * sizeof(int));
        int x = ns(n, m);
        delete [] m;
        return x;
    }
    
private:
    int ns(const int n, int* m) {
        const int s_n = (int)sqrt(n);
        m[s_n * s_n] = 1;
        
        if (n == s_n * s_n)
            return 1;
        
        int min = n;
        for (int i = s_n; i > 0; i --) {
            int temp_min;
            if (m[n - i * i] != 0)
                temp_min = m[n - i * i] + 1;
            else
                temp_min = ns(n - i * i, m) + 1;
            min = temp_min < min ? temp_min : min;
        }
        m[n] = min;
        //cout << "min[" << n << "] = " << min << "  " << endl;
        return min;
    }
};
