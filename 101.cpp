//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

//For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

//    1
//   / \
//  2   2
// / \ / \
//3  4 4  3
//But the following [1,2,2,null,3,null,3] is not:
//    1
//   / \
//  2   2
//   \   \
//   3    3

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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
            
        //ShowLevel(root);
        
        if (root->left == NULL && root->right == NULL) 
            return true;
            
        if (root->left != NULL && root->right != NULL) {
            Reverse(root->left);
            //ShowLevel(root);
            return isSame(root->left, root->right);
        }
            
        return false;
    }
private:
    void ShowLevel(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* p = q.front();
            ShowNode(p);
            q.pop();
            if (p)
                EnQueue(&q, p);
        }
        printf("\n");
    }
    
    void ShowNode(TreeNode* p) {
        if (p)
            printf("%d ", p->val);
        else
            printf("null ");
    }
    
    void EnQueue(queue<TreeNode*>* q, TreeNode* root) {
        q->push(root->left);
        q->push(root->right);
    }
    
    void Reverse(TreeNode* a) {
        TreeNode* p = a->left;
        a->left = a->right;
        a->right = p;
        
        if (a->left)
            Reverse(a->left);
        if (a->right)
            Reverse(a->right);
    }
    
    bool isSame(TreeNode* a, TreeNode* b){
       // ShowLevel(a);
        //ShowLevel(b);
        if (a->val != b->val)
            return false;
            
        if ((a->left == NULL && b->left) || (a->left && b->left == NULL) || (a->right == NULL && b->right) || (a->right && b->right == NULL))
            return false;
        else if (a->left == NULL && b->left == NULL && a->right && b->right)
            return isSame(a->right, b->right);
        else if (a->left && b->left && a->right == NULL && b->right == NULL)
            return isSame(a->left, b->left);
        else if (a->left == NULL && b->left == NULL && a->right == NULL && b->right == NULL)
            return true;
        else
            return (isSame(a->left, b->left) && isSame(a->right, b->right));
    }
    
};
