#include "arraylist.h"
#include <assert.h>
using namespace std;

template <class T>
ArrayList<T>::ArrayList(int size)
{
    maxSize = size;
    currSize = 0;
    moveToStart();
    arr = new T[maxSize];
}

template <class T>
ArrayList<T>::~ArrayList()
{
    delete [] arr;
}

template <class T>
void ArrayList<T>::append(T elem)
{
    if(currSize == maxSize)
    {
        doubleSize();
    }
    arr[currSize] = elem;
    currSize++;
}

template <class T>
void ArrayList<T>::next()
{
    if (currElemPos < currSize)
        currElemPos++;
}

template <class T>
void ArrayList<T>::moveToStart()
{
    currElemPos = 0;
}

template <class T>
int ArrayList<T>::length() const
{
    return currSize;
}

template <class T>
int ArrayList<T>::currPos() const
{
    return currElemPos;
}

template <class T>
T ArrayList<T>::value() const
{
    assert(currElemPos >=0 &&  currElemPos < currSize); // No current element
    return arr[currElemPos];
}

template <class T>
void ArrayList<T>::remove()
{
    assert(currElemPos >=0 &&  currElemPos < currSize);
    for(int i = currElemPos; i < currSize-1; i++)
    {
        T temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
    currSize--;
}

template <class T>
void ArrayList<T>::moveToEnd()
{
    currElemPos = currSize;
}

template <class T>
void ArrayList<T>::prev()
{
    if (currElemPos > 0)
    {
        currElemPos--;
    }
}

template <class T>
void ArrayList<T>::moveToPos(int pos)
{
    assert(pos >=0 && pos <= currSize);
    currElemPos = pos;
}

template <class T>
void ArrayList<T>::insert(T elem)
{
    if(currSize == maxSize)
    {
        doubleSize();
    }
    T* temp = new T[currSize+1];

    for(int i = 0; i <= currSize; i++)
    {
        if(i < currElemPos)
        {
            temp[i] = arr[i];
        }
        else if(i == currElemPos)
        {
            temp[i] = elem;
        }
        else if(i > currElemPos)
        {
            temp[i] = arr[i-1];
        }
    }

    currSize++;

    for(int i = 0; i < currSize; i++)
    {
        arr[i] = temp[i];
    }

    delete [] temp;
}

template <class T>
void ArrayList<T>::doubleSize()
{
    maxSize = maxSize*2;
    T* temp = new T[maxSize];
    for(int i = 0; i < currSize; i++)
    {
        temp[i] = arr[i];
    }

    delete [] arr;
    arr = temp;
}

template <class T>
void ArrayList<T>::clear()
{
    delete [] arr;
    arr = new T[maxSize];
    currElemPos = 0;
    currSize = 0;
}
