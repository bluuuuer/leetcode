//Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

//An example is the root-to-leaf path 1->2->3 which represents the number 123.

//Find the total sum of all root-to-leaf numbers.

//For example,

//    1
//   / \
//  2   3
//The root-to-leaf path 1->2 represents the number 12.
//The root-to-leaf path 1->3 represents the number 13.

//Return the sum = 12 + 13 = 25.

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
    int sumNumbers(TreeNode* root) {
        return iter(root, 0);
    }
    
private:
    int iter(TreeNode* root, const int x) {
        if (!root)
            return 0;
        
        if (!root->left && !root->right) 
            return x * 10 + root->val;
        
        return iter(root->left, root->val + x * 10) + iter(root->right, root->val + x * 10);
    }
};
