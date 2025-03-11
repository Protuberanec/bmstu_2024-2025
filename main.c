#include <iostream>
#include <time.h>
#include "file_oper.h"
#include "filo.h"

//УКАЗАТЕЛИ НА ФУНКЦИИ!!!



int getA(int) {
	std::cout << __func__ << std::endl;
	return 'a';
}

int getB(int) {
	std::cout << __func__ << std::endl;
	return 'b';
}

int getC(int) {
	std::cout << __func__ << std::endl;
	return 'c';
}

void bubbleSort(int* data, int size, bool (*comp)(int a, int b)) {

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (comp(data[j], data[j+1])) {
				std::swap(data[j], data[j+1]);
			}
		}
	}
}

void bubbleSort(int* data, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (data[j] > data[j+1]) {
				std::swap(data[j], data[j+1]);
			}
		}
	}
}

bool my_tst_xz(int a, int b) {
	return a < b;
}

void test_bubbleSort() {
	int* ar = new int [10] {9,4,8,10,-1,0,4,7,9,1};
	bubbleSort(ar, 10);

	bubbleSort(ar, 10, my_tst_xz);

	bubbleSort(ar, 10, [](int a, int b){
			return (a & 0x01) && (a > b);
			});


	return;
}

int main(int argc, char** argv) {

	test_bubbleSort();

	int (*pget[3])(int) = {getA, getB, getC};

	for (int i = 0; i < 3; i++) {
		std::cout << (char)pget[i](0) << std::endl;
	}



	return 0;
}
