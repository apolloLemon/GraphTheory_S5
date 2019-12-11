//#include <string>
//#include <vector>
//#include <set>
//#include <tuple>
#include <array>
#include <limits>
#include <ostream>
#include <iostream>

template<typename T>
class Graph {
/*
Types and Constants

Here are defined:
	the legal types of graph,
	the Max size of any graph,
and the data structure for the Adjacency Matrix
*/
static_assert(
		std::is_same<T, double>::value 
	|| 	std::is_same<T, float>::value
	|| 	std::is_same<T, int>::value
	|| 	std::is_same<T, long>::value,
	"needs to be int, float, double, long");

public:
	static const unsigned int MAX = 1000;
	typedef std::array<std::array<T, MAX>,MAX> Matrix;
//End of Types and Constants


/*
General Graph Properties and Methods

Here are the "basic graph" attributes and methods
*/
private:
	//Adjacency Matrix
	Matrix adjacencyMatrix; //Adjacency Matrix T weight
	unsigned int vertexCount; //number of veticies
	bool oriented;

public:
	//Constructors, initators, setters
	//Graph<T>();
	//~Graph<T>()=default;

	void Init(unsigned int);
	
	void SetOriented(bool o){oriented=o;}
	void Arc(int,int,T);

	/*
	Information (const)
	
	We have << Graph
	and the usual getters
	*/
	std::ostream & OutStream(std::ostream & os);
	template<typename U> friend std::ostream & operator<<(std::ostream &, Graph<U> const &);

	//Getters
	int VertexCount() const {return vertexCount;}
	T Arc(int src,int dst) const {return adjacencyMatrix[src][dst];}

	//Algorithms
private:
	std::array<bool, MAX> seen;
public:
	void DepthFirstSearch();
	void BreadthFirstSearch();
	void Explore(int);
//End Of General Graph Stuff
};
/*
class CityGraph : public Graph {
private:

};
*/





/*

Because of using templates:
here all da code

*/
template <typename T>
std::ostream & operator<< (std::ostream & os, Graph<T> & g){
	 g.OutStream(os);
	 return os;
}
template <typename T>
std::ostream & Graph<T>::OutStream(std::ostream & os) {
	for(unsigned int i=0;i<vertexCount;i++){
		for(unsigned int j=0;j<vertexCount;j++)
			os << adjacencyMatrix[i][j] << "\t";
		os << "\n";
	}
	return os;
}

/*
General graph methods
init 	adjmtrx=0
Arc 	adjmtrx[s][d]=w
*/
template <typename T>
void Graph<double>::Init(unsigned int nV) {
	vertexCount=nV;
	for(unsigned int i=0;i<vertexCount;i++)
		for(unsigned int j=0;j<vertexCount;j++)
			adjacencyMatrix[i][j]=std::numeric_limits<T>::infinity();
	//std::cout << "Graph::Init of size "<<vertexCount<<" completed\n";
}
template <typename T>
void Graph<int>::Init(unsigned int nV) {
	vertexCount=nV;
	for(unsigned int i=0;i<vertexCount;i++)
		for(unsigned int j=0;j<vertexCount;j++)
			adjacencyMatrix[i][j]=std::numeric_limits<T>::max();
	//std::cout << "Graph::Init of size "<<vertexCount<<" completed\n";
}
//template <typename T>
//void Graph<T>::SetOriented(bool o) in .h
template <typename T>
void Graph<T>::Arc(int src, int dst, T w) {
	if(!oriented) adjacencyMatrix[dst][src]=w;
	adjacencyMatrix[src][dst]=w;
}



