#include <iostream>

#include "LinkedStack.h"


int main() {

	LinkedStack<int> testLinkedStack;

	std::cout << "testLinkedStack.isEmpty() : " << testLinkedStack.isEmpty() << std::endl;
	std::cout << "testLinkedStack.getAllocatedSize() : " << testLinkedStack.getAllocatedSize() << std::endl;
	std::cout << "testLinkedStack.getSize() : " << testLinkedStack.getSize() << std::endl;

	testLinkedStack.push(5);
	testLinkedStack.push(6);
	testLinkedStack.push(7);
	testLinkedStack.push(9);
	testLinkedStack.push(10);

	std::cout << testLinkedStack.peek() << std::endl;

	int a = testLinkedStack.peek();
	testLinkedStack.pop();
	std::cout << a << std::endl;

	std::cout << testLinkedStack.peek() << std::endl;

	a = testLinkedStack.peek();
	testLinkedStack.pop();
	//testLinkedStack.pop(a);
	std::cout << a << std::endl;

	std::cout << testLinkedStack.peek() << std::endl;

	LinkedStack<int> testLinkedStack_2;
	testLinkedStack_2 = testLinkedStack;

	std::cout << testLinkedStack_2.peek() << std::endl;

	std::cout << "testLinkedStack.getSize() : " << testLinkedStack.getSize() << std::endl;

	testLinkedStack.clean();
	std::cout << "testLinkedStack.getSize() : " << testLinkedStack.getSize() << std::endl;
	std::cout << testLinkedStack.getAllocatedSize() << std::endl;

	testLinkedStack.push(5);
	testLinkedStack.push(6);
	std::cout << "testLinkedStack.getSize() : " << testLinkedStack.getSize() << std::endl;
	std::cout << testLinkedStack.peek() << std::endl;


	return 0;
}