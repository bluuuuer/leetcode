/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if (root) {
            stringstream ss;
            ss << root->val << ",";
            ss >> res;
        } else
            return res;
            
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* p = q.front();
                
            stringstream ss_l;
            string temp_l;
            if (p->left) {
                ss_l << p->left->val << ",";
                q.push(p->left);
            } else
                    ss_l << "n,";
            ss_l >> temp_l;
            res += temp_l;
                
            stringstream ss_r;
            string temp_r;
            if (p->right) {
                ss_r << p->right->val << ",";
                q.push(p->right);
            } else 
                ss_r << "n,";
            ss_r >> temp_r;
            res += temp_r;
                
            q.pop();
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = new TreeNode(0);
        if (data.length() == 0)
            return NULL;
        else {
            int pos = data.find_first_of(',');
            TreeNode* p = new TreeNode(atoi(data.substr(0, pos).data()));
            root = p;
            data = data.substr(pos + 1, data.length() - pos);
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* f = q.front();
            
            int pos = data.find_first_of(',');
            string s_l = data.substr(0, pos);
            if (s_l != "n") {
                TreeNode* l = new TreeNode(atoi(s_l.data()));
                f->left = l;
                q.push(l);
            }
            data = data.substr(pos + 1, data.length() - pos);
            
            pos = data.find_first_of(',');
            string s_r = data.substr(0, pos);
            if (s_r != "n") {
                TreeNode* r = new TreeNode(atoi(s_r.data()));
                f->right = r;
                q.push(r);
            }
            data = data.substr(pos + 1, data.length() - pos);
            
            q.pop();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
