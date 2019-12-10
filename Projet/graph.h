//#include <string>
//#include <vector>
//#include <set>
//#include <tuple>
#include <array>
#include <limits>
#include <ostream>

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
	Graph();
	~Graph()=default;

	void Init(unsigned int);
	
	void SetOriented(bool o){oriented=o;}
	void Arc(int,int,T);

	/*
	Information (const)
	
	We have << Graph
	and the usual getters
	*/
	void OutStream(std::ostream & os);
	template<class U> friend std::ostream & operator<<(std::ostream &, Graph<U> const &);

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