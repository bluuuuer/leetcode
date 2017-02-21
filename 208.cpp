/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        this->root = new TNode(' ', false);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TNode* r = this->root;
        for (int i = 0; i < word.size(); i ++) {
            const char c = word[i];
            TNode* p = new TNode(c, false);
            int j;
            for (j = 0; j < r->next.size(); j ++)
                if (r->next[j]->val == c) {
                    if (i == word.size() - 1)
                        r->next[j]->exist = true;
                    break;
                }
                        
            if (j == r->next.size()) { // 查找失败
                r->next.push_back(p);
                if (i == word.size() - 1)
                    p->exist = true;
                else
                    r = p;
            } else { // 查找成功
                delete p;
                r = r->next[j];
            }
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TNode* r = this->root;
        for (int i = 0; i < word.size(); i ++) {
            const char c = word[i];
            int j;
            for (j = 0; j < r->next.size(); j ++)
                if (r->next[j]->val == c) // 查找成功
                    break;
            if (j == r->next.size()) // 查找失败
                return false;
            else if(i == word.size() - 1) 
                return r->next[j]->exist;
            else
                r = r->next[j];
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TNode* r = this->root;
        for (int i = 0; i < prefix.size(); i ++) {
            const char c = prefix[i];
            int j;
            for (j = 0; j < r->next.size(); j ++)
                if (r->next[j]->val == c) // 查找成功
                    break;
            if (j == r->next.size()) // 查找失败
                return false;
            else if (i == prefix.size() - 1)
                return true;
            else
                r = r->next[j];
        }
    }
private:
    struct TNode{
        char val;
        bool exist;
        vector<TNode*> next;
        TNode(char c, bool b) : val(c), exist(b) {
            next.resize(0);
        }
    };
    
    TNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
