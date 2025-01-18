#include <iostream>
#include <set>
#include <string>
using namespace std;
/*自定义数据类型的指定排序*/
// 指定特殊的类型
class Person {
public:
    Person(string name, int age) {
        this->m_Age = age;
        this->m_Name = name;
    }
    string m_Name;
    int m_Age;
};

// 仿函数
class MyCompare {
    public:
    bool operator()(const Person&s1, const Person&s2) {
        return s1.m_Age < s2.m_Age;
    }
};

void test() {
    set<Person, MyCompare>s;
    // 创建Person对象
    Person p1("刘备",24);
    Person p2("关羽",28);
    Person p3("张飞",25);
    Person p4("赵云",21);

    // 插入数据
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    // 只有为set指定排序规则才可以插入，所以没有仿函数是无法插入的
    for(set<Person, MyCompare>::iterator it = s.begin(); it != s.end(); it++) {
        cout << it->m_Name << " " << it->m_Age << " ";
    }
    cout << endl;
}

int main() {
    test();
    return 0;
}
    