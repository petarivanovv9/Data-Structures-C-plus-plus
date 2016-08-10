#pragma once

#include <iostream>
#include <exception>
#include <assert.h>


template <typename TYPE>
class Node {
public:
	TYPE _data;
	Node* _pNext;
	Node(TYPE, Node* = NULL);
};


template <typename TYPE>
class LinkedQueue {
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
	Node<TYPE>* _pTop;
	Node<TYPE>* _pBack;
	size_t _used;
};

