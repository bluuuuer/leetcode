/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            vector<TreeNode*> res;
            return res;
        }
        return genTrees(1, n);
    }

private:
    vector<TreeNode*> genTrees(const int start, const int end) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(NULL);
            return res;
        }
        //if (start == end) {
            //TreeNode* p = new TreeNode(start);
            //res.push_back(p);
            //return res;
        //}
        for (int i = start; i <= end; i ++) {
            vector<TreeNode*> left_trees = genTrees(start, i - 1);
            vector<TreeNode*> right_trees = genTrees(i + 1, end);
            for (int j = 0; j < left_trees.size(); j ++) {
                for (int k = 0; k < right_trees.size(); k ++) {
                    TreeNode* p = new TreeNode(i);
                    p->left = left_trees[j];
                    p->right = right_trees[k];
                    res.push_back(p);
                }
            }
        }
        return res;
    }
};
