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
        return reverse(head, nullptr);
    }
    /*写递归先考虑终止条件，当指针为空时就结束，结束时返回新的头节点指针
    */
    ListNode* reverse(ListNode* cur, ListNode* pre) {
        if(cur == nullptr) return pre;// 终止条件
        else {
            ListNode* tmp = cur->next;// 存储cur的下一节点，方便后移动
            cur->next = pre;          // 反转
            return reverse(tmp, cur);        // 进入下一层递归的同时将指针后移
        }
    }
};