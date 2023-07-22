#include "linkList.h"
#include <string>
#include<cstdlib>

int main() {
    LinkList<int> list;
    int size = 10;
    Node node1(1);
    Node node2(10000);
    for(int i{0}; i < size; ++i) {
        int randNum = std::rand();
        list.insert(randNum);
    }
    list.push_front(1);
    list.printList(list);
    list.push_front(10000);
    return 0;
}