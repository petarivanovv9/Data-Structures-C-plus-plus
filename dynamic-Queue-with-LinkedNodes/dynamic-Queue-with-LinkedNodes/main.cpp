#include <iostream>

#include "LinkedQueue.h"

using namespace std;

int main() {

	LinkedQueue<int> testLinkedQueue_1;
	for (int i = 0; i < 105; i++)
		testLinkedQueue_1.enqueue(i);

	cout << testLinkedQueue_1.head() << endl;

	LinkedQueue<int> testLinkedQueue_2 = testLinkedQueue_1;
	testLinkedQueue_2.enqueue(-1);

	while (!testLinkedQueue_2.isEmpty()) {
		cout << testLinkedQueue_2.head() << ' ';
		testLinkedQueue_2.dequeue();
	}
	cout << endl;

	cout << testLinkedQueue_2.head() << endl;
	cout << testLinkedQueue_2.head() << endl;

	cout << testLinkedQueue_1.head() << endl;
	cout << testLinkedQueue_1.dequeue() << endl;
	cout << testLinkedQueue_1.dequeue() << endl;
	cout << testLinkedQueue_1.dequeue() << endl;
	cout << testLinkedQueue_1.head() << endl;
	cout << testLinkedQueue_1.head() << endl;

	return 0;
}