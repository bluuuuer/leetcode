/*
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).

 Buildings Skyline Contour
The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:

The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
Credits:
*/

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int> > res;
        if (buildings.size() == 0)
            return res;
        
        list<pair<int, pair<int, int> > > h_x1_x2;
        for (int i = 0; i < buildings.size(); i ++)
            h_x1_x2.push_back(make_pair(buildings[i][2], make_pair(buildings[i][0], buildings[i][1])));
        
        h_x1_x2.sort(my_sort);
        
        vector<pair<int, int> > x1_x2;
        list<pair<int, pair<int, int> > >::iterator it = h_x1_x2.begin();
        while (it != h_x1_x2.end()) {
            const int x1 = (*it).second.first;
            const int x2 = (*it).second.second;
            if (x1_x2.size() == 0)
                res.push_back(make_pair(x1, (*it).first));
            for (int i = 0; i < x1_x2.size(); i ++) {
                if (x1 < x1_x2[i].first && x2 > x1_x2[i].second) { // 包含
                    res.push_back(make_pair(x1, (*it).first));
                    res.push_back(make_pair(x1_x2[i].second, (*it).first));
                    i ++;
                    while (i < x1_x2.size()) {
                        if (x1_x2[i].second < x2)
                            res.push_back(make_pair(x1_x2[i].second, (*it).first));
                        i ++;
                    }
                    break;
                }
                if (x1 >= x1_x2[i].first && x2 <= x1_x2[i].second) // 被包含
                    break;
                if (x1 < x1_x2[i].first && x2 <= x1_x2[i].second) { // 左边有重合
                    res.push_back(make_pair(x1, (*it).first));
                    break;
                }
                if (x1 <= x1_x2[i].second && x2 > x1_x2[i].second) { // 右边有重合
                    res.push_back(make_pair(x1_x2[i].second, (*it).first));
                    i ++;
                    while (i < x1_x2.size()) {
                        if (x1_x2[i].second < x2)
                            res.push_back(make_pair(x1_x2[i].second, (*it).first));
                        i ++;
                    }
                    break;
                } else if (i == x1_x2.size() - 1) { // 无重合
                    res.push_back(make_pair(x1, (*it).first));
                }
            }
                
            Add(x1, x2, x1_x2);
            resSort(x1_x2, 0, x1_x2.size() - 1);
            it ++;
        }
        for (int i = 0; i < x1_x2.size(); i ++)
            res.push_back(make_pair(x1_x2[i].second, 0));
        resSort(res, 0, res.size() - 1);
        resSort_1(res);
        resDel(res);
        return res;
    }
    
private:
    void resSort_1(vector<pair<int, int> >& res) {
        for (int i = 0; i < res.size() - 1; i ++)
            if (res[i].first == res[i + 1].first && res[i].second > res[i + 1].second) {
                int x = res[i].second;
                res[i].second = res[i + 1].second;
                res[i + 1].second = x;
            }
    }
    
    void resDel(vector<pair<int, int> >& res) {
        for (int i = 0; i < res.size() - 1; i ++) {
            if (res[i].second == res[i + 1].second) {
                res.erase(res.begin() + i + 1);
                i --;
            }
            if (res[i].first == res[i + 1].first) {
                if (res[i].second < res[i + 1].second)
                    res.erase(res.begin() + i  + 1);
                else
                    res.erase(res.begin() + i);
                i --;
            }
        }
    }
       
    void resSort(vector<pair<int, int> >& res, int start, int end) {
        //cout << "resSort(" << start << ", " << end << ")" << endl;
        if (start >= end)
            return;
        int first = start;
        int last = end;
        
        pair<int, int> key = res[first];
        while (first < last) {
            while (first < last && res[last].first >= key.first)
                last --;
            res[first] = res[last];
            while (first < last && res[first].first <= key.first)
                first ++;
            res[last] = res[first];
        } 
        res[first] = key;
        resSort(res, start, first - 1);
        resSort(res, first + 1, end);
    }
    
    void Add(const int x1, const int x2, vector<pair<int, int> >& x1_x2) {
        if (x1_x2.size() == 0)
            x1_x2.push_back(make_pair(x1, x2));
        for (int i = 0; i < x1_x2.size(); i ++) {
            if (x2 < x1_x2[i].first && i < x1_x2.size() - 1)  // 左边不重合
                continue;                                     //
            else if (x2 < x1_x2[i].first)                     //
                x1_x2.push_back(make_pair(x1, x2));           //
            else if (x1 > x1_x2[i].second && i < x1_x2.size() - 1) // 右边不重合
                continue;                                          //
            else if (x1 > x1_x2[i].second)                         //
                x1_x2.push_back(make_pair(x1, x2));                //
            else if (x1 < x1_x2[i].first && x2 <= x1_x2[i].second) { // 左边重合
                const int temp_x = x1_x2[i].second;
                x1_x2.erase(x1_x2.begin() + i);
                Add(x1, temp_x, x1_x2);
                return;
            } else if (x1 >= x1_x2[i].first && x2 > x1_x2[i].second) { // 右边重合
                const int temp_x = x1_x2[i].first;
                x1_x2.erase(x1_x2.begin() + i);
                Add(temp_x, x2, x1_x2);
            } else if (x1 < x1_x2[i].first && x2 > x1_x2[i].second) { // 包含
                x1_x2.erase(x1_x2.begin() + i);
                Add(x1, x2, x1_x2);
            } else { // 被包含
                break;
            }
        } 
    }
    
    static bool my_sort(pair<int, pair<int, int> >& l1, pair<int, pair<int, int> >& l2) {
        return (l1.first > l2.first);
    }
};
