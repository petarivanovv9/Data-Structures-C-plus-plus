#pragma once

#include <iostream>
//#include <exception>
//#include <assert.h>


template <typename TYPE>
class LinkedQueue {

	class Node {
	public:
		TYPE _data;
		Node* _pNext;
		Node(TYPE, Node* = NULL);
	};

public:
	LinkedQueue();
	LinkedQueue(LinkedQueue<TYPE> const &);
	LinkedQueue& operator=(LinkedQueue<TYPE> const &);
	~LinkedQueue();

public:
	bool enqueue(TYPE const &);
	bool dequeue();
	TYPE head() const;

	bool isEmpty() const;

private:
	void init();
	void copyFrom(LinkedQueue<TYPE> const &);
	void clean();

private:
	Node* _pFront;
	Node* _pBack;
	size_t _used;
};


//template <typename TYPE>
//LinkedQueue<TYPE>::Node::Node(TYPE data, Node* pNext) {
//	_data = data;
//	_pNext = pNext;
//}
//
//template <typename TYPE>
//LinkedQueue<TYPE>::LinkedQueue() {
//	init();
//}
//
//template <typename TYPE>
//LinkedQueue<TYPE>::LinkedQueue(LinkedQueue<TYPE> const & other) {
//	init();
//	copyFrom(other);
//}
//
//template <typename TYPE>
//LinkedQueue<TYPE>& LinkedQueue<TYPE>::operator=(LinkedQueue<TYPE> const & other) {
//	if (this != &other) {
//		clean();
//		copyFrom(other);
//	}
//
//	return *this;
//}
//
//template <typename TYPE>
//LinkedQueue<TYPE>::~LinkedQueue() {
//	clean();
//}
//
//template <typename TYPE>
//void LinkedQueue<TYPE>::init() {
//	_pFront = NULL;
//	_pBack = NULL;
//	_used = 0;
//}
//
//template <typename TYPE>
//void LinkedQueue<TYPE>::copyFrom(LinkedQueue<TYPE> const & other) {
//	for (Node* pTemp = other._pFront; pTemp != NULL; pTemp = pTemp->_pNext) {
//		enqueue(pTemp->_data);
//	}
//}
//
//template <typename TYPE>
//void LinkedQueue<TYPE>::clean() {
//	while (!isEmpty()) {
//		dequeue();
//	}
//}
//
//template <typename TYPE>
//bool LinkedQueue<TYPE>::enqueue(TYPE const & elem) {
//	Node* pTemp;
//
//	try {
//		pTemp = new Node(elem);
//	}
//	catch (...) {
//		return false;
//	}
//
//	if (!isEmpty()) {
//		_pBack->_pNext = pTemp;
//	}
//	else {
//		_pFront = pTemp;
//	}
//
//	_pBack = pTemp;
//	_used++;
//
//	return true;
//}
//
//template <typename TYPE>
//bool LinkedQueue<TYPE>::dequeue() {
//	if (isEmpty())
//		return false;
//
//	Node* pTemp = _pFront;
//	_pFront = _pFront->_pNext;
//
//	if (_pFront == NULL)
//		_pBack = NULL;
//
//	delete pTemp;
//	_used--;
//
//	return true;
//}
//
//template <typename TYPE>
//bool LinkedQueue<TYPE>::isEmpty() const {
//	return _pBack == NULL;
//}
//
//template <typename TYPE>
//TYPE LinkedQueue<TYPE>::head() const {
//	if (isEmpty()) {
//		std::cerr << "Trying to dequeue from an empty queue!\n";
//		return TYPE();
//	}
//
//	return _pFront->_data;
//}
