/*
 * Celula.cpp
 *
 *  Created on: 11 oct. 2022
 *      Author: luis
 */

#include "Celula.h"

#include <iostream> //eliminar

Celula::Celula(unsigned int maximoDeCargaGenetica) {
	//falta validar
	estado=muerto;
	cantidadMaximaDeGenes = 3;
	genes = new std::vector<Gen*>;
	this->maximoDeCargaGenetica = maximoDeCargaGenetica;
	forma = FormaDeTransmision( rand() % 3);

	for(unsigned int i = 0; i < this->cantidadMaximaDeGenes; i++){
		genes->push_back( new Gen(this->maximoDeCargaGenetica) );
	}
}

Celula::Celula(Celula* otraCelula){
	//falta validar
	estado=otraCelula->getEstado();
	forma = otraCelula->getFormaDeTransmision();
	cantidadMaximaDeGenes = otraCelula->getCantidadMaximaDeGenes();
	genes = new std::vector<Gen*>;
	this->maximoDeCargaGenetica = otraCelula->getMaximoDeCargaGenetica();
	for(unsigned int i = 0; i < cantidadMaximaDeGenes; i++){
		genes->push_back( new Gen(this->maximoDeCargaGenetica) );
		(*genes)[i]->setCargaGenetica( (*otraCelula->getGenes())[i]->getCargaGenetica()   );
	}
	/*for(unsigned int i = 0; i < cantidadMaximaDeGenes; i++){
		std::cout << "valor de la carga copia: " << (*otraCelula->getGenes())[i]->getCargaGenetica() << std::endl;
		(*genes)[i]->setCargaGenetica( (*otraCelula->getGenes())[i]->getCargaGenetica()   );
	} */
}


void Celula::setEstado(Estado estado){
	//validar
	this->estado = estado;
}

Estado Celula::getEstado(){ return estado;}

std::vector<Gen*>* Celula::getGenes(){return genes;}

void Celula::matarGenes(){
	for(unsigned int i = 0; i < cantidadMaximaDeGenes; i++){
		(*genes)[i]->setCargaGenetica(0);
	}
}

void Celula::setFormaDeTransimision(FormaDeTransmision forma){
	//validar
	this->forma = forma;
}

FormaDeTransmision Celula::getFormaDeTransmision(){return forma;}

unsigned int  Celula::getCantidadMaximaDeGenes(){return cantidadMaximaDeGenes; }

unsigned int  Celula::getMaximoDeCargaGenetica(){return maximoDeCargaGenetica; }
/*
Celula::Celula() {
	this->gen.genAlfa=0;
	this->gen.genBeta=0;
	this->gen.genGamma=0;
	this->estado=muerto;
}

Celula::Celula(Celula &otraCelula){
    this->gen.genAlfa=otraCelula.getGenes().genAlfa;
    this->gen.genBeta=otraCelula.getGenes().genBeta;
    this->gen.genGamma=otraCelula.getGenes().genGamma;
    this->estado=otraCelula.getEstado();
}
void Celula::setEstado(Estado estado){
	this->estado=estado;
}


void Celula::setCelulaViva(){

	this->estado=vivo;
}



void Celula::setCelulaVecina(Celula* vecina, int i){
	this->vecinos[i]=vecina;
}

Celula* Celula::getVecina(int i){
	Celula* vecina=vecinos[i];
	return vecina;
}

Estado Celula::getEstado(){
	return this->estado;
}

Gen Celula::getGenes(){
	return this->gen;
}

void Celula::setGenAlfa(unsigned int valor){
	this->gen.genAlfa=valor;
}
void Celula::setGenBeta(unsigned int valor){
	this->gen.genBeta=valor;
}
void Celula::setGenGamma(unsigned int valor){
	this->gen.genGamma=valor;
}
void Celula::matarGenes(){
	this->gen.genAlfa=0;
	this->gen.genBeta=0;
	this->gen.genGamma=0;
}

void Celula::setGenesRAND(){
	unsigned int genAleatorio1=rand();
	unsigned int genAleatorio2=rand();
	unsigned int genAleatorio3=rand();
	this->gen.genAlfa=(genAleatorio1 % 256);
	this->gen.genBeta=(genAleatorio2 % 256);
	this->gen.genGamma=(genAleatorio3 % 256);
}
Celula::~Celula() {
	// TODO Auto-generated destructor stub
}
*/
