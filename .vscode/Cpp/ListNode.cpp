/*
设计链表
*/
class MyLinkedList{
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        // 构造函数
        LinkedNode(int val):val(val), next(nullptr){}
    }

    // 初始化链表
    MyLinkedList() {
        // 定义一个虚拟头节点
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }

    // 获取链表第index个节点的数值
    int get(int index) {
        // 判断合法性
        if(index < 0 || index > (_size - 1)) {
            return -1;
        }
        LinkedNode *cur = _dummyHead->next;
        while(index) {
            cur = cur->next;
            index--;
        }
        return cur->val;
    }

    // 插入头节点
    void addAtHead(int val) {
        // 为新节点开辟空间
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    // 插入尾节点
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead->next;
        while(cur->next) {
            cur->next = cur->next->next;
        }
        cur->next = newNode;
        // 注意链表数量变化！
        _size++;
    }

    // 在链表第index个节点前面插入一个节点
    void addAtIndex(int index, int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead->next;
        /*需要对index进行讨论：
        1.<=0就是头插
        2.==size就是尾插
        3.>size返回空*/ 
        if(index <= 0) {
            newNode->next = _dummyHead->next
        } else if(index == _size) {
            while(cur->next) {
                cur->next = cur->next->next;
            }
            cur->next = newNode;
        } else if(index > _size) {
            return ;
        } else {
            while(index--){
                // 注意这里是插在前面
                cur->next = cur->next->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
        }
        _size++;
    }
private:
    int _size;
    LinkedNode* _dummyHead;
}