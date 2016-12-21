//Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

//According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

//For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

//Note: If there are several possible values for h, the maximum one is taken as the h-index.

class Solution {
public:
    struct Node {
        int val = -1;
        Node* next = NULL;
    };
    
    int Insert(Node* head, const int v) {
        int count = 0;
        Node* q = new Node;
        q->val = v;
        
        if (head->next == NULL) {
            head->next = q;
        } else {
            Node* p = head;
            while (p->next->val >= v) {
                if (p->next->next == NULL) {
                    p->next->next = q;
                    break;
                }
                count ++;
                p = p->next;
            }
            if (p->next->val < v) {
                q->next = p->next;
                p->next = q;
            }
        }
        
        count ++;
        return count;
    }
    
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0)
            return 0;
            
        Node* head = new Node;
        int a = 0;
        
        for (int i = 0; i < citations.size(); i ++) {
            if (citations[i] < a)
                continue;
            
            const int count = Insert(head, citations[i]);
            if (count > citations[i])
                a = citations[i];
        }
        
        Node* p = head;
        int count = 1;
        while(p->next!= NULL && p->next->val >= count) {
            p = p->next;
            count ++;
        }
        return count - 1;
    }
};
