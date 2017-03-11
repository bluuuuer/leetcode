/*
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
*/

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
            
        int root_sum = calSum(root);
        
        int max_f = 0;
        for (auto it : this->m)
            max_f = max(max_f, it.second);
            
        for (auto it : this->m)
            if (it.second == max_f)
                res.push_back(it.first);
                
        return res;
    }

private:
    
    map<int, int> m;
    
    int calSum(TreeNode* root) {
        int res = 0;
        res += root->val;
        if (root->left)
            res += calSum(root->left);
        if (root->right)
            res += calSum(root->right);
            
        if (this->m.find(res) != this->m.end())
            this->m[res] ++;
        else
            this->m[res] = 1;
            
        return res;
    }
};
