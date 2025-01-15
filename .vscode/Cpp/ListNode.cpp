/*
设计链表
*/
class MyLinkedList{
public:
    // 初始化链表
    MyLinkedList() {
        // 定义一个虚拟头节点
        _dummyHead = new ListNode(0);
        _size = 0;
    }

    // 获取链表第index个节点的数值
    int get(int index) {
        // 判断合法性
        if(index < 0 || index > (_size - 1)) {
            return -1;
        }
        ListNode *cur = _dummyHead->next;
        while(index) {
            cur = cur->next;
            index--;
        }
        return cur->val;
    }

    // 插入头节点
    void addAtHead(int val) {
        // 为新节点开辟空间
        ListNode* newNode = new ListNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    // 插入尾节点
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyHead;
        while(cur->next) {
            cur->next = cur->next->next;
        }
        cur->next = newNode;
        // 注意链表数量变化！
        _size++;
    }

    // 在链表第index个节点前面插入一个节点
    void addAtIndex(int index, int val) {
        if(index > _size) return;
        if(index < 0) index = 0;
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyHead;
        while(index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    // 删除第index个节点,>=size返回空
    void deleteAtIndex(int index) {
        if(index >= _size) {
            return;
        }
        LinkedNode* cur = _dummyHead;
        while(index--) {
            cur = cur->next;
        }
        // 不记录要删除的点就会使点的地址消失
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        // tmp之后会变成指向随机的野指针，所以要使他成为空指针
        tmp = nullptr;
        _size--;
    }

private:
    int _size;
    ListNode* _dummyHead;
}