#include <iostream>

#include "work_array.h"

/*
 *	так тестировать можно только до 15.03.2025 года.....
 */
void test_GetCountOne() {
	if (GetCountOne(0xFF0F) != 12) {
		std::cout << "errorrrrrrr garden.... 0" << std::endl;
	}

	if (GetCountOne(256) != 1) {
		std::cout << "errorrrrrrr garden.... 1" << std::endl;
	}
	if (GetCountOne(0xFFFFFFFF) != 32) {
		std::cout << "errorrrrrrr garden.... 2" << std::endl;
	}
}




void ShowElement(const int* addr_0, unsigned int size) {
	for (int i = 0; i < size; i++) {
//		std::cout << *(addr_0 + i) << "\t";
//		std::cout << *(addr_0++) << "\t";
		if (i % 10 == 0 && i != 0) {
			std::cout << "\n";
		}
		std::cout << addr_0[i] << "\t";
	}
	std::cout << std::endl;
}



int main(int argc, char** argv) {

	test_GetCountOne();

	return 0;
}
