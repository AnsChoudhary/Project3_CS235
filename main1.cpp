//
// Created by Ans Choudhary on 4/8/21.
//

#include "DoubleNode.hpp"
#include "DoublyLinkedList.hpp"
#include <iostream>
int main(){

    DoublyLinkedList<int> numList1;
    //numList1.display();
    numList1.insert(10,1);
    numList1.insert(12,5);
    numList1.insert(4,4);
    numList1.insert(3,6);
    numList1.insert(8,7);
    numList1.insert(2,2);
    numList1.insert(3,3);
    //numList1.display();

    DoublyLinkedList<int> charList2(numList1);
    charList2.display();


}