#ifndef _node_h_
#define _node_h_

#include <iostream>


struct Data {
	static int countEl;
	int nameData = 0;
	Data() {
		countEl++; 
		nameData = countEl;
#ifdef SHOW_CONSTR_DATA
		std::cout << countEl << " " <<  __func__ << std::endl; 
#endif
	}
	Data(Data& _new_data) {
		std::cout << __func__ << " copy constructor" << std::endl;
		nameData = _new_data.nameData;
	}
	~Data() {
#ifdef SHOW_CONSTR_DATA
		std::cout << nameData << " " << __func__ << std::endl; 
#endif
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
struct Data GetNode(struct Node* Head, int num_node, bool del);
void ShowElements(struct Node* Head);


#endif
