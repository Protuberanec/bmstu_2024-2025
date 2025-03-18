#pragma once 

#include <iostream>


struct Data {
	static int countEl;
	int nameData = 0;
	Data() {
		countEl++; 
		nameData = countEl;
		std::cout << countEl << " " <<  __func__ << std::endl; 
	}
	~Data() {
		std::cout << nameData << " " << __func__ << std::endl; 
		countEl--;
	}

};


struct Node {
	Node* next;
	Data* data;
	Node();
	~Node();
};

void AddNode(struct Node* Head);
void ShowElements(struct Node* Head);
