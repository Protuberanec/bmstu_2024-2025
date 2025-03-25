#ifndef _double_ll_h_
#define _double_ll_h_

#include <iostream>


struct Data {};

struct node {
	static int count_nodes;
	int name_node;
	node* next;
	node* prev;

	Data* data;

	node();
	~node();

	void changeNameNode(int new_name) {
		name_node = new_name;
	}
};


class LL {
	private :
		node* Head;
		node* Tail;
	public :
		LL();
		~LL();
		
		void putToEnd(const Data& data);
		void putToBegin(const Data& data);
		Data getFromEnd(bool& ok);
		Data getFromBegin(bool& ok);
		void delete_element(int start, int count = 1);
		void flush();
		bool search(const Data& toSearch);
		void printLL(int start = 0, int count = -1);
		void saveToFile(const char* file_name);					   
		int totalCountNodes() const;
};


#endif
