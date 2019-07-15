#ifndef NODE_H
#define NODE_H


template <class T>
class Node
{
private:
	Node<T> * next,* previous;
	T value;
public:
	Node();
	Node(T value);
	void setNext(Node * next);
	Node * getNext();
	void setPrevious(Node * previous);
	Node * getPrevious();
	void setValue(T previous);
	T getValue();

};
//generics
template<class T>
Node<T>::Node()
{
	next = previous =0;
}

template<class T>
Node<T>::Node(T value)
{
	next = previous =0;
	this->value = value;
}

template<class T>
void Node<T>::setNext(Node * next)
{
	this->next = next;
}

template<class T>
void Node<T>::setPrevious(Node * previous)
{
	this->previous = previous;
}

template<class T>
Node<T> * Node<T>::getNext()
{
	 return next;
}

template<class T>
Node<T>* Node<T>::getPrevious()
{
	return previous;
}


template<class T>
T Node<T>::getValue()
{
	 return value;
}

template<class T>
void Node<T>::setValue(T value)
{
	this->value = value;
}
#endif // NODE_H
