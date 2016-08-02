#include <iostream>

#include "LinkedStack.h"


int main() {

	LinkedStack<int> testLinkedStack;

	std::cout << "testLinkedStack.isEmpty() : " << testLinkedStack.isEmpty() << std::endl;

	std::cout << "testLinkedStack.getAllocatedSize() : " << testLinkedStack.getAllocatedSize() << std::endl;
	
	std::cout << "testLinkedStack.getSize() : " << testLinkedStack.getSize() << std::endl;




	return 0;
}