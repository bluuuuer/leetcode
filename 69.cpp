/*
mplement int sqrt(int x).

Compute and return the square root of x.
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int left = 1;
        int right = 47000;
        while (1) {
            int mid = left + (right - left) / 2;
            if (mid > x / mid)
                right = mid - 1;
            else {
                if (mid + 1 > x / (mid + 1))
                    return mid;
                left = mid + 1;
            }
        }
    }
};
