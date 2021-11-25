//Ans Choudhary
#ifndef PROJECT3_DOUBLENODE_H
#define PROJECT3_DOUBLENODE_H

template <class ItemType>
class DoubleNode {
private:
    ItemType item; // the data
    DoubleNode<ItemType>* Next;
    DoubleNode<ItemType>* Prev;
public:
    DoubleNode();
    DoubleNode(const ItemType& aItem);
    ~DoubleNode();
    bool setNext(DoubleNode<ItemType>* NextPtr);
    bool setPrev(DoubleNode<ItemType>* PrevPtr);
    bool setItem(ItemType& aItem);
    DoubleNode<ItemType>* getNext() const;
    DoubleNode<ItemType>* getPrev() const;
    ItemType getItem() const;

};

#include "DoubleNode.cpp"
#endif