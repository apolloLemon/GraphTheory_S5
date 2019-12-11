#include "graph.h"
#include <iostream>

int main() {
	//Graph<short> shortgraph;
	Graph intgraph;
	intgraph.SetOriented(true);
	intgraph.Init(5);
	intgraph.Arc(0,4,9);
	std::cout << intgraph.Arc(0,4) << std::endl;
	std::cout << intgraph << std::endl;

	return 0;
}