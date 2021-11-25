#include "DoublyLinkedList.hpp"
#include "DoubleNode.hpp"
int main() {



    int data1[5] = {4, 2, 8, 5, 8};

    int data2[6] = {5, 1, 8, 4, 5, 9};

    DoublyLinkedList<int> list1, list2;

    for (int i = 0; i < 5; i++) {
        list1.insert(data1[i], i + 1);
    }

    for (int i = 0; i < 6; i++) {
        list2.insert(data2[i], i + 1);
    }

    DoublyLinkedList<int> list3 = list1.interleave(list2);
    //list3.display(); //4 5 2 1 8 8 5 4 8 5 9
    //list1.display();
    //list1.clear();
    //list1.display();



    return 0;
}