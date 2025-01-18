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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;
        ListNode* i = headA, *j = headB;
        // 让长度记录从一开始，方便以后判断焦点
        int countA = 1, countB = 1;
        // 记录长度并判断是否有交点
        while(i->next) {
            i = i->next;
            countA++;
        }
        while(j->next) {
            j = j->next;
            countB++;
        }
        if(i != j) return NULL;
        // 通过长度来同步寻找交点
        i = headA, j = headB;
        int n = countA - countB;
        if(countA >= countB) return research(i, j, n);
        else return research(j, i, -n);
        
    }

    ListNode* research(ListNode* i, ListNode* j, int n) {
        while(n--) {i = i->next;}
        while(i && j) {
            if(i == j) return i;
            else {
                i = i->next;
                j = j->next;
            }
        }
        return NULL;
    }
};