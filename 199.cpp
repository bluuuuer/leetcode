/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        queue<TreeNode*> q_1;
        queue<TreeNode*> q_2;
        q_2.push(root);
        while (!q_2.empty()) {
            q_1.swap(q_2);
            TreeNode* p;
            while (!q_1.empty()) {
                p = q_1.front();
                if (p->left)
                    q_2.push(p->left);
                if (p->right)
                    q_2.push(p->right);
                q_1.pop();
            }
            res.push_back(p->val);
        }
        return res;
    }
};
