#include <iostream>
#include <time.h>
#include "file_oper.h"
#include "filo.h"

//УКАЗАТЕЛИ НА ФУНКЦИИ!!!

enum class SortType {
	no_sort = 0,
	Ascending = 1,
	Descending = 2,

};
enum STATE_MACHINE {
	Blink = 0,
	TurnOff = 1,
	TurnOn = 2,
};

#define Blink	0
#define	TurnOn	1
#define TurnOff	2



void bubbleSort(int*, int, SortType isAsc) {}

void test1() {}
void test2() {}
void test3() {}

void (*pTest[3])() = {test1, test2, test3};



int main(int argc, char** argv) {

	bubbleSort(nullptr, 0, SortType::Ascending);

	STATE_MACHINE t1;
	pTest[t1]();


	switch(t1) {
		case STATE_MACHINE::Blink :
			break;
		case STATE_MACHINE::TurnOff :
			break;

		case STATE_MACHINE::TurnOn :
			break;

		default:
			break;



	}


	return 0;
}
