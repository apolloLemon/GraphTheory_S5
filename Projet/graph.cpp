#include "graph.h"
#include <iostream>

template <typename T>

std::ostream & operator<< (std::ostream & os, Graph<T> const & g){
	 os << g.Arc(0,0);
	 return os;
}

void Graph::Init(unsigned int nV) {
	for(auto i=0;i<nV;i++)
		for(auto j=0;j<nV;j++)
			adjacencyMatrix[i][j]=std::numeric_limits<double>::infinity();
	std::cout << "Graph::Init of size "<<nV<<" completed\n";
}