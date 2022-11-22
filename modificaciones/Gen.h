/*
 * Gen.h
 *
 *  Created on: 13 nov 2022
 *      Author: camac
 */

#ifndef SRC_GEN_H_
#define SRC_GEN_H_

class Gen{
private:
	unsigned int maximoDeCargaGenetica;
	unsigned int cargaGenetica;
public:
	/*
	 * pre: maximoDeCargaGenetica es un entero  positivo o cero y cargaGenetica tiene un valor entre 0 inclusive y maximoDeCargaGenetica
	 * pos:  deja el Gen creado  con la carga en "cargaGenetica"y el maximo en "maximoDeCargaGenetica"
	 */
	Gen(unsigned int maximoDeCargaGenetica, unsigned int cargaGenetica);

	/*
	 * pre: maximoDeCargaGenetica es un entero  positivo o cero
	 * pos:  deja el Gen creado con con la carga en 0 y el maximo en "maximoDeCargaGenetica"
	 */
	Gen(unsigned int maximoDeCargaGenetica);

//	~Gen();

	/*
	 * pre:-
	 * pos: devuelve la cargaGenetica del Gen
	 */
	unsigned int getCargaGenetica();

	/*
	 *  pre: cargaGenetica es un valor entre 0 y maximoDeCargaGenetica inclusives
	 *  pos: cambia el valor de cargaGenetica
	 */
	void setCargaGenetica(int cargaGenetica);

	/*
	 * pre:-
	 * pos: devuelve el valor de maximoDeCargaGenetica
	 */
	unsigned int getMaximoDeCargaGenetica();

private:
	/*
	 * pre:-
	 * pos: da error si maximoDeCargaGenetica o cargaGenetica no respeta los rangos
	 */
	void verificar(unsigned int maximoDecargaGenetica, unsigned int cargaGenetica);
};
#endif /* SRC_GEN_H_ */



