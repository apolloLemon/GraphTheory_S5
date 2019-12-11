#include "graph.h"
#include <iostream>

/*
Information
<< graph
OutStream(stream)
*/
template <typename T>
std::ostream & operator<< (std::ostream & os, Graph<T> & g){
	 os << g.OutStream(os);
	 return os;
}
template <typename T>
void Graph<T>::OutStream(std::ostream & os) {
	for(auto i=0;i<vertexCount;i++){
		for(auto j=0;j<vertexCount;j++)
			os << adjacencyMatrix[i][j] << " ";
		os << "\n";
	}
}

/*
General graph methods
init 	adjmtrx=0
Arc 	adjmtrx[s][d]=w
*/
template <typename T>
void Graph<T>::Init(unsigned int nV) {
	for(auto i=0;i<nV;i++)
		for(auto j=0;j<nV;j++)
			adjacencyMatrix[i][j]=std::numeric_limits<double>::infinity();
	std::cout << "Graph::Init of size "<<nV<<" completed\n";
}
//template <typename T>
//void Graph<T>::SetOriented(bool o) in .h
template <typename T>
void Graph<T>::Arc(int src, int dst, T w) {
	if(!oriented) adjacencyMatrix[dst][src]=w;
	adjacencyMatrix[src][dst]=w;
}