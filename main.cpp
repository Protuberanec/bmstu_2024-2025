#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <string>

#include "ring_buffer.h"


int main(int argc, char** argv) {
	RingBuffer<double> test;
	RingBuffer tempBuffer;
	auto res { [&]() {
		unsigned char data;
		int count_data = 0;
		while(tempBuffer.getFromFront(&data) != RB_ERROR::BUFFER_EMPTY) {
			std::cout << (unsigned int)data;
			if (!(count_data++ % 8)) {
				std::cout << std::endl;
				continue;
			}
			std::cout << "\t";
		}
		std::cout << std::endl << "buffer empty" << std::endl;;
	} };

	res();

	for (int i = 0; i < 156; i++) {
		if (tempBuffer.putToEnd(i) == RB_ERROR::BUFFER_FULL) 
		{
			std::cout << " buffer is full...." << std::endl;
			break;
		}
	}

	res();

	for (int i = 0; i < 300; i++) {
		if (tempBuffer.putToEnd(i) == RB_ERROR::BUFFER_FULL) 
		{
			std::cout << " buffer is full.... " << i  << std::endl;
			break;
		}
	}

	res();
	for (int i = 0; i < 300; i++) {
		if (tempBuffer.putToEnd(i) == RB_ERROR::BUFFER_FULL) 
		{
			std::cout << " buffer is full.... " << i  << std::endl;
			break;
		}
	}
	tempBuffer.flush();
	res();


	return 0;
}
