
#include "Gen.h"
#include <iostream>
#include "AdministradorDeGen.h"
#include <vector>
#include "Celula.h"
using namespace std;
static const unsigned int MaximoDeCargaGenetica = 255;


int main(){

try{
/**********probando genes *********************
    vector<Gen*>* genes = new vector<Gen*>;


	genes->push_back( new Gen(MaximoDeCargaGenetica,0) );
	genes->push_back( new Gen(MaximoDeCargaGenetica,7) );
	genes->push_back( new Gen(MaximoDeCargaGenetica,4) );
	genes->push_back( new Gen(MaximoDeCargaGenetica,201) );

	AdministradorDeGen* administradorDeGen = new AdministradorDeGen(MaximoDeCargaGenetica);


	Gen* genResultado1 = administradorDeGen->generarGenPorPromedio(genes);
	Gen* genResultado2 = administradorDeGen->generarGenPorMaximo(genes);
	Gen* genResultado3 = administradorDeGen->generarGenPorCargaMediaDePrimos(genes);
	cout << genResultado1->getCargaGenetica() << endl;
	cout << genResultado2->getCargaGenetica() << endl;
	cout << genResultado3->getCargaGenetica() << endl;

*/

/* **********probando celulas ********************* */

	Celula celula1(MaximoDeCargaGenetica);
	cout << "Mostrando estado de celula1: " << celula1.getEstado() << endl;
	celula1.setEstado(vivo);
	cout << "Mostrando estado cambiado: " << celula1.getEstado() << endl;
	cout << "Mostrando cantidadMaximaDeGenes: " << celula1.getCantidadMaximaDeGenes() << endl;
	cout << "Mostrando maximoDeCargaGenetica: " << celula1.getMaximoDeCargaGenetica() << endl;
	for(unsigned int i = 0; i< celula1.getCantidadMaximaDeGenes(); i++){

		cout << "Mostrando carga de gen "<< i + 1 << " : "  << (*celula1.getGenes())[i]->getCargaGenetica()
				<< endl;
	}

	(*celula1.getGenes())[0]->setCargaGenetica(244);
	(*celula1.getGenes())[1]->setCargaGenetica(2);
	(*celula1.getGenes())[2]->setCargaGenetica(38);

	cout << endl <<  "-----------Mostrando genes cambiados-----------" << endl;
	for(unsigned int i = 0; i< celula1.getCantidadMaximaDeGenes(); i++){

		cout << "Mostrando carga de gen "<< i + 1 << " : "  << (*celula1.getGenes())[i]->getCargaGenetica()
				<< endl;
	}


	cout << endl << "------creando celula2 a partir de celula1 con el constructor de copia -------------" << endl;
	Celula celula2(&celula1);


	cout << "Mostrando estado de celula2: " << celula2.getEstado() << endl;
	cout << "Mostrando cantidadMaximaDeGenes: " << celula2.getCantidadMaximaDeGenes() << endl;
	for(unsigned int i = 0; i< celula2.getCantidadMaximaDeGenes(); i++){
		cout << "Mostrando carga de gen "<< i + 1 << " : "  << (*celula2.getGenes())[i]->getCargaGenetica()
		<< endl;
	}

	cout << endl << "------Modificando y mostrando celula1---------------- " << endl;
	(*celula1.getGenes())[0]->setCargaGenetica(4);
	(*celula1.getGenes())[1]->setCargaGenetica(1);
	(*celula1.getGenes())[2]->setCargaGenetica(57);
	cout << "Mostrando estado de celula1: " << celula1.getEstado() << endl;
	celula1.setEstado(vivo);
	cout << "Mostrando estado cambiado: " << celula1.getEstado() << endl;
	cout << "Mostrando cantidadMaximaDeGenes: " << celula1.getCantidadMaximaDeGenes() << endl;
	cout << "Mostrando maximoDeCargaGenetica: " << celula1.getMaximoDeCargaGenetica() << endl;
	for(unsigned int i = 0; i< celula1.getCantidadMaximaDeGenes(); i++){

		cout << "Mostrando carga de gen "<< i + 1 << " : "  << (*celula1.getGenes())[i]->getCargaGenetica()
				<< endl;
	}


	cout << endl << "------verificando que no se altero celula2---------------- " << endl;
	cout << "Mostrando estado de celula2: " << celula2.getEstado() << endl;
	cout << "Mostrando cantidadMaximaDeGenes: " << celula2.getCantidadMaximaDeGenes() << endl;
	for(unsigned int i = 0; i< celula2.getCantidadMaximaDeGenes(); i++){
		cout << "Mostrando carga de gen "<< i + 1 << " : "  << (*celula2.getGenes())[i]->getCargaGenetica()
		<< endl;
	}
	return 0;
}
catch(const char* expc){
	cout << expc << endl;
}
}
