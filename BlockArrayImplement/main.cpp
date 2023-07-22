#include <iostream>
#include "blockArray.h" 

int main() {
	const size_t size = 5;
	BlockArray<int> b(size);
	b.setItem(8, 2);
	std::cout << b.getItem(2) << std::endl;
	b.append(3);
	return 0;
}