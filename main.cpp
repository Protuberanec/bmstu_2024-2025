#include <iostream>
#include <vector>
#include <array>
#include "test.h"



template<class T> 
class MyArray {
	private :
		T* array;
		int size;
		int count_data;
	public :
		MyArray()  {
			array = new T [64];
			size = 64;
			count_data = 0;
		}
		MyArray(int real_size) {
			array = new T [real_size];
			size = real_size;
			count_data = 0;
		}
		~MyArray() {
			delete [] array;
		}

		T at(int index) const { return array[index % size];}

		T& operator[](int index) {
			return array[index % size];
		}
		bool operator==(const MyArray<T>& comp) {
			if (comp.sizeAr() != this->sizeAr()) {
				return false;
			}
			bool ok = true;
			for (int i = 0; i < comp.sizeAr(); ((comp.at(i) != this->at(i)) ? ok = false : ok = ok), i++) {
				if (ok == false) {
					break;
				}
			}
			
		
			return ok;
		}

		int sizeAr() const {
			return size;
		}

		void show() {
			for (int i = 0; i < size; std::cout << array[i++] << " ");	
			std::cout << std::endl;
		}
};
template<class T>
std::ostream& operator<<(std::ostream& out, const class MyArray<T>& new_array) {
	out << "MyArray : \n";
	for (int i = 0; i < new_array.sizeAr(); out << new_array.at(i) << ((!((i+1) % 8) && i > 0) ? "\n" : "\t"), ++i);

	out << std::endl;
	
	return out;
}

struct Node {};

std::ostream& operator<<(std::ostream& out, const Node& temp) {

	return out;
}


int main(int argc, char** argv) {

	MyArray<int> test1;
	MyArray<int> test;
	for (int i = 0; i < test.sizeAr()*4; test[i] += (i) + 1, i++);
	for (int i = 0; i < test1.sizeAr()*3; test1[i] += i + 1, i++);
	std::cout << (test1 == test ? "true" : "false")  << std::endl;

	std::cout << test << std::endl;

	return 0;
}
