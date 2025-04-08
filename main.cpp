#include <iostream>

void ShowNum(int a) {
	if (a < 0) {

		return;
	}

	ShowNum(--a);
	std::cout << a + 1 << "\t";
}

int GetMax1(const int* ar, int size) {
	int left = 0;
	int right = size - 1;

	while(left != right) {
		if (ar[left] > ar[right]) {
			right--;
			continue;
		}
		left++;
	}

	return ar[left];
}

int GetMax2(const int* ar, int size) {
	if (size == 1) {
		return ar[0];
	}

	if (ar[0] > ar[size - 1]) {
		return GetMax2(ar, size - 1);
	}
	else {
		return GetMax2(&ar[1], size - 1);
	}
}

int GetMax(const int* ar, int size) {
	return (size != 1 ) ? ((ar[0] > ar[size - 1]) ? GetMax(ar, size-1) : GetMax(&ar[1], size-1)) : ar[0];
}


int BinarySearch(const int* ar, int size, int element) {
	if (size <= 1) {
		if (ar[0] == element) {
			return size/2;
		}
		return -1;
	}

	if (element > ar[(size)/2]) {
		int res = BinarySearch(&ar[size / 2], size - size/2, element);
		res = (res == -1) ? -1 : res + (size) / 2;
		return res;
	}
	else if (element < ar[(size)/2]) {
		return BinarySearch(&ar[0], size/2, element);
	}

	return (size)/2;
}

int test_BinarySearch() {
	int count_test = 1;
	std::cout << "------\n" << __func__ << std::endl;
	{
		int* ar = new int [10] {1,2,3,4,5,6,7,8,9,10};
		for (int i = 1; i < 11; i++) {
			if (BinarySearch(ar, 10, i) == i - 1) 
				std::cout << "TEST " << count_test++ << " PASSED" << std::endl;
			else 
				std::cout << "TEST " << count_test++ << " BAD" << std::endl;
		}
		delete [] ar;
	}
	{
		std::cout << "---" << std::endl;
		int* ar = new int [10] {1,3,3,4,5,6,8,8,9,10};
		if (BinarySearch(ar, 10, 14) == -1) 
				std::cout << "TEST " << count_test++ << " PASSED" << std::endl;
			else 
				std::cout << "TEST " << count_test++ << " BAD" << std::endl;
		if (BinarySearch(ar, 10, 0) == -1) 
				std::cout << "TEST " << count_test++ << " PASSED" << std::endl;
			else 
				std::cout << "TEST " << count_test++ << " BAD" << std::endl;
		if (BinarySearch(ar, 10, 7) == -1) 
				std::cout << "TEST " << count_test++ << " PASSED" << std::endl;
			else 
				std::cout << "TEST " << count_test++ << " BAD" << std::endl;

		if (BinarySearch(ar, 10, 2) == -1) 
				std::cout << "TEST " << count_test++ << " PASSED" << std::endl;
			else 
				std::cout << "TEST " << count_test++ << " BAD" << std::endl;
		delete [] ar;
	}
}

void test_GetMax() {
	{
		int* ar = new int [10] {1,2,3,4,5,6,7,8,9,10};
		if (GetMax(ar, 10) == 10) {
			std::cout << "TEST PASSED" << std::endl;
		}
		else {
			std::cout << "TEST BAD" << std::endl;
		}
		delete [] ar;
	}

	{
		int* ar = new int [10] {22,2,3,4,5,6,7,8,9,10};
		if (GetMax(ar, 10) == 22) {
			std::cout << "TEST PASSED" << std::endl;
		}
		else {
			std::cout << "TEST BAD" << std::endl;
		}
		delete [] ar;
	}
	{
		int* ar = new int [10] {22,2,3,4,40,6,7,8,9,10};
		if (GetMax(ar, 10) == 40) {
			std::cout << "TEST PASSED" << std::endl;
		}
		else {
			std::cout << "TEST BAD" << std::endl;
		}
		delete [] ar;
	}
	{
		int* ar = new int [10] {5,5,5,5,5,5,5,5,5,5};
		if (GetMax(ar, 10) == 5) {
			std::cout << "TEST PASSED" << std::endl;
		}
		else {
			std::cout << "TEST BAD" << std::endl;
		}

		delete [] ar;
	}
}

int main(int argc, char** argv) {

	test_GetMax();
	test_BinarySearch();


	return 0;
}
