#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <string>

#include <memory>

#include "unique_ptr.h"


int memory_give = 0;

void* operator new[](size_t size) {
	memory_give++;

	return (void*)malloc(size);
}

void* operator new(size_t size) {
	memory_give++;
	return (void*)malloc(size);
}

void operator delete(void* ar) {
	free(ar);
	memory_give--;
	std::cout << "free memory..." << std::endl;
}

void operator delete[](void* ar) {
	free(ar);
	memory_give--;
}


class Foo {
	public :
		Foo() { std::cout << __func__ << std::endl; }
		~Foo() { std::cout << __func__ << std::endl; }

		unsigned char sum(unsigned char a, unsigned char b) { 
			std::cout << __LINE__ << " : " << __func__ << ":  " << (int)a << " + " <<  (int)b << " = " << (int)(a+b) << std::endl;
			return a + b;
	   	}
};

int main(int argc, char** argv) {

	{
		std::unique_ptr<Foo> sp1 {std::make_unique<Foo>()};
		std::unique_ptr<Foo> sp2 = std::move(sp1); 

		if (sp1.get()) {
			sp1.get()->sum(10,-10);
		}
		sp2.get()->sum(56, 202);
		int* ar = new int();
		int* ar1 = new int();

	}

	std::cout << "start to end ..... " << std::endl;

	std::cout << "-----------------------------" << std::endl;

	{
		UniquePtr<Foo> sq1 { new Foo() };
		sq1.get()->sum(100, 100);
		int* ar = new int();
	}

	int* ar = new int();
	std::cout << "memory ..... " << memory_give << std::endl; 

	return 0;
}





















