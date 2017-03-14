/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return head;
            
        ListNode* o = head;
        ListNode* e_h = head->next;
        ListNode* e = e_h;
        ListNode* p = e->next;
        bool odd = true;
        while (p) {
            if (odd) {
                o->next = p;
                o = p;
                odd = false;
                p = p->next;
            } else {
                e->next = p;
                e = p;
                odd = true;
                p = p->next;
                e->next = NULL;
            }
        }
        o->next = e_h;
        
        return head;
    }
};
