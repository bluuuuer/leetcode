/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if (!root)
            return res;
        
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        
        while (!q1.empty()) {
            q2.swap(q1);
            vector<int> temp_res;
            while (!q2.empty()) {
                TreeNode* p = q2.front();
                if (p->left)
                    q1.push(p->left);
                if (p->right)
                    q1.push(p->right);
                 temp_res.push_back(p->val); 
                q2.pop();
            }
            res.push_back(temp_res);
        }
        
        int i = 0, j = res.size() - 1;
        while (i < j) {
            vector<int> temp;
            temp.swap(res[i]);
            res[i].swap(res[j]);
            res[j].swap(temp);
            i ++;
            j --;
        }
        return res;
    }
};
