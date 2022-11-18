
#include "Gen.h"
#include <iostream>
#include "AdministradorDeGen.h"
#include <vector>
using namespace std;
static const unsigned int MaximoDeCargaGenetica = 255;


int main(){

try{
	vector<Gen*>* genes = new vector<Gen*>;


	genes->push_back( new Gen(MaximoDeCargaGenetica,2) );
	genes->push_back( new Gen(MaximoDeCargaGenetica,7) );
	genes->push_back( new Gen(MaximoDeCargaGenetica,3) );
	genes->push_back( new Gen(MaximoDeCargaGenetica,201) );

	AdministradorDeGen* administradorDeGen = new AdministradorDeGen(MaximoDeCargaGenetica);


	Gen* genResultado1 = administradorDeGen->generarGenPorPromedio(genes);
	Gen* genResultado2 = administradorDeGen->generarGenPorMaximo(genes);
	Gen* genResultado3 = administradorDeGen->generarGenPorCargaMediaDePrimos(genes);
	cout << genResultado1->getCargaGenetica() << endl;
	cout << genResultado2->getCargaGenetica() << endl;
	cout << genResultado3->getCargaGenetica() << endl;

	return 0;
}
catch(const char* expc){
	cout << expc << endl;
}
}
