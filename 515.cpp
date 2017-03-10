/*
You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        
        while (!q1.empty()) {
            q2.swap(q1);
            int max_val = -1e20;
            while (!q2.empty()) {
                TreeNode* p = q2.front();
                max_val = max(max_val, p->val);
                if (p->left)
                    q1.push(p->left);
                if (p->right)
                    q1.push(p->right);
                q2.pop();
            }
            res.push_back(max_val);
        }
        return res;
    }
};
