#include "filo.h"

FILO::FILO() {
	//ну
	ar = new int [64];
	lastElement = 0;
	_size = 64;
}

FILO::FILO(int size) : _size(size) {
	ar = new int [size];
	lastElement = 0;
}

FILO::~FILO() {
	delete [] ar;
}

bool FILO::addToEnd(int el) {
	if (lastElement == _size) {
		return false;
	}

	ar[lastElement++] = el;
	return true;
}


int FILO::getFromEnd(bool& ok) {
	if (lastElement == 0) {
		ok = false;
		return -1;
	}
	ok = true;
	return ar[--lastElement];	

}

int FILO::getCountElement() const {
	return lastElement;
}

void FILO::flush() {
	lastElement = 0;	
}

