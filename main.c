#include <iostream>

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

	int count = 1;

	for (int i = 0; i < 32; i++) {

		std::cout << std::hex << (count << i) << "\n";
	}
	std::cout << std::endl;

	return 0;
}
