#pragma once

#include <iostream>


template <typename TYPE>
class LinkedStack {

	class Node {
	public:
		TYPE _data;
		Node<TYPE>* _pNext;
		Node(TYPE, Node<TYPE>* = NULL);
	};

public:
	LinkedStack();
	~LinkedStack();
	LinkedStack(LinkedStack<TYPE> const & other);
	LinkedStack& operator=(LinkedStack<TYPE> const & other);

public:
	bool push(TYPE);
	bool pop();
	TYPE peek() const;

	void removeAll();

	size_t getAllocatedSize() const;
	size_t getSize() const;

	bool isEmpty() const;

private:
	void init();
	void destroy();
	void copyFrom(LinkedStack<TYPE> const &);

private:
	Node* _pTop;
	size_t _used;
};

