

#include "AdministradorDeGen.h"
#include <iostream>


AdministradorDeGen::AdministradorDeGen(unsigned int maximoDeCargaGenetica) {
	if( maximoDeCargaGenetica < 0 )
		throw "maximoDeCargaGenetica es un entero positivo";
	this->maximoDeCargaGenetica = maximoDeCargaGenetica;
}

void AdministradorDeGen::verificar(std::vector<Gen*>*  genes){
	if(!genes)
		throw "genes no debe ser un puntero nulo";
	if(genes->size() == 0)
		throw "genes no debe ser un array vacio";
}

Gen* AdministradorDeGen::generarGenPorPromedio(std::vector<Gen*>* genes){
	verificar(genes);

	unsigned int suma = 0;

	for(int i = 0; i < int(genes->size()); i++ ){
		suma = suma + (*genes)[i]->getCargaGenetica();
	}

	return new Gen( maximoDeCargaGenetica, suma / genes->size() );
}

Gen* AdministradorDeGen::generarGenPorMaximo(std::vector<Gen*>* genes){
	verificar(genes);

	unsigned int maximaCargaGenetica = 0;

	for(int i = 0; i < int(genes->size()); i++ ){
		if( (*genes)[i]->getCargaGenetica() > maximaCargaGenetica )
			maximaCargaGenetica = (*genes)[i]->getCargaGenetica();
	}


	return new Gen( maximoDeCargaGenetica, maximaCargaGenetica );
}


Gen* AdministradorDeGen::generarGenPorCargaMediaDePrimos(std::vector<Gen*>* genes){
	verificar(genes);

	std::vector<unsigned int>* numerosPrimos = new std::vector<unsigned int>;

	for(int i = 0; i < int(genes->size()); i++){
		if(  esPrimo(  (*genes)[i]->getCargaGenetica() ) )

			numerosPrimos->push_back(  (*genes)[i]->getCargaGenetica()  );
	}


	if(!numerosPrimos->empty())
		return new Gen( maximoDeCargaGenetica,( valorMaximo(numerosPrimos) + valorMinimo(numerosPrimos) ) / 2   );

	return new Gen( maximoDeCargaGenetica);
}


bool AdministradorDeGen::esPrimo(int numero)
{
	/* Para que un numero sea primo debe ser divisible por 1 y por el mismo */
	if(numero <= 1)  // numeros negativos, cero y uno no son primos
	    return false;
	else{
		int i=2;
	    while( i <= numero / 2 ){
		    if(numero % i == 0)
		    	return false;
		    i++;
	    }
	}
	return true;
}

unsigned int AdministradorDeGen::valorMaximo(std::vector<unsigned int>* numeros){
	verificar(numeros);

	unsigned int maximo = numeros->front();
	for(int i = 1; i < int(numeros->size()); i++){
		if( (*numeros)[i] > maximo  )
			maximo = (*numeros)[i];
	}

	return maximo;
}



unsigned int AdministradorDeGen::valorMinimo(std::vector<unsigned int>* numeros){
	verificar(numeros);

	unsigned int minimo = numeros->front();
	for(int i = 1; i < int(numeros->size()); i++){
		if( (*numeros)[i] < minimo  )
			minimo = (*numeros)[i];
	}

	return minimo;
}

void AdministradorDeGen::verificar(std::vector<unsigned int>* numeros){
	if(!numeros)
		throw "el puntero no debe ser nulo";
	if(numeros->size() == 0)
		throw "el array no debe estar vacio";
}



/*
 Gen* AdministradorDeGen::generarGenPorPromedio(Lista<Gen*>* genes){
	verificar(genes);

	unsigned int sumaDeCargasGeneticas = 0;
	genes->iniciarCursor();
	while(genes->avanzarCursor()){
			sumaDeCargasGeneticas += genes->obtenerCursor()->getCargaGenetica();
	}

	return new Gen(maximoDeCargaGenetica, sumaDeCargasGeneticas / genes->contarElementos()  );
}

 Gen* AdministradorDeGen::generarGenPorMaximo(Lista<Gen*>* genes){
	verificar(genes);

	unsigned int maximaCargaGenetica = 0;

	genes->iniciarCursor();
	while(genes->avanzarCursor()){
		if(genes->obtenerCursor()->getCargaGenetica() > maximaCargaGenetica )
			maximaCargaGenetica = genes->obtenerCursor()->getCargaGenetica();
	}

	return new Gen(maximoDeCargaGenetica, maximaCargaGenetica);
 }

 Gen* AdministradorDeGen::generarGenPorCargaMedia(Lista<Gen*>* genes){
	 verificar(genes);

	 unsigned int maximaCargaGenetica = 0,minimaCargaGenetica = 0;

	genes->iniciarCursor();
	while(genes->avanzarCursor()){
		if(genes->obtenerCursor()->getCargaGenetica() > maximaCargaGenetica )
			maximaCargaGenetica = genes->obtenerCursor()->getCargaGenetica();
		else if(genes->obtenerCursor()->getCargaGenetica() < minimaCargaGenetica)
			minimaCargaGenetica = genes->obtenerCursor()->getCargaGenetica();
	}

	return new Gen(maximoDeCargaGenetica, (maximaCargaGenetica + minimaCargaGenetica) / 2 );
 }

void AdministradorDeGen::verificar(Lista<Gen*>* genes){
	if(!genes || genes->estaVacia()){
		throw "genes debe apuntar a  una lista no vacia";
	}
}


AdministradorDeGen::~AdministradorDeGen() {
	// TODO Auto-generated destructor stub
}


*/



