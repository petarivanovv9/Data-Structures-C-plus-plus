#include <iostream>

#include "StaticQueue.h"

using namespace std;

int main() {

	StaticQueue<int> testStaticQueue_1;
	cout << testStaticQueue_1.empty() << endl;
	for (int i = 0; i < 80; i++)
		testStaticQueue_1.enqueue(i);

	cout << testStaticQueue_1.head() << endl;
	cout << testStaticQueue_1.empty() << endl;

	//StaticQueue<int> testStaticQueue_2 = testStaticQueue_1;
	//testStaticQueue_2.enqueue(-1);

	//while (!testStaticQueue_2.empty()) {
	//	cout << testStaticQueue_2.head() << ' ';
	//	testStaticQueue_2.dequeue();
	//}
	cout << endl;

	//cout << testStaticQueue_2.head() << endl;
	//cout << testStaticQueue_2.head() << endl;
	
	cout << testStaticQueue_1.head() << endl;
	cout << testStaticQueue_1.dequeue() << endl;
	cout << testStaticQueue_1.dequeue() << endl;
	cout << testStaticQueue_1.dequeue() << endl;
	cout << testStaticQueue_1.head() << endl;
	cout << testStaticQueue_1.head() << endl;

	return 0;
}