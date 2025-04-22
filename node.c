#include "node.h"
#include <endian.h>

int Node::countNode = 0;

Node::Node() : data(nullptr){
}


Node::~Node() {
	if (data != nullptr) {
		delete data;
	}
	
	while (!leafs.empty()) {
		delete leafs[0];
		leafs.erase(leafs.begin(), leafs.begin() + 1);
	}

}

