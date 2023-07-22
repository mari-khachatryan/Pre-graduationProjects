#include "blockArray.h"
 

template<typename T>
BlockArray<T>::BlockArray(size_t b) : blockSize{b} {
    blocks.push_back(std::vector<T>(b));
}

template<typename T>
size_t BlockArray<T>::getBlockSize() const {
	return blockSize;
}

template<typename T>
std::vector<std::vector<T>> BlockArray<T>::getBlocks() const {
	return blocks;
}

template<typename T>
void BlockArray<T>::setBlockSize(const size_t& b) {
	blockSize = b;
}

template<typename T>
void BlockArray<T>::setBlocks(const std::vector<std::vector<T>>& b) {
	blocks = b;
}

template<typename T>
void BlockArray<T>::setItem(const T& item, size_t index) {
	if(index < 0 || index > blockSize) {
		throw std::out_of_range("illegal position!");
	}
	size_t blockNum = index / blockSize;
	size_t innerBlock = index % blockSize;
	blocks[blockNum][innerBlock] = item;
}

template<typename T>
T BlockArray<T>::getItem(size_t index) {
	if(index < 0 || index > blockSize) {
		throw std::out_of_range("illegal position!");
	}
	size_t blockNum = index / blockSize;
	size_t innerBlock = index % blockSize;
	return blocks[blockNum][innerBlock];
}

template<typename T>
void BlockArray<T>::append(const T& item) {
	if(blocks.back().size() == blockSize) {
		blocks.push_back(std::vector<T>());
	}
	blocks.back().push_back(item);
}

template<typename T>
size_t BlockArray<T>::size() const {
	size_t blockCount = blocks.size();
	size_t lastBlockSize = blocks.back().size();
	return (blockCount - 1) * blockSize + lastBlockSize;
}