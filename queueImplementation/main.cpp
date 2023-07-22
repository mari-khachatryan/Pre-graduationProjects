#include <iostream>
#include "queueImplementation.h"
#include "node.h"

int main() {
	Node<int>* backPtr = new Node<int>();
	Node<int>* frontPtr = new Node<int>();
	LinkedQueue<int> queue(backPtr, frontPtr);
	std::cout << queue.isEmpty();
	const int a = 5;
	queue.enqueue(a);
	queue.enqueue(a);
	queue.dequeue();
	queue.peekFront();
	return 0;
}