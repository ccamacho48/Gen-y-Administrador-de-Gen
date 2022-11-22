/*
 * Celula.h
 *
 *  Created on: 11 oct. 2022
 *      Author: luis
 */

#ifndef CELULA_H_
#define CELULA_H_

#include <random>
#include "Gen.h"
#include <vector>

enum Estado{vivo,muerto};
enum FormaDeTransmision{Promedio,Primos,Maximo};

/*
struct Gen{
	unsigned int genAlfa;
	unsigned int genBeta;
	unsigned int genGamma;
}; */

/*
class Celula {
private:
	Gen gen;
	Estado estado;
	Celula* vecinos[26];
	FormaDeTransmision forma;
public:
	static const int cantidadDeVecinos=26;
	Celula();
	Celula(Celula &otraCelula);
	void setEstado(Estado estado);
	void setGenAlfa(unsigned int valor);
	void setGenBeta(unsigned int valor);
	void setGenGamma(unsigned int valor);
	void setCelulaViva();
	void setCelulaVecina(Celula* vecina, int i);
	Celula* getVecina(int i);
	Estado getEstado();
	Gen getGenes();
	void setGenesRAND();
	void matarGenes();
	virtual ~Celula();
}; */

class Celula{
private:
	Estado estado;
	std::vector<Gen*>* genes;
	unsigned int cantidadMaximaDeGenes;
	FormaDeTransmision forma;
	unsigned int maximoDeCargaGenetica;
public:
	/*
	 * pre: -
	 * post: crea una celula con FormaDeTransmision incializado aleatoreamente,estado en muerto
	 *  cantidadMaximaDeGenes en 3, genes un vector de tamanio cantidadMaximaDeGenes cuyas
	 *   cargas estan en cero y maximoDeCargaGenetica en "maximoDeCargaGenetica".
	 */
	Celula(unsigned int maximoDeCargaGenetica);

	Celula(Celula* otraCelula);

	void setEstado(Estado estado);

	Estado getEstado();

	/*
	 * devuelve el puntero a la primer posicion del vector de genes de la celula
	 *
	 */
	std::vector<Gen*>* getGenes();

	void matarGenes();

	void setFormaDeTransimision(FormaDeTransmision forma);

	FormaDeTransmision getFormaDeTransmision();

	unsigned int  getCantidadMaximaDeGenes();

	unsigned int getMaximoDeCargaGenetica();
};

#endif /* CELULA_H_ */
