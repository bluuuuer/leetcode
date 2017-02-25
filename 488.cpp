/*
Think about Zuma Game. You have a row of balls on the table, colored red(R), yellow(Y), blue(B), green(G), and white(W). You also have several balls in your hand.

Each time, you may choose a ball in your hand, and insert it into the row (including the leftmost place and rightmost place). Then, if there is a group of 3 or more balls in the same color touching, remove these balls. Keep doing this until no more balls can be removed.

Find the minimal balls you have to insert to remove all the balls on the table. If you cannot remove all the balls, output -1.

Examples:

Input: "WRRBBW", "RB"
Output: -1
Explanation: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW

Input: "WWRRBBWW", "WRBRW"
Output: 2
Explanation: WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW -> WWWW -> empty

Input:"G", "GGGGG"
Output: 2
Explanation: G -> G[G] -> GG[G] -> empty 

Input: "RBYYBBRRB", "YRBGB"
Output: 3
Explanation: RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> RRRB -> B -> B[B] -> BB[B] -> empty 

Note:
You may assume that the initial row of balls on the table won’t have any 3 or more consecutive balls with the same color.
The number of balls on the table won't exceed 20, and the string represents these balls is called "board" in the input.
The number of balls in your hand won't exceed 5, and the string represents these balls is called "hand" in the input.
Both input strings will be non-empty and only contain characters 'R','Y','B','G','W'.
*/

class Solution {
public:
    int findMinStep(string board, string hand) {
        tNode* root = Init(board, hand);
        if (!Check(root))
            return -1;
            
        queue<tNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            tNode* p = q.front();
            vector<tNode*> childs = genNode(p);
            for (int i = 0; i < childs.size(); i ++) {
                if (childs[i]->board.size() == 0)
                    return childs[i]->height;
                else 
                    q.push(childs[i]);
            }
            q.pop();
        }
        return -1;
    }

private:
    struct tNode {
        string board;
        map<char, int> hand;
        int height;
        tNode(string b, map<char, int> h, int val) : board(b), hand(h), height(val) {}
    };
    
    string Clean(string board) {
        for (int i = 0; i < (int)board.length() - 2; i ++) {
            int j = i + 1;
            if (board[j + 1] == board[j] && board[j] == board[i]) {
                j ++;
                while (j + 1 < board.length() && board[j + 1] == board[j] && board[j] == board[i])
                    j ++;
                board.erase(board.begin() + i, board.begin() + j + 1);
                return Clean(board);
            }
        }
        return board;
    }
    
    bool Check(tNode* p) {
        map<char, int> red;
        for (int i = 0; i < p->board.length(); i ++) {
            const char c = p->board[i];
            if (red.find(c) == red.end())
                red[c] = 1;
            else
                red[c] ++;
        }
        map<char, int>::iterator it = red.begin();
        while (it != red.end()) {
            const char c = it->first;
            if (p->hand.find(c) == p->hand.end() && it->second < 3)
                return false;
            if (p->hand.find(c) != p->hand.end() && p->hand[c] + it->second < 3)
                return false;
            it ++;
        }
        return true;
    }
    
    vector<tNode*> genNode(tNode* root) {
        vector<tNode*> res;
        for (int i = 0; i <= root->board.length(); i ++) {
            map<char, int>::iterator it = root->hand.begin();
            while (it != root->hand.end()) {
                string b = root->board;
                const char c = it->first;
                if (c == b[i] && it->second != 0) {
                    b.insert(b.begin() + i, c);
                    b = Clean(b);
                    map<char, int> h(root->hand);
                    h[c] --;
                    tNode* new_node = new tNode(b, h, root->height + 1);
                    if (Check(new_node))
                        res.push_back(new_node);
                }
                it ++;
            }
        }
        return res;
    }
    
    tNode* Init(string board, string hand) {
        map<char, int> h;
        for (int i = 0; i < hand.size(); i ++) {
            const char c = hand[i];
            if (h.find(c) == h.end() && board.find(c) != string::npos) 
                h[c] = 1;
            else
                h[c] ++;
        }
        
        tNode* root = new tNode(board, h, 0);
        return root;
    }
};
