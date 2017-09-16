/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL && n == 1) {
            return NULL;
        }
        
        ListNode* p = head;
        ListNode* q = p;
        for (int i = 0; i < n - 1; i ++) {
            q = q->next;
        }       
        
        ListNode *temp = p;
        while (q->next != NULL) {
            temp = p;
            p = p->next;
            q = q->next;
        }
        
        if (p == head) {
            head = head->next;   
        } else {
            temp->next = p->next;
            free(p);
        }
        return head;
    }
};
