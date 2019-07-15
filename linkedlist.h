#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"

template<class T>
class LinkedList
{
private:

	 unsigned int size;

public:
    Node<T> * first,* last;
	 LinkedList();
	 ~LinkedList();
	 bool isEmpty();
	 unsigned int getSize();
	 bool add(T value);
	 bool remove(int index);
	 T get(int index);
	 bool clear();

};


template<class T>
bool LinkedList<T>::add (T value)
{
    bool returnThis = false;
	Node<T> * newNode =  new Node<T>(value);
	if(isEmpty())
    {
		last = first = newNode;
		returnThis = true;
    }
	else
	{
		last->setNext(newNode);
		newNode->setPrevious(last);
		last = newNode;
		returnThis = true;
	}
	size++;
	return returnThis;
}

template<class T>
bool LinkedList<T>::remove(int index)
{
    Node<T> * actual = 0;
    actual = first;
    bool returnThis = false;

    for(int i = 0; i < index; ++i)
    {
        actual = actual->getNext();
    }
     if (actual!= 0)
    {   returnThis = true;
        size--;
        if (actual == first)
        {
            if (actual == last)
                delete actual;
            else
            {
                first = actual->getNext();
                delete actual;
                first->setPrevious(0);
            }
        }
        else if (actual == last)
        {
            last = actual->getPrevious();
            delete actual;
            last->setNext(0);
        }
        else
        {
            actual->getPrevious()->setNext(actual->getNext());
            actual->getNext()->setPrevious(actual->getPrevious());
            delete actual;
        }
    }
    return returnThis;
}

template<class T>
T LinkedList<T>::get(int index)
{
    if (index > getSize()) return 0;
    Node<T> * actual;
    T temp;
    actual = first;

    for(int i = 0; i < index; i++)
    {
        actual = actual->getNext();
    }
    temp = actual->getValue();
    return temp;

}

template<class T>
LinkedList<T>::LinkedList()
{
	first=last=0;
	size=0;
}


template<class T>
LinkedList<T>::~LinkedList()
{
  if(isEmpty()) return;
     Node<T> * actual;
     Node<T> * eraseMe;
    actual = first;
    do
    {
        eraseMe = actual;
        actual = actual->getNext();
        delete eraseMe;
    }while(actual != 0);
}

template<class T>
unsigned int LinkedList<T>::getSize()
{
    return size;
}

template<class T>
bool LinkedList<T>::isEmpty()
{
    return size==0;
}

template<class T>
bool LinkedList<T>::clear()
{
    for(int i = 0; i < size;i++)
    {
        this->remove(0);
    }
    size = 0;
    return true;
}

#endif // LINKEDLIST_H
