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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        /*判断终止有两种情况：
        要么是cur->next == NULL
        要么是cur->next->next == NULL
        这里要注意前后顺序，容易产生空指针异常*/
        while(cur->next && cur->next->next) {
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            tmp->next = cur->next->next;
            cur->next->next = tmp;
            cur = cur->next->next;
        }
        return dummyHead->next;
    }
};