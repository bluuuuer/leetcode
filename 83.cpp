/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
            
        ListNode* p = head;
        ListNode* q = p;
        while (p->next) {
            q = p->next;
            if (p->val == q->val) {
                if (q->next)
                    p->next = q->next;
                else
                    p->next = NULL;
            } else
                p = q;
        }
        return head;
    }
};
