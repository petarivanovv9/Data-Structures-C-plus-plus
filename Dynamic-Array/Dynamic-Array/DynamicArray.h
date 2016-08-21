#pragma once

#include <algorithm>

template <typename TYPE>
class DynamicArray {
public:
	DynamicArray();
	DynamicArray(DynamicArray<TYPE> const & other);
	DynamicArray<TYPE>& operator=(DynamicArray<TYPE> const & other);
	~DynamicArray();

public:
	void clear();
	void push_back(TYPE elem);

	size_t size() const;

	TYPE at(size_t) const;

private:
	TYPE* pData;
	size_t allocatedSize;
	size_t _size;

private:
	void copyFrom(DynamicArray<TYPE> const & other);
	void reallocate(size_t);
};


template <typename TYPE>
DynamicArray<TYPE>::DynamicArray() {
	pData = NULL;
	allocatedSize = 0;
	_size = 0;
}

template <typename TYPE>
DynamicArray<TYPE>::DynamicArray(DynamicArray<TYPE> const & other) {
	copyFrom(other);
}

template <typename TYPE>
DynamicArray<TYPE>& DynamicArray<TYPE>::operator=(DynamicArray<TYPE> const & other) {
	if (this != &other) {
		clear();
		copyFrom(other);
	}
	return *this;
}

template <typename TYPE>
DynamicArray<TYPE>::~DynamicArray() {
	clear();
}

template <typename TYPE>
void DynamicArray<TYPE>::copyFrom(DynamicArray<TYPE> const & other) {
	clear();

	pData = new TYPE[other.allocatedSize];

	for (size_t i = 0; i < other._size; i++)
		pData[i] = other.pData[i];
	
	allocatedSize = other.allocatedSize;
	_size = other._size;
}

template <typename TYPE>
void DynamicArray<TYPE>::clear() {
	delete[] pData;

	pData = NULL;
	allocatedSize = 0;
	_size = 0;
}

template <typename TYPE>
void DynamicArray<TYPE>::reallocate(size_t newSize) {
	TYPE* pTemp = new TYPE[newSize];
	
	size_t limit = std::min(allocatedSize, newSize);

	for (size_t i = 0; i < limit; i++)
		pTemp[i] = pData[i];

	delete[] pData;
	pData = pTemp;
	allocatedSize = newSize;
}

template <typename TYPE>
void DynamicArray<TYPE>::push_back(TYPE elem) {
	if (_size >= allocatedSize) {
		size_t newSize = (allocatedSize == 0 ? 2 : allocatedSize * 2);

		reallocate(newSize);
	}
	pData[_size++] = elem;
}

template <typename TYPE>
size_t DynamicArray<TYPE>::size() const {
	return _size;
}

template <typename TYPE>
TYPE DynamicArray<TYPE>::at(size_t index) const {
	if (index >= _size) {
		throw std::out_of_range("Index out of range!");
	}
	return pData[index];
}