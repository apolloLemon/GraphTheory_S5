#include <limits>
double inf = std::numeric_limits<double>::infinity();
//exo2
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>

typedef std::vector< std::vector<int> > i2d;

void addEdge(i2d & ma, int src, int dst, int w){
	ma[src][dst]=w;
}
void EdgeAdder(i2d & ma, int src, int dst, int w, bool type){
	if(type)
		addEdge(ma,src,dst,w);
	else
		addEdge(ma,src,dst,w);addEdge(ma,dst,src,w);
}
void LoadGraph(std::string nom,i2d & ma){
	std::ifstream fichier(nom);
	std::string line;
	bool graphType=false;
	int size, src, dst, weight;
	while(getline(fichier,line)){
		switch(line[0]){
			case 'o':
				if(line[2]=='g' && line[3]=='o')
					graphType=true;
				break;
			case 'v':
				size=stoi(line.substr(2));
				ma.resize(size+1, std::vector<int>(size+1));
				break;
			case 'e':
	std::cout << "src" << std::endl;
				src=stoi(line.substr(2,2));
				dst=stoi(line.substr(4,2));
				weight=stoi(line.substr(6,2));
				EdgeAdder(ma, src , dst , weight , graphType);
				break;
			case 'c':
			default:
				break;
		}
	}
}// exo2

