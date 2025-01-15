// 我的错误揭解法
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
        ListNode* cur, *dummyHead, *tmp1 = nullptr, *tmp2 = nullptr;
        dummyHead = new ListNode(0);
        dummyHead->next;
        cur = dummyHead;
        while(cur) {
            tmp2->next = tmp1;
            tmp1 = cur;
            cur = cur->next;
            tmp2 = cur;
        }
        //tmp2->next = tmp1;
        head->next = nullptr;
        delete dummyHead;
        dummyHead = nullptr;

        return cur;
    }
};