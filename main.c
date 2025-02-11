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

void fillArray(int *ar, size_t size, int val) {
	for (int i = 0; i < size; ar[i++] = val) {
	}
}


int main(int argc, char** argv) {

	int ar[100];
	fillArray(ar, 100, 0);
	fillArray(&ar[50], 50, 5);
	ShowElement(&ar[0], 100);
	return 0;
}
