#include <iostream>

using namespace std;
#include <set>

void printSet(set<int>&s) {
    for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

// set 容器构造和赋值
void test1() {
    set<int>s1;
    // 插入数据只有insert方式
    s1.insert(10);s1.insert(10);s1.insert(30);s1.insert(30);s1.insert(20);
    printSet(s1);
    set<int>s2(s1);
    // 拷贝
    printSet(s2);
    // 赋值
    set<int>s3;
    s3 = s2;
    printSet(s3);
    // 交换
    set<int>s4;
    s4.insert(9);
    s4.swap(s1);
    printSet(s1);
    printSet(s4);
}

int main() {
    test1();
    
    return 0;
}