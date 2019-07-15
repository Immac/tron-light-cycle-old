#ifndef ARRAYLIST_H
#define ARRAYLIST_H


#include <cstdio>

#ifndef _ArrayList_
#define _ArrayList_

#include "node.h"





template<class T>
class ArrayList
{
private:
     Node<T> * first,* last;
	 unsigned int size;

public:
	 ArrayList();
	 ~ArrayList();
	 bool isEmpty();
	 unsigned int getSize();
	 bool add(T value);


	 T get(int index);
     void set(int index,T value);
     void print();
     bool isContained(ArrayList<T> * listToFind);
     void removeAll(T value)
     void remove(T value);
//     void sortBubble();
};


template<class T>
void ArrayList<T>::removeAll(T value)
{
    Node<T> * actual = 0;
    actual = first;
    int cant;

    for(int i = 0; i < size; i++)
    {
        if (actual->getValue() == value)
            cant++;

        actual = actual->getNext();

    }

    for (int i = 0; i < cant; i++){
        Node<T> * newNode = new Node<T>(value);
    Node<T> * aremover = 0;
            aremover = first;
    while(aremover!=0 && (newNode->getValue() != aremover->getValue())){
        aremover = aremover->getNext();
    }
    if (aremover!= 0)
    {
        size--;
        if (aremover == first)
        {
            if (aremover == last)
                delete aremover;
            else
            {
                first = aremover->getNext();
                delete aremover;
                first->setPrevious(0);
            }
        }
        else if (aremover == last)
        {
            last = aremover->getPrevious();
            delete aremover;
            last->setNext(0);
        }
        else
        {
            aremover->getPrevious()->setNext(aremover->getNext());
            aremover->getNext()->setPrevious(aremover->getPrevious());
            delete aremover;
        }
    }

    }

}

template<class T>
void ArrayList<T>::add (T value)
{
	Node<T> * newNode =  new Node<T>(value);
	if(isEmpty())
		last = first = newNode;
	else
	{
		last->setNext(newNode);
		newNode->setPrevious(last);
		last = newNode;
	}
	size++;
}


template<class T>
ArrayList<T>::ArrayList()
{
	first=last=0;
	size=0;
}


template<class T>
ArrayList<T>::~ArrayList()
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
bool ArrayList<T>::isEmpty()
{
   return size==0;
}



template<class T>
T ArrayList<T>::get(int index)
{
    if (index < getSize()) return 0;
    if (index >= getSize()) return 0;

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
void ArrayList<T>::set(int index,T value)
{
    if (index < getSize()) return;
    if (index >= getSize()) return;
    Node<T> * newNode = new Node<T>(value);
    Node<T> * actual = 0;

    actual = first;
    for(int i = 0; i < index; ++i)
    {
        actual = actual->getNext();
    }

    actual->setValue(newNode->getValue());

}



template <class T>
void ArrayList<T>::print()
{
    if(isEmpty()) return;
     Node<T> * actual;
    actual = first;
    do
    {
        std::cout << actual->getValue();
        std::cout << " ";
        actual = actual->getNext();
    }while(actual != 0);

}



#endif


#endif // ARRAYLIST_H
