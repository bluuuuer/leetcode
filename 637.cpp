/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> q1, q2;
        q1.push(root);
        bool f = true;
        double v = 0.0;
        int num = 0;
        while (!q1.empty() || !q2.empty()) {
            if (f) {
                TreeNode* p = q1.front();
                v += p->val;
                num ++;
                if (p->left)
                    q2.push(p->left);
                if (p->right)
                    q2.push(p->right);
                q1.pop();
                if (q1.empty()) {
                    result.push_back(v / (double)num);
                    v = 0.0;
                    num = 0;
                    f = false;
                }
            } else {
                TreeNode* p = q2.front();
                v += p->val;
                num ++;
                if (p->left)
                    q1.push(p->left);
                if (p->right)
                    q1.push(p->right);
                q2.pop();
                if (q2.empty()) {
                    result.push_back(v / (double)num);
                    v = 0.0;
                    num = 0;
                    f = true;
                }
            }
        }
        return result;
    }
};
