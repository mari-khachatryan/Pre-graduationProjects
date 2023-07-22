#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>

template <typename T>
class Node{
    public:
        T value;
        Node* next;
        Node* prev; 
        Node<T>(const T& a) : value{a}, next{nullptr}, prev{nullptr} {}
};

template <typename T>
class LinkList {
public:
    LinkList() : head{nullptr}, tail{nullptr} {}
	~LinkList();
    int size() const;
	void push_front(const T& val);
	void push_back(const T& val);
	void pop_front();
	void pop_back();
	bool empty();
    void clear();
	T& front();
	T& back();
	void remove(const T& value);
	void erase(int pos);
    void insert(int val);
	void insert(int pos, const T& val);
	int find(const T& val);
	void printList(const LinkList<T>& myList);
private:
    Node<T>* head;
    Node<T>* tail;
};

#include "linkList.tpp"

#endif //LINKLIST_H