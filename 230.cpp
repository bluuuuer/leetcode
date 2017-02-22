/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* smallest = root;
        while (smallest->left) {
            this->s.push(smallest);
            smallest = smallest->left;
        }
        for (int i = 2; i <= k; i ++)
            smallest = findNext(smallest);
        return smallest->val;
    }

private:
    stack<TreeNode*> s;
    
    TreeNode* findNext(TreeNode* root) {
        TreeNode* p = root;
        if (!this->s.empty()){
            if (p->right) {
                this->s.push(p);
                p = p->right;
                while (p->left) {
                    this->s.push(p);
                    p = p->left;
                }
                return p;
            } else {
                TreeNode* f = this->s.top();
                while (f->right == p) {
                    p = f;
                    this->s.pop();
                    f = this->s.top();
                }
                this->s.pop();
                return f;
            }
        } else {
            if (p->right) {
                this->s.push(p);
                p = p->right;
                while (p->left) {
                    this->s.push(p);
                    p = p->left;
                }
                return p;
            }
            return p;
        }
    }
};
