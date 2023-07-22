// #include <iostream>
// #include <list>
// #include "PrecondViolatedExcep.h"

// template<class ItemType>
// class ListQueue {
// public:
// 	ListQueue();
// 	ListQueue(const ListQueue& aQueue);
// 	~ListQueue();
// 	bool isEmpty() const;
// 	bool enqueue(const ItemType& newEntry);
// 	bool dequeue();
// 	ItemType peekFront() const throw(PrecondViolatedExcep);
// private:
// 	LinkedList<ItemType>* listPtr;
// };


// template<class ItemType>
// ListQueue<ItemType>::ListQueue() {
// 	listPtr = new list<ItemType>();
// }

// template<class ItemType>
// ListQueue<ItemType>::ListQueue(const ListQueue& aQueue) : listPtr(aQueue.listPtr)
// {}

// template<class ItemType>
// ListQueue<ItemType>::~ListQueue() 
// {}

// template<class ItemType>
// bool ListQueue<ItemType>::isEmpty() const 
// {
// 	return listPtr->empty();
// }

// template<class ItemType>
// bool ListQueue<ItemType>::enqueue(const ItemType& newEntry) 
// {
// 	return listPtr->insert(listPtr->getLength() + 1, newEntry);
// }

// template<class ItemType>
// bool ListQueue<ItemType>::dequeue() 
// {
// 	return listPtr->remove(1);
// }

// template<class ItemType>
// ItemType ListQueue<ItemType>::peekFront() const 
// 		throw(PrecondViolatedExcep) 
// {
// 	if(empty()) 
// 	{
// 		throw PrecondViolatedExcep("peekFront() called with empty queue.");
// 	}

// 	return listPtr->getEntry(1);
// }



// int main() {
// 	ListQueue<int> lq;
// }


#ifndef _LINKED_QUEUE 
#define _LINKED_QUEUE 

//#include "QueueInterface.h" 
#include "node.h" 
#include "precondViolatedExcep.h"

template <class ItemType>
class LinkedQueue {
public:
	LinkedQueue();
	LinkedQueue(Node<ItemType>*, Node<ItemType>*);
	LinkedQueue(const LinkedQueue& aQueue);
	~LinkedQueue();

	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peekFront() const noexcept(false);
private:
	Node<ItemType>* backPtr;
	Node<ItemType>* frontPtr;
};

template <class ItemType>
LinkedQueue<ItemType>::LinkedQueue() {
	Node<ItemType>* newNode = nullptr;
	backPtr = newNode;
	frontPtr = newNode;
}

template <class ItemType>
LinkedQueue<ItemType>::LinkedQueue(Node<ItemType>* b, Node<ItemType>* f) 
	:backPtr{b}
	,frontPtr{f}
{}

template <class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue& aQueue) : frontPtr{aQueue.frontPtr} {}

template <class ItemType>
LinkedQueue<ItemType>::~LinkedQueue() {}

template <class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const {
	return frontPtr->isEmpty();
}

template <class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry) {
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
	newNodePtr->setNext(nullptr);

	if (isEmpty())
		frontPtr = newNodePtr;
	else 
		backPtr->setNext(newNodePtr);
	backPtr = newNodePtr;
	return true;
}

template <class ItemType>
bool LinkedQueue<ItemType>::dequeue() {
	bool result = false;
	if(!isEmpty())
	{
		Node<ItemType>* newNodePtr = frontPtr;
		if(frontPtr == backPtr) 
		{
			frontPtr = nullptr;
			backPtr = nullptr;
		} 
		else
		{
			frontPtr = frontPtr->getNext();
		}
		newNodePtr->setNext(nullptr);
		delete newNodePtr;
		newNodePtr = nullptr;
		result = true;
	}
	return result;
}

template <class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const noexcept(false) {
	if(isEmpty()) 
	{
		throw PrecondViolatedExcep("peekFront() called with empty queue.");
	}

	return frontPtr->getItem();
}

#endif 