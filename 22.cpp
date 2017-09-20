/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0)
            return result;
        queue<iNode*> q;
        iNode* head = new iNode("(", 1, 0);
        q.push(head);
        while (!q.empty()) {
            iNode *node = q.front();
            if (node->left == n && node->right == n)
                result.push_back(node->s);
            else if (node->left >= node->right) {
                if (node->left < n) {
                    iNode *new_node_1 = new iNode(node->s + "(", node->left + 1, node->right);
                    q.push(new_node_1);
                }
                if (node->right < n) {
                    iNode *new_node_2 = new iNode(node->s + ")", node->left, node->right + 1);
                    q.push(new_node_2);
                }
            }
            free(node);
            q.pop();
        }
        return result;
    }
private:
    struct iNode {
        string s;
        int left;
        int right;
        iNode(string ss, int l, int r) : s(ss), left(l), right(r) {}
    };
};
