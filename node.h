#ifndef _node_h_
#define _node_h_

#include <iostream>
#include <vector>


struct Data {
};


struct Node {
	int nameNode;
	static int countNode;
	std::vector<Node*> leafs;
	Data* data;
	Node();
	~Node();
};


class Graph {
	private :
		Node* Parent;

	public :
		Graph();
		~Graph();

		void addChild(const std::string& childName, 

};



#endif
