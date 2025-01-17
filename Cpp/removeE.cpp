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
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // 使用虚拟头节点,使得删除头节点是一样的操作
        ListNode *dummyhead, *p; // p用来遍历链表
        // 一个很重要的步骤：为虚拟头节点分配内存
        dummyhead = new ListNode();
        dummyhead->next = head;
        // 实际上删除的是p->next,所以p要从虚拟头节点开始
        p = dummyhead;
        while (p->next)
        {
            // 找到要删除的元素,并要考虑漏删
            if (p->next->val == val)
            {
                ListNode *tmp = p->next;
                p->next = p->next->next;
                delete tmp;
            }
            else
            {
                p = p->next;
            }
        }
        return dummyhead->next;
    }
};