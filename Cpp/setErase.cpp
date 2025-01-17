#include <iostream>
using namespace std;
#include <set>
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
    s1.erase(s1.begin()); // 删除pos对应元素
    P(s1);s1.insert(10);
    s1.erase(10);// 删除相应数值元素
    s1.insert(10);P(s1);
    s1.erase(s1.begin(), s1.end()); // 清空，相当于clear();
    P(s1);
}

int main() {
    test();
    return 0;
}