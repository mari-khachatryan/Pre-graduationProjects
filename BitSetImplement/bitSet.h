#include <iostream>
#include <vector>

class BitSet { 
public:
	BitSet(size_t);
	void set(size_t, bool);
	bool get(size_t) const;
	void clear();
	size_t size() const;
	void print() const;
private:
	std::vector<unsigned char> data;
};


BitSet::BitSet(size_t size) {
	size_t countOfItem = 0;
	if(size % sizeof(char) == 0) {
		countOfItem = size / sizeof(char);
	} else {
		countOfItem = size / sizeof(char) + 1;
	}
	data.resize(countOfItem, 0);
}

void BitSet::set(size_t index, bool value = true) {
	if(index >= size()) {
		throw std::out_of_range("possition out of permissible rang!");
	}
	// size_t countOfItems = index / sizeof(char);
	size_t poss = index % sizeof(char);
	size_t changingByte = (index + sizeof(char) - 1) / sizeof(char);
	unsigned char mask = 1 << (sizeof(char) - poss);
	if(value) {
		data[changingByte] |= mask;
	} else {
		data[changingByte] &= ~mask;
	}
}

bool BitSet::get(size_t index) const {
	if(index >= size()) {
		throw std::out_of_range("possition out of permissible rang!");
	}
	//size_t countOfItems = index / sizeof(char);
	size_t poss = index % sizeof(char);
	size_t getingByte = (index + sizeof(char) - 1) / sizeof(char);
	unsigned char mask = 1 << (sizeof(char) - poss);
    return (data[getingByte] & mask) != 0;
}

void BitSet::clear() {
	data.assign(data.size(), 0);
}

size_t BitSet::size() const {
	return data.size() * sizeof(char);
}

void BitSet::print() const {
	 for (size_t i = 0; i < size(); ++i) {
        std::cout << (get(i) ? '1' : '0');
    }
    std::cout << std::endl;
}

