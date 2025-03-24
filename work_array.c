#include "work_array.h"


void PrintArray(const int* ar, size_t size) {
	size--;

	while(size >= 0) {
		std::cout << ar[size] << "\t";
	}
	std::cout << std::endl;

}

int GetCountOne(unsigned int ar) {
	int count = 0;
	for (int i = 0; i < 32; i++) {
		count += (ar >> i) & 0x01;
	}
	return count;
}

int GetMaxBitNumber(const int* ar, size_t size_ar) {

	int ind_max = 0;
	int max_one = GetCountOne(ar[ind_max]);

	int temp_one = 0;
	for (int i = 1; i < size_ar && max_one < 32; i++) {
		temp_one = GetCountOne(ar[i]);
		if (max_one < temp_one) {
			ind_max = i;
			max_one = temp_one;
		}
	}

	return ind_max;
}
