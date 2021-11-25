//Ans Choudhary
#ifndef PROJECT3_DOUBLYLINKEDLIST_H
#define PROJECT3_DOUBLYLINKEDLIST_H

#include "DoubleNode.hpp"
#include <iostream>
using namespace std;

template<class ItemType>
class DoublyLinkedList {
private:
    DoubleNode<ItemType>* first_;
    DoubleNode<ItemType>* last_;
    size_t count;
public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<ItemType>& a_list);
    ~DoublyLinkedList();
    bool insert(const ItemType &item, const int &position);
    bool remove(const int &position);
    int getSize() const;
    bool isEmpty() const;
    void clear();
    void display() const;
    void displayBackwards() const;
    DoubleNode<ItemType>* getHeadPtr() const;
    DoubleNode<ItemType>* getAtPos(const int &pos) const;
    DoublyLinkedList<ItemType> interleave(const DoublyLinkedList<ItemType> &a_list);


};

#include "DoublyLinkedList.cpp"
#endif