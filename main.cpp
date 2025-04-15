#include <iostream>
#include <vector>

#include "test.h"


void foo(const std::vector<int>& a) {
	for (int i = 0; i < a.capacity(); i++) {
		std::cout << a[i] << std::endl;
	}

}

class T {
	private :
		std::vector<int> test11;
	public :
		static void test(const std::vector<int>& a);
		void test1() const {
		}

};

void T::test(const std::vector<int>& a) {
	std::cout << __func__ << std::endl;

	
	for (int i = 0; i < a.capacity(); i++) {
		std::cout << i << " : " << a[i] << std::endl;
	}
}

void sort(int* ar, int size, bool (*comp)(int a, int b)) {
	auto getMax = [](const int* ar, int size, bool (*comp)(int a, int b)) {
		int left = 0;
		int right = size - 1;
		while(left != right) {
			if (comp(ar[left], ar[right])) {
				left++;
				continue;
			}
			right--;
		}
		return left;
	};

	for (int i = size - 1; i >= 0; i--) {
		int max_index = getMax(ar, i + 1, comp);
		std::swap(ar[i], ar[max_index]);
	}
}

void test_sort(void (*typeSort)(int* ar, int size, bool (*comp)(int,int)), const std::string& name_sort) {
	std::cout << name_sort << std::endl;
	{
		int size = 10;
		int* ar = new int [size] {2,1,5,3,8,4,4,5,0,19};
		int* true_ar = new int [size] {0,1,2,3,4,4,5,5,8,19};

		typeSort(ar, size, [](int a, int b){return a < b;});

		ASSERT_EQUAL_ARRAY(ar, true_ar, size);

		
		delete [] true_ar;
		delete [] ar;
	}

	{
		int size = 10;
		int* ar = new int [size] {2,1,5,3,8,4,4,5,0,19};
		int* true_ar = new int [size] {0,1,2,3,4,4,5,5,8,19};
		auto reverse = [](int* ar, int size) {
			int left = 0;
			int right = size - 1;
			while(left <= right) {
				std::swap(ar[left++], ar[right--]);
			}
		};
		reverse(true_ar, size);

		typeSort(ar, size, [](int a, int b){return a > b;});

		ASSERT_EQUAL_ARRAY(ar, true_ar, size);

		
		delete [] true_ar;
		delete [] ar;
	}


}


int main(int argc, char** argv) {
	test_sort(sort, "stupid sort");

		int size = 10;
		int* ar = new int [size] {2,1,5,3,8,4,4,5,0,19};

		auto show = [&ar, &size]() {
			std::cout << "---" << std::endl;
			for (int i = 0; i < size; i++) {
				std::cout << ar[i] << "   ";
			}
			std::cout << std::endl;
		};

		show();
		sort(ar, size, [](int a, int b) {return (((b & 0x01) == 0x01)  && ((a & 0x01) == 0x00)); });
		show();

		sort(ar, size, [](int a, int b) {return (((b & 0x01) == 0x01)  && ((a & 0x01) == 0x00)); });
		show();
		sort(ar, size, [](int a, int b) {return (((b & 0x01) == 0x01)  && ((a & 0x01) == 0x00)); });
		show();
		sort(ar, size, [](int a, int b) {return (((b & 0x01) == 0x01)  && ((a & 0x01) == 0x00)); });
		show();
		sort(ar, size, [](int a, int b) {return (((b & 0x01) == 0x01)  && ((a & 0x01) == 0x00)); });
		show();
		sort(ar, size, [](int a, int b) {return (((b & 0x01) == 0x01)  && ((a & 0x01) == 0x00)); });
		show();

	return 0;
	std::vector<int> a;
	a.reserve(16);
	std::cout << a.capacity() << std::endl;
	std::cout << a.capacity()*sizeof(int) << std::endl;


	for (int i = 0; i < a.capacity(); i++) {
		a.push_back(i+1);
	}
	foo(a);

	for (int i = 0; i < 17; i++) {
		a.push_back(1111);
	}

	a.shrink_to_fit();
	T::test(a);

	a.insert(a.begin(),12);
	a.shrink_to_fit();
	std::cout << "-----------------" << std::endl;
	for (const auto& element : a) {
		std::cout << element << std::endl;
	}
	T::test(a);

	std::cout << "-----------------" << std::endl;
	for (std::vector<int>::iterator iter = a.begin(); iter != a.end(); iter++) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
	a.clear();
	a.resize(a.size() + 100);

	std::vector<int*> test;
//	test[0] = 10;
	test.push_back((int*)0x7ffc8aa9a74);
	std::cout << test.capacity() << *test.at(0) << std::endl;

	return 0;
}
