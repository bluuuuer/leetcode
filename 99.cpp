//Two elements of a binary search tree (BST) are swapped by mistake.

//Recover the tree without changing its structure.

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
    TreeNode* firstElement = NULL;
    TreeNode* secondElement = NULL;
    TreeNode* prevElement = new TreeNode(-10000000);
    
    void recoverTree(TreeNode* root) {
        
        // In order traversal to find the two elements
        traverse(root);
        
        // Swap the values of the two nodes
        int temp = firstElement->val;
        firstElement->val = secondElement->val;
        secondElement->val = temp;
    }
    
private: 

    void traverse(TreeNode* root) {
        if (root == NULL)
            return;
            
        traverse(root->left);
   
        if (firstElement == NULL && prevElement->val >= root->val) {
            firstElement = prevElement;
        }
        if (firstElement != NULL && prevElement->val >= root->val) {
            secondElement = root;
        }        
        prevElement = root;

        traverse(root->right);
    }
};
