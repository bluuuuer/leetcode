/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return NULL;
           
        return insertNode(nums, 0, nums.size() - 1);
    }
    
private:
    TreeNode* insertNode(vector<int> nums, const int start, const int end) {
        if (start > end)
            return NULL;
        
        const int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        if (start <= mid - 1)
            root->left = insertNode(nums, start, mid - 1);
        if (mid + 1 <= end)
            root->right = insertNode(nums, mid + 1, end);
        return root;
    }
};
