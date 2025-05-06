#ifndef _ring_buffer_h_
#define _ring_buffer_h_

#include <iostream>

enum class RB_ERROR {
	OK = 0,
	BUFFER_FULL = 1,
	BUFFER_EMPTY = 2,
};

template<class T>
class RingBuffer {
	private :
		T *buffer;
		int size;
		int begin;
		int end;	//index
		int data_count;

	public :
		RingBuffer();
		RingBuffer(int);
		~RingBuffer();

		RB_ERROR putToEnd(T xz);
		RB_ERROR getFromFront(T* xz);
		void flush();
};



#endif
