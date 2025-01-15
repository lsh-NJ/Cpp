#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> lst;

    lst.push_back(10);
    lst.push_front(20);

    // 构造迭代器：
    list<int>::iterator it;
    for(it = lst.begin(); it != lst.end(); it++)
        cout << *it << " ";
    cout << endl;
}