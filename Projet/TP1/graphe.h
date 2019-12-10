 #include <string>
#include <vector>
#include <set>
#include <tuple>
#include <array>
#include <limits>

const int Max = 1000;

class Graphe{
  private :
    std::array<std::array<double,Max>, Max> matrice; //
    std::array<bool,Max> parcourus;
    int nbSommets; //
    bool oriente; //
    
  public :

    Graphe(); //
    ~Graphe()=default; //
    void initMatrice(int nbSommets); //
    int getNbSommets(int i) {return nbSommets;} //
    void setOriente(bool o) {oriente = o;}; //
    void ajoutArc(int,int,double); //
    void affichageMatrice(); 
    void parcoursProfondeur(); //
    void explorer(int s); //
    void parcoursLargeur(); //
};
