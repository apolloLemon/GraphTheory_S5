#include "graph.h"
#include <iostream>

int main() {
	//Graph<short> shortgraph;
	Graph<int> intgraph;
	intgraph.SetOriented(true);
	intgraph.Init(5);
	intgraph.Arc(0,4,9);
	std::cout << intgraph.Arc(0,4) << std::endl;
	std::cout << intgraph << std::endl;
/*

	Graph<double> doublegraph;
	doublegraph.Init(5);
	doublegraph.Arc(0,4,9.3);
	std::cout << doublegraph.Arc(0,4) << std::endl;
	std::cout << doublegraph << std::endl;

*/
	return 0;
}