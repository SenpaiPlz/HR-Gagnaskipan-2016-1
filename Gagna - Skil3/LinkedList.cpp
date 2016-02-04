#include "LinkedList.h"
#include <cstdlib>

template <class T>
LinkedList<T>::LinkedList()
{
    trailer = new Node<T>;
    header = new Node<T>;
    init();
}

template <class T>
LinkedList<T>::LinkedList(LinkedList<T>& lis)
{
    trailer = new Node<T>;
    header = new Node<T>;
    init();
    if(!lis.empty())
    {
        for(lis.moveToStart(); lis.getCurrNode() != lis.end(); lis.next())
        {
            //insert the values one by one, into the end of the list
            append(lis.value());
        }
    }
}

template <class T>
LinkedList<T>::~LinkedList()
{
    removeAll();
    delete header;
    delete trailer;
    //deallocate memory
}

template <class T>
void LinkedList<T>::init()
{
    trailer->setNext(NULL);
    header->setPrev(NULL);
    trailer->setPrev(header);
    header->setNext(trailer);

    currSize = 0;
    currNode = trailer;
}

template <class T>
Node<T>* LinkedList<T>::getCurrNode() const
{
    return currNode;
}

template <class T>
Node<T>* LinkedList<T>::end() const
{
    return trailer;
}

template <class T>
bool LinkedList<T>::empty() const
{
    return (header->getNext() == trailer);
}

template <class T>
T LinkedList<T>::value() const
{
    return (currNode->getData());
}

template <class T>
int LinkedList<T>::length() const
{
    return currSize;
}

template <class T>
void LinkedList<T>::moveToStart()
{
    currNode = header->getNext();
}

template <class T>
void LinkedList<T>::moveToEnd()
{
    currNode = trailer;
}

template <class T>
void LinkedList<T>::next()
{
    if(currNode != trailer)
    {
        currNode = currNode->getNext();
    }
}

template <class T>
void LinkedList<T>::prev()
{
    if(currNode->getPrev() != header)
    {
        currNode = currNode->getPrev();
    }
}

template <class T>
void LinkedList<T>::moveToPos(int pos)
{
    if((pos < 0) || (pos > currSize)) //define out of range set as trailer.
    {
        currNode = trailer;
    }
    else
    {
        moveToStart();
        for(int i = 0; i < pos; i++)
        {
            next();
        }
    }
}

template <class T>
void LinkedList<T>::append (T elem)
{
    //Create a new node;
    Node<T>* temp = new Node<T>(elem,trailer,trailer->getPrev());

    //Set links to point correctly
    (trailer->getPrev())->setNext(temp);
    trailer->setPrev(temp);

    currSize++;
    if(currNode == trailer)
    {
        currNode = trailer->getPrev();
    }
}

template <class T>
T LinkedList<T>::remove()
{
    Node<T>* temp = currNode;
    next();
    //next assures us that currNode never goes beyond trailer
    //if currNode == trailer: temp = trailer.
    //                        currNode(trailer) set prev to trailer get prev
    //                        (last node) set next to trailer.
    //Therefore we can assume that if currNode = trailer, nothing happens.

    currNode->setPrev(temp->getPrev());
    (temp->getPrev())->setNext(currNode);
    T data = temp->getData();
    currSize--;
    delete temp;
    return data;
}

template <class T>
void LinkedList<T>::insert (const T& elem)
{
    insert(currNode,elem);
    currSize++;
    currNode = currNode->getPrev();
}

template <class T>
void LinkedList<T>::insert (Node<T>* beforeMe,const T& elem)
{
    Node<T>* temp = new Node<T>(elem,beforeMe,beforeMe->getPrev());
    (beforeMe->getPrev())->setNext(temp);
    beforeMe->setPrev(temp);
}

template <class T>
void LinkedList<T>::removeAll()
{
    moveToStart();
    while(currNode != trailer)
    {
        remove();
    }
}

template <class T>
void LinkedList<T>::clear()
{
    removeAll();
    init();
}
