#include <iostream>

#include "DoublyLinkedList.hpp"

using namespace std;

template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(): first_(nullptr), last_(nullptr), count(0){
    // cout << "dllist default constructor called" << endl;
}

template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType> &a_list) {
    // cout << "Copy Constructor" << endl;
    first_ = nullptr;
    last_ = nullptr;
    count  = 0;
    int c1= a_list.count;
    for (int i = 1; i <= c1; i++)
    {
        // cout << "Insert at pos " << i << " a_list.count " << c1 << " this->count = " << count << endl;
        insert(a_list.getAtPos(i)->getItem(), i);
    }
}

template<class ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList<ItemType>() {
    //cout << "dllist destructor called" << endl;
    clear();
}


template<class ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType &item, const int &position) {

    if (position <= 0)
        return false;

    DoubleNode<ItemType>* new_node_ptr = new DoubleNode<ItemType>(item);

    //new_node_ptr->display();
    if (position == 1) {
        //cout << "--- Inserting at the head" << endl;
        if (first_ != nullptr) {

            new_node_ptr->setPrev(first_->getPrev());
            new_node_ptr->setNext(first_);
            first_->setPrev(new_node_ptr);
            first_ = new_node_ptr;
        }
        else {  //case if list is null/empty
            first_ = new_node_ptr;
            last_ = new_node_ptr;
        }
        //cout << "first element " << endl;
        // first_->display();
    }
    else if (position > count)// inserting in end of list
    {

        last_->setNext(new_node_ptr);
        new_node_ptr->setPrev(last_);
        last_ = new_node_ptr;
    }
    else // position <= count  // inserting in middle of list
    {


        DoubleNode<ItemType> * insertPosNode = getAtPos(position);

        DoubleNode<ItemType> * prev = insertPosNode->getPrev();
        new_node_ptr->setPrev(prev);
        new_node_ptr->setNext(insertPosNode);

        prev->setNext(new_node_ptr);
        insertPosNode->setPrev(new_node_ptr);

        if (position == count)
        {
            last_ = insertPosNode;
        }

        //prev->display();
        //new_node_ptr->display();
        //insertPosNode->display();
    }
    count ++;
    return true;
}

template<class ItemType>
bool DoublyLinkedList<ItemType>::remove(const int &position){

    if ((position >= count) || (position < 1))
    {
        //cout << " position exceeds size of list; no node deleted" << endl;
        return false;
    }

    DoubleNode<ItemType> * removePosNode = getAtPos(position);
    if (removePosNode != nullptr)
    {
        //cout << "Removing Node at position: " << position << " " ;
        //removePosNode->display();
        DoubleNode<ItemType> * prev = removePosNode->getPrev();
        DoubleNode<ItemType> * next = removePosNode->getNext();

        if (prev != nullptr)
        {
            prev->setNext(next);
        }
        else {
            //cout << " First node was removed, position must be zero: " << position << endl;
            first_ = next;
        }

        if (next != nullptr)
        {
            next->setPrev(prev);
        }
        else
        {
            //cout << " Last node removed, position = "
            //<< position << " count = " << count << endl;
            last_ = prev;
        }

        delete removePosNode;
        count --;
        return true;
    }
    else
    {
        //cout << "list is empty";
        return false;
    }
}


template<class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const {
    return (count == 0) && (first_ == nullptr);
}


template<class ItemType>
void DoublyLinkedList<ItemType>::clear() {
    DoubleNode<ItemType> *currNode= first_;
    int i = 0;
    while((currNode != nullptr) && (i < count))
    {
        DoubleNode<ItemType> * temp = currNode;
        currNode = currNode->getNext();
        i++;
        delete temp;
    }
    first_ = nullptr;
    last_ = nullptr;
    count = 0;
}

template<class ItemType>
int DoublyLinkedList<ItemType>::getSize() const {
    return count;
}

template<class ItemType>
void DoublyLinkedList<ItemType>::display() const {

    //cout << "display : count = " << count << endl;
    for(int i = 1; i <= count; i++)
    {
        cout << getAtPos(i)->getItem();
        if (i < count) {
            cout << " ";
        }
    }
    cout << "\n";
}


template<class ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const {
    for(int i = count; i > 0; i--)
    {
        cout << getAtPos(i)->getItem();
        if (i > 1)
        {
            cout << " ";
        }

    }
    cout<<"\n";
}


template<class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getHeadPtr() const {
    return first_;
}

template<class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getAtPos(const int &pos) const {
    // cout << "getAtPos : pos= " << pos << " " ;
    DoubleNode<ItemType> *currNode= first_;
    for (int i = 1; i <= count; i++, currNode = currNode->getNext())
    {
        if (i == pos) {
            // currNode->display();
            return currNode;
        }
    }
    return nullptr;
}

template<class ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType> &a_list) {
    int acount  = a_list.count;
    int upto = acount;

    if (count < acount )
    {
        upto = count;
    }

    DoublyLinkedList<ItemType>   combinedList(*this);

    // cout << "Interleaved called c1.count = " << c1 << endl;
    //cout << "This copied, entering for loop " << endl;

    for (int i = 1; i <= upto ; i++)
    {
        DoubleNode<ItemType> *currNode = a_list.getAtPos(i);
        //cout <<"Inserting  " ;
        //currNode->display();
        //cout << " at position " << 2*i << endl;
        combinedList.insert(currNode->getItem(),2*i);
        //combinedList.display() ;
    }

    int remaining = acount - upto;
    int currSize = combinedList.getSize();
    //cout << currSize << " " << remaining << endl;
    if (remaining > 0)
    {
        for (int i = count+1; i <= acount ; i++)
        {
            DoubleNode<ItemType> *currNode = a_list.getAtPos(i);
            //cout <<">>>>>" <<  i << " " ;
            //currNode->display();
            //cout << endl;
            combinedList.insert(currNode->getItem(),currSize+i);
        }
    }


    //cout << " NNNNNNNNNNNEW LIST IS " << endl;
    //combinedList.display();


    return  combinedList;
}