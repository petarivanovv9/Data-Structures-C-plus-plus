#include <iostream>

using namespace std;

#include "DynamicArray.h"


int main() {

	DynamicArray<int> testDynamicArray;

	std::cout << "testDynamicArray.size() : " << testDynamicArray.size() << std::endl;

	testDynamicArray.push_back(5);
	testDynamicArray.push_back(6);
	testDynamicArray.push_back(7);
	testDynamicArray.push_back(9);
	testDynamicArray.push_back(10);

	std::cout << testDynamicArray.at(0) << std::endl;

	int a = testDynamicArray.at(2);
	
	std::cout << a << std::endl;

	DynamicArray<int> testDynamicArray_2;
	testDynamicArray_2 = testDynamicArray;

	std::cout << testDynamicArray_2.at(1) << std::endl;

	std::cout << "testDynamicArray.size() : " << testDynamicArray.size() << std::endl;

	testDynamicArray.clear();
	std::cout << "testDynamicArray.size() : " << testDynamicArray.size() << std::endl;

	testDynamicArray.push_back(5);
	testDynamicArray.push_back(6);
	std::cout << "testDynamicArray.size() : " << testDynamicArray.size() << std::endl;
	

	return 0;
}