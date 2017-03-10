/*
Given a binary tree, find the leftmost value in the last row of the tree. 
Example 1:
Input:

    2
   / \
  1   3

Output:
1

Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7

Note: You may assume the tree (i.e., the given root node) is not NULL.
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
    int findBottomLeftValue(TreeNode* root) {
        int res;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        
        while (!q1.empty()) {
            q2.swap(q1);
            res = q2.front()->val;
            while (!q2.empty()) {
                TreeNode* p = q2.front();
                if (p->left)
                    q1.push(p->left);
                if (p->right)
                    q1.push(p->right);
                q2.pop();
            }
        }
        return res;
    }
};
