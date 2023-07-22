#ifndef BLOCKARRAY_H
#define BLOCKARRAY_H

#include <iostream>
#include <vector>


template<typename T>
class BlockArray {
public:
	BlockArray(size_t);
	size_t getBlockSize() const;
	std::vector<std::vector<T>> getBlocks() const;
	void setBlockSize(const size_t&);
	void setBlocks(const std::vector<std::vector<T>>&);
	void setItem(const T&, size_t index);
	T getItem(size_t index);
	void append(const T&);
	size_t size() const;
private:
	size_t blockSize;
	std::vector<std::vector<T>> blocks;
};


#include "blockArray.tpp"

#endif //BLOCKARRAY_H