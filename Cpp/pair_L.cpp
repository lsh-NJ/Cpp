#include <iostream>
using namespace std;

test() {
    pair<string, int>p("Tom", 20);
    cout << "姓名： " << p.first << " 年龄： " << p.second << endl;

    pair<string, int>p2 = make_pair("Jerry", 30);
    cout << "姓名： " << p2.first << " 年龄： " << p2.second << endl;
}

int main() {
    test();
    return 0;
}