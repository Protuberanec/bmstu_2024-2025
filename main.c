#include <assert.h>
#include <iostream>
#include <string>
#include <time.h>
#include <cstring>
#include "file_oper.h"
#include "filo.h"
#include "node.h"

#include "test.h"

void xzSort(int* ar, int size) {
	int index = 0;
	auto getMax1 = [&index](const int *ar, int size) {
		index = 0;
		for (int i = 1; i < size; i++) {
			index = ar[i] > ar[index] ? i : index;
		}

	};

	for (int i = 0; i < size; i++) {
		getMax1(&ar[i], size - i);
		//std::swap(ar[i], ar[index + i]);
	}
}

bool CheckSorts(const int* ar, int size) {
	for (int i = 0; i < size - 1; i++) {
		if (ar[i] < ar[i+1]) {
			return false;
		}
	}
	return true;
}

void test_zxSort() {
	
	{
		int size = 10;
		int *ar = new int [size] {1,2,3,4,5,6,7,8,9,10};
		xzSort(ar, size);
		bool isSorted = CheckSorts(ar, size);
	//	assert(isSorted);
		if (isSorted == true) {
			std::cout << "TEST OK" << std::endl;
		}
		else {
			std::cout << "TEST BAD" << std::endl;
		}
		delete [] ar;
	}
	{
		int size = 10;
		int* ar = new int [size] {10,9,8,7,6,5,4,3,2,1};
		xzSort(ar, size);
		bool isSorted = CheckSorts(ar, size);
	//	assert(isSorted);
		if (isSorted == true) {
			std::cout << "TEST OK" << std::endl;
		}
		else {
			std::cout << "TEST BAD" << std::endl;
		}
		delete [] ar;
	}
	{
		int size = 10;
		int* ar = new int [size] {10,9,8,7,6,5,4,3,2,1};
		memset(ar, 0x00, size * 4);
		xzSort(ar, size);
		bool isSorted = CheckSorts(ar, size);
	//	assert(isSorted);
		if (isSorted == true) {
			std::cout << "TEST OK" << std::endl;
		}
		else {
			std::cout << "TEST BAD" << std::endl;
		}
		delete [] ar;
	}
}


#define SIZE	100
#define SUM(a,b)	(a) + (b)
#define MULT(a,b, c, d)	a * b + c/ (d == 0 ? 1 : d)
void mergeSort(int* ar, int size) {}



void testSorts(void (*typeSort)(int* ar, int size)) {

	{
		int size = 10;
		int *ar = new int [size] {1,2,3,4,5,6,7,8,9,10};
		typeSort(ar, size);
		bool isSorted = CheckSorts(ar, size);
		ASSERT(isSorted);
		delete [] ar;
	}

}
int main(int argc, char** argv) {


	testSorts(xzSort);
	testSorts(mergeSort);


	return 0;
	struct Node* Head = new Node();
	for (int i = 0; i < 10; AddNode(Head), i++);

	ShowElements(Head);
	ShowElements(Head->next->next->next);


	delete Head;

	return 0;
}
