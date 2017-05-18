/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        
        if (!root)
            return res;
        
        map<TreeNode*, int> degree;
        calDegree(root, degree);
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* p = q.front();
            if (p->left && p->right) {
                res = max(res, degree[p->left] + degree[p->right]);
                q.push(p->left);
                q.push(p->right);
            } else if (p->left) {
                res = max(res, degree[p->left]);
                q.push(p->left);
            } else if (p->right) {
                res = max(res, degree[p->right]);
                q.push(p->right);
            }
            q.pop();
        }
        return res;
    }
    
private:
    int calDegree(TreeNode* root, map<TreeNode*, int>& degree) {
        if (root->left == NULL && root->right == NULL) {
            degree[root] = 1;
            return 1;
        } else if (root->left == NULL) {
            degree[root] = calDegree(root->right, degree) + 1;
            return degree[root];
        } else if (root->right == NULL) {
            degree[root] = calDegree(root->left, degree) + 1;
            return degree[root];
        } else {
            degree[root] = max(calDegree(root->left, degree), calDegree(root->right, degree)) + 1;
            return degree[root];
        }
        
    }
};
