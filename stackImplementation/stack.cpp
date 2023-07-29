#include <iostream>
#include <vector>
#include <stdexcept>

template<class Itemtype>
class Stack {
public:
	Stack() = default;
	bool isEmpty() const;
	bool push(const Itemtype&);
	bool pop();
	Itemtype peek() const;
	size_t size() const;
private:	
	std::vector<Itemtype> stack;
	//int size;
};


template <class Itemtype>
bool Stack<Itemtype>::isEmpty() const {
	return stack.size() == 0 ? true : false;
}

template <class Itemtype>
bool Stack<Itemtype>::push(const Itemtype& newEntry) {
	stack.push_back(newEntry);
	return true;
}

template <class Itemtype>
bool Stack<Itemtype>::pop() {
	if(isEmpty()) {
		//throw std::out_of_range("Stack is empty");
		return false;
	}
	Itemtype item = stack.back();
	item.pop_back();
	return true;
}

template <class Itemtype>
Itemtype Stack<Itemtype>::peek() const {
	if(isEmpty()) {
		throw std::out_of_range("Stackis empty");
	}
	return stack[size() - 1];
}

template <class Itemtype>
size_t Stack<Itemtype>::size() const{
	return stack.size();
}

int main() {
	Stack<int> st;
	std::cout << "first" << st.isEmpty() << std::endl;
	const int a = 10;
	st.push(a);
	std::cout << st.peek();
}