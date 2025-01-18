#include <iostream>
using namespace std;
#include <set>
class MyCompare {
public:
    // 第一个括号中是“要重载的符号”，第二个括号是函数体的参数列表
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};
void P(set<int> &s) {
    for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test() {
    set<int>s1;
    s1.insert(10);s1.insert(40);s1.insert(30);s1.insert(20);
    P(s1);
    // 在插入数据之前指定排序规则为从大到小
    set<int, MyCompare>s2;
    s2.insert(10);s2.insert(40);s2.insert(30);s2.insert(20);
    for(set<int>::iterator it = s2.begin(); it != s2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    test();
    return 0;
}