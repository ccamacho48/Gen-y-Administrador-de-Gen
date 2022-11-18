/*
 * Gen.cpp
 *
 *  Created on: 13 nov 2022
 *      Author: camac
 */



#include "Gen.h"

Gen::Gen(unsigned int maximoDecargaGenetica, unsigned int cargaGenetica){
	verificar(maximoDecargaGenetica, cargaGenetica);

	this->cargaGenetica = cargaGenetica;
	this->maximoDeCargaGenetica = maximoDecargaGenetica;
}

Gen::Gen(unsigned int maximoDeCargaGenetica){
	verificar(maximoDeCargaGenetica, 0);
	this->maximoDeCargaGenetica = maximoDeCargaGenetica;
	this->cargaGenetica = 0;
}



unsigned int Gen::getCargaGenetica(){
		return cargaGenetica;
}

void Gen::setCargaGenetica(int cargaGenetica) {
	verificar(maximoDeCargaGenetica, cargaGenetica);
		this->cargaGenetica = cargaGenetica;
}

unsigned int Gen::getMaximoDeCargaGenetica()  {
	return maximoDeCargaGenetica;
}

void Gen::verificar(unsigned int maximoDeCargaGenetica, unsigned int cargaGenetica ){
	if(maximoDeCargaGenetica < 0)
		throw "maximoDeCargaGenetica debe ser un entero positivo";
	if( cargaGenetica < 0 || cargaGenetica > maximoDeCargaGenetica)
		throw "cargaGenetica debe ser un entero mayor o igual que cero y menor o igual que maximoDeCArgaGenetica";
}
