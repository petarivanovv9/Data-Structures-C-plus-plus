#pragma once

int const MAX_SIZE = 100;

template <typename TYPE>
class StaticQueue {
private:
	TYPE data[MAX_SIZE];
	int front, back, size;
	bool full() const;
public:
	StaticQueue();
	bool empty() const;
	bool enqueue(TYPE const&);
	TYPE dequeue();
	bool dequeue(TYPE&);
	TYPE head() const;
	bool head(TYPE&) const;
	int length() const { return size; }
};

template <typename TYPE>
StaticQueue<TYPE>::StaticQueue() : front(0), back(0), size(0) {}

template <typename TYPE>
bool StaticQueue<TYPE>::empty() const {
	return size == 0;
}

template <typename TYPE>
bool StaticQueue<TYPE>::full() const {
	return size == MAX_SIZE;
}

template <typename TYPE>
bool StaticQueue<TYPE>::enqueue(TYPE const& x) {
	if (full())
		return false;
	data[back] = x;
	(++back) %= MAX_SIZE;
	size++;
	return true;
}

template <typename TYPE>
TYPE StaticQueue<TYPE>::dequeue() {
	if (empty())
		return TYPE();
	TYPE x = head();
	(++front) %= MAX_SIZE;
	size--;
	// front++; if (front == MAX_SIZE) front = 0;
	return x;
}

template <typename TYPE>
bool StaticQueue<TYPE>::dequeue(TYPE& x) {
	if (empty())
		return false;
	x = dequeue();
	return true;
}

template <typename TYPE>
bool StaticQueue<TYPE>::head(TYPE& x) const {
	if (empty())
		return false;
	x = data[front];
	return true;
}

template <typename TYPE>
TYPE StaticQueue<TYPE>::head() const {
	TYPE x;
	head(x);
	return x;
}