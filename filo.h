#pragma once 
#include <iostream>
//#ifndef _filo_h_
//#define _filo_h_

struct FILO {
	int* ar;	
	int lastElement;
	int _size;

	FILO();
	FILO(int size);
	~FILO();

	bool addToEnd(int element);
	bool getFromEnd_ZaicevVV(int &Zaicev_VV);
	int getFromEnd(bool& ok);
	int getCountElement() const;
	void flush();
};


//#endif
