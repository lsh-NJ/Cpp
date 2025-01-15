/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr, *cur = head;
        ListNode* tmp;
        while(cur) {
            tmp1 = cur;
            tmp2 = pre;
            pre = cur;
            cur = cur->next;
            tmp1->next = tmp2;
        }
        return pre;
    }
};