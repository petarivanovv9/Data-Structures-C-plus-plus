#include <exception>
#include <assert.h>

#include "LinkedStack.h"


template <typename TYPE>
LinkedStack<TYPE>::Node<TYPE>::Node(TYPE data, Node* pNext) {
	_data = data;
	_pNext = pNext;
}

template <typename TYPE>
LinkedStack<TYPE>::LinkedStack() {
	init();
}

template <typename TYPE>
LinkedStack<TYPE>::~LinkedStack() {
	destroy();
}

template <typename TYPE>
LinkedStack<TYPE>::LinkedStack(LinkedStack<TYPE> const & other) {
	init();
	copyFrom(other);
}

template <typename TYPE>
LinkedStack<TYPE>& LinkedStack<TYPE>::operator=(LinkedStack<TYPE> const & other) {
	if (this != &other) {
		destroy();
		copyFrom(other);
	}

	return *this;
}

template <typename TYPE>
void LinkedStack<TYPE>::init() {
	_pTop = NULL;
	_used = 0;
}

template <typename TYPE>
void LinkedStack<TYPE>::destroy() {
	Node* pTemp;

	while (_pTop) {
		pTemp = _pTop;
		_pTop = _pTop->_pNext;
		delete pTemp;
	}

	init();
}

template <typename TYPE>
void LinkedStack<TYPE>::copyFrom(LinkedStack<TYPE> const & other) {
	if (other.isEmpty())
		return;

	Node* pOurs;
	Node* pTheirs;

	try {
		_pTop = new Node(other._pTop->_data);

		pOurs = _pTop;
		pTheirs = other._pTop;

		while (pTheirs) {
			pOurs->_pNext = new Node(pTheirs->_data);
			pOurs = pOurs->_pNext;
			pTheirs = pTheirs->_pNext;
		}

		_used = other._used;
	}
	catch (std::bad_alloc&) {
		destroy();

		throw;
	}
}

template <typename TYPE>
void LinkedStack<TYPE>::removeAll() {
	destroy();
}

template <typename TYPE>
size_t LinkedStack<TYPE>::getAllocatedSize() const {
	return _used * sizeof(Node);
}

template <typename TYPE>
size_t LinkedStack<TYPE>::getSize() const {
	return _used;
}

template <typename TYPE>
bool LinkedStack<TYPE>::isEmpty() const {
	return _used == 0;
}

template <typename TYPE>
bool LinkedStack<TYPE>::push(TYPE element) {
	Node* pNewNode;

	try {
		pNewNode = new Node(element, _pTop);
	}
	catch (...) {
		return false;
	}

	_pTop = pNewNode;
	_used++;

	return true;
}

template <typename TYPE>
bool LinkedStack<TYPE>::pop() {
	if (_used == 0)
		return false;

	Node* pLastNode;
	pLastNode = _pTop;
	_pTop = _pTop->_pNext;
	delete pLastNode;

	_used--;

	return true;
}

template <typename TYPE>
TYPE LinkedStack<TYPE>::peek() const {
	assert(_used != 0);

	return _pTop->_data;
}


template class LinkedStack <int>;
