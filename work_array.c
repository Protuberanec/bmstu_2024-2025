#include "work_array.h"


void PrintArray(const int* ar, size_t size) {
	size--;

	while(size >= 0) {
		std::cout << ar[size] << "\t";
	}
	std::cout << std::endl;

}

int GetCountOne(int ar) {
	int count = 0;
	for (int i = 0; i < 32; i++) {
		count += (ar >> 1) & 0x01;
	}
}

int GetMaxBitNumber(const int* ar, size_t size_ar) {



}
