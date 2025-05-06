#include "ring_buffer.h"


RingBuffer::RingBuffer() {
	buffer = new unsigned char [256];
	begin = 255;
	end = begin;
	data_count = 0x00;
	size = 256;
}

RingBuffer::RingBuffer(int size_) {
	size = size_;
	buffer = new unsigned char [size];
	begin = 0;
	end = begin;
	data_count = 0;
}

RingBuffer::~RingBuffer() {
	delete [] buffer;
}

RB_ERROR RingBuffer::putToEnd(unsigned char element) {
	if (data_count >= size) {
		return RB_ERROR::BUFFER_FULL;
	}

	buffer[end] = element;
	data_count++;
	end++;
	if (end == size) {
		end = 0;
	}

	return RB_ERROR::OK;
}

RB_ERROR RingBuffer::getFromFront(unsigned char* data_out) {
	if (data_count == 0) {
		return RB_ERROR::BUFFER_EMPTY;
	}

	*data_out = buffer[begin];
	data_count--;
	begin++;

	if (begin == size) {
		begin = 0;
	}
	return RB_ERROR::OK;
}

void RingBuffer::flush() {
	data_count = 0;
	begin = end;
}



