#include "linkList.h"

template <typename T>
LinkList<T>::~LinkList() {
    clear();
}

template <typename T>
int LinkList<T>::size() const {
    int count = 0;
	Node<T>* current = head;
	while(current != nullptr){
		count++;
		current = current->next;
	}
	return count;
}

template <typename T>
void LinkList<T>::push_front(const T& val) {
    if(val > head->value) {
        std::cout << "can't add in sorted list, use insert method" << std::endl;
    }
    Node<T>* newNode = new Node<T>(val);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

template <typename T>
void LinkList<T>::push_back(const T& val) {
    if(val < tail->value) {
        std::cout << "can't add in sorted list, use insert method" << std::endl;
    }
    Node<T>* newNode = new Node<T>(val);
    if(!tail) {
        tail = newNode;
        head  = tail; 
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void LinkList<T>::pop_front() {
    if(empty()) return;
    Node<T>* tmp = head;
    head = head->next;
    delete tmp;
    tmp = nullptr;
}

template <typename T>
void LinkList<T>::pop_back() {
    if(!head) return;
    if(head == tail) {
        clear();
    }
    Node<T>* tmp = head;
    while (tmp->next != tail) {
        tmp = tmp->next;
    }
    delete tail;
    tail = tmp;
    tail->next = nullptr;
    
}

template <typename T>
bool LinkList<T>::empty() {
    return head == nullptr;
}

template <typename T>
void LinkList<T>::clear() {
    while (!empty())
    {
        pop_front();
    }
    
}

template <typename T>
T& LinkList<T>::front() {
    return head->value;
}

template <typename T>
T& LinkList<T>::back() {
    return tail->value;
}

template <typename T>
void LinkList<T>::remove(const T& value) {
    if(head == nullptr) return;
    if(head->value == value) {
        Node<T>* tmp = head;
        head = head->next;
        delete tmp;
    }

    Node<T>* curr = head;
    while(head != tail) {
        
        if(head->next->value == value) {

            Node<T>* tmp = curr->next;
            curr->next = tmp->next;
            delete tmp;
            return;

        }
        if(curr->next != nullptr) {
            curr = curr->next;
        }
    }
}

template <typename T>
void LinkList<T>::erase(int pos) {
    if(empty()){
		std::cout << "List is empty";
	} 
	if(pos < 0 || pos >= size()){
		std::cout << "Index out of range";
	}
	if(pos == 0){
		pop_front();
	}
    Node<T>* current = head;
    Node<T>* previous = nullptr;
    int count = 0;
    while (count < pos) {
        previous = current;
        current = current->next;
        count++;
    }
    previous->next = current->next;
    
    if (current == tail) {
        tail = previous;
    } else {
        current->next->prev = previous;
    }
    
    delete current;

}

template <typename T>
void LinkList<T>::insert(int pos, const T& val) {
    if (pos < 0 || pos > size()) {
        std::cout << "Invalid position";
    }
    
    if (pos == 0) {
        push_front(val);  
        return;
    }
    Node<T>* current = head;
    Node<T>* previous = nullptr;
    int count = 0;
    
    while (count < pos) {
        previous = current;
        current = current->next;
        count++;
    }
    
    Node<T>* new_node = new Node<T>(val);
    new_node->next = current;
    new_node->prev = previous;
    
    previous->next = new_node;
    
    if (current != nullptr) {
        current->prev = new_node;
    } else {
        tail = new_node;  
    }

}

template <typename T>
void LinkList<T>::insert(int data) {
    Node<T>* newNode = new Node<T>(data);
    if(head == nullptr) {
        head = newNode;
        tail = newNode;
    } else if(data < head->value) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        Node<T>* current = head;
        while (current->next != nullptr && current->next->value < data)
        {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next = newNode;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
        
    }
}

template <typename T>
int LinkList<T>::find(const T& val) {
    Node<T>* tmp = head;
    int index = 0;
    while (tmp != nullptr)
    {
        if(tmp->value == val) {
            return index;
        }
        tmp = tmp->next;
        return -1;
    }
    
}

template <typename T>
void LinkList<T>::printList(const LinkList<T>& myList) {
    Node<T>* current = myList.head;

    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }

    std::cout << std::endl;
}
