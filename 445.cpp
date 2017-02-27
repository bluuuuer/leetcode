/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        
        l1 = reList(l1);
        l2 = reList(l2);
        
        res->val = (l1->val + l2->val) % 10;
        int ten = (l1->val + l2->val) / 10;
        ListNode* add = res;
        while (l1->next || l2->next || ten) {
            ListNode* new_node = new ListNode(0);
            add->next = new_node;
            add = new_node;
            if (l1->next && l2->next) {
                l1 = l1->next;
                l2 = l2->next;
                add->val = (l1->val + l2->val + ten) % 10;
                ten = (l1->val + l2->val + ten) / 10;
            } else if (l1->next) {
                l1 = l1->next;
                add->val = (l1->val + ten) % 10;
                ten = (l1->val + ten) / 10;
            } else if (l2->next) {
                l2 = l2->next;
                add->val = (l2->val + ten) % 10;
                ten = (l2->val + ten) / 10;
            } else {
                add->val = 1;
                ten = 0;
            }
        }
        res = reList(res);
        return res;
    }

private:
    ListNode* reList(ListNode* l) {
        stack<ListNode*> s;
        while (l->next) {
            s.push(l);
            l = l->next;
        }
        ListNode* new_head = l;
        while (!s.empty()) {
            l->next = s.top();
            l = l->next;
            s.pop();
        }
        l->next = NULL;
        return new_head;
    }
};
