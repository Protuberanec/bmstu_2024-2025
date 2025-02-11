#include <iostream>

void ShowElement(const int* addr_0, unsigned int size) {
	for (int i = 0; i < size; i++) {
		std::cout << addr_0[i] << "\t";
//		std::cout << *(addr_0 + i) << "\t";
//		std::cout << *(addr_0++) << "\t";
	}
	std::cout << std::endl;

}


int main(int argc, char** argv) {

	int ar[100];
	ShowElement(&ar[0], 100);
	return 0;
}
