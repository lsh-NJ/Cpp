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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        /*双指针,fast指针先移动n次，后fast与slow一起移动
        直到fast->next为空结束
        如此就是slow移动了sz - n次
        slow->next就是要删除的点*/
        if (head->next == nullptr)
            return nullptr;
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *slow = dummyHead, *fast = dummyHead;
        while (n--)
        {
            fast = fast->next;
        }
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // 删除slow后面的节点
        ListNode *tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        // delete dummyHead;
        return dummyHead->next;
    }
};