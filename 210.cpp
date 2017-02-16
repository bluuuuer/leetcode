// There are a total of n courses you have to take, labeled from 0 to n - 1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

// There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

// For example:

// 2, [[1,0]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

// 4, [[1,0],[2,0],[3,1],[3,2]]
// There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

// Note:
// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// You may assume that there are no duplicate edges in the input prerequisites.

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> result;
        result.resize(0);
        
        vector<bool> visit, takable;
        for (int i = 0; i < numCourses; i ++) {
            visit.push_back(false);
        }
        takable.resize(numCourses);
        
        while (result.size() != numCourses) {
            int b_num = result.size();
            
            for (int i = 0; i < numCourses; i ++)
                takable[i] = true;
                
            for (int i = 0; i < prerequisites.size(); i ++)
                takable[prerequisites[i].first] = false;
            
            for (int i = 0; i < numCourses; i ++) {
                if (!visit[i] && takable[i]) {
                    for (int j = 0; j < prerequisites.size(); j ++)
                        if (prerequisites[j].second == i) {
                            prerequisites.erase(prerequisites.begin() + j);
                            j --;
                        }
                        
                    visit[i] = true;
                    result.push_back(i);
                }
            }
            
            if (result.size() == b_num) {
                vector<int> re;
                return re;
            }
        }

        return result;
    }
};
