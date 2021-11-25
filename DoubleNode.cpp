#include "DoubleNode.hpp"


template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& aItem) :Next(nullptr), Prev(nullptr),
                                                         item(aItem){
    //cout << " constructor called " << endl;
}

template<class ItemType>
DoubleNode<ItemType>::~DoubleNode()
{
    //cout << "dnode destructor called" << endl;
    Next = Prev = nullptr;
}


template<class ItemType>
bool DoubleNode<ItemType>::setNext(DoubleNode<ItemType>* NextPtr) {
    Next=NextPtr;
    //cout << "SETTING NEXTPtr to " << hex << Next << "shd be " << NextPtr << endl;
    return true;
}

template<class ItemType>
bool DoubleNode<ItemType>::setPrev(DoubleNode<ItemType>* PrevPtr) {
    Prev=PrevPtr;
    // cout << "SETTING PrevPtr to " << hex << Next << "shd be " << PrevPtr << endl;
    return true;
}

template<class ItemType>
bool DoubleNode<ItemType>::setItem(ItemType& aItem){
    item=aItem;
    return true;
}
template<class ItemType>
ItemType DoubleNode<ItemType>::getItem() const {
    return item;
}

template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getNext() const {
    return Next;
}

template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getPrev() const {
    return Prev;
}





