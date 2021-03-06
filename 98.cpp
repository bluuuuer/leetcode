/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
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
    bool isValidBST(TreeNode* root) {
        vector<int> visit = LMR(root);
        for (int i = 0; i < (int)visit.size() - 1; i ++)
            if (visit[i] >= visit[i + 1])
                return false;
        return true;
    }

private:
    vector<int> LMR(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;
        vector<int> v_left = LMR(root->left);
        res.insert(res.end(), v_left.begin(), v_left.end());
        res.push_back(root->val);
        vector<int> v_right = LMR(root->right);
        res.insert(res.end(), v_right.begin(), v_right.end());
        return res;
    }
};
