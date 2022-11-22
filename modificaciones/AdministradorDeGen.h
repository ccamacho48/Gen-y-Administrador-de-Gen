
#ifndef SRC_ADMINISTRADORDEGEN_H_
#define SRC_ADMINISTRADORDEGEN_H_
#include "Gen.h"
//#include "E:\Algos2\04-Estructuras-lineales-main\Lista con Template\Lista.h"
#include <vector>
class AdministradorDeGen {
private:
	unsigned int maximoDeCargaGenetica;
public:

	/*
	 * pre: maximoDeCargaGenetica es un entero positivo
	 * pos: asigna a maximoDeCargaGenetica el valor pasado
	 */
	AdministradorDeGen(unsigned int maximoDeCargaGenetica);

	/*
	 * pre: genes apunta a un array  no vacio
	 * pos: devuelve un gen con  maximoDeCargaGenetica en  "maximoDeCargaGenetica" y cargaGenitca con el promedio de las cargas geneticas
	 * de los genes del array
	 */
	Gen* generarGenPorPromedio(std::vector<Gen*>* genes);

	/*
	 * pre: genes apunta a una array no vacio
	 * pos: devuelve un gen con  maximoDeCargaGenetica en  "maximoDeCargaGenetica" y cargaGenitca con la maxima  carga genetica  de los
	 *  genes del array
	 */
	Gen* generarGenPorMaximo(std::vector<Gen*>* genes);

	/*
	 * pre: genes apunta a un array no vacio
	 * pos: devuelve un gen con  maximoDeCargaGenetica en  "maximoDeCargaGenetica" y cargaGenitca con el punto medio entre la minima y
	 *  maximima carga genetica siendo estos numeros primos. De no haber maximo y minimo numeros primos, lo carga en 0
	 */
	Gen* generarGenPorCargaMediaDePrimos(std::vector<Gen*>* genes);

	//virtual ~AdministradorDeGen();

private:
	/*
	 * pre:
	 * pos: lanza un error si genes es un puntero nulo o apunta  a un array vacio
	 */
	void verificar(std::vector<Gen*>*  genes);

	/*
	 * pre:
	 * pos: lanza un error si numeros es un puntero nulo o apunta a un array vacio
	 */
	void verificar(std::vector<unsigned int>* numeros);

	bool esPrimo(int numero);


	/*
	 * pre: numeros apunta a un arrat no vacios
	 */
	unsigned int valorMaximo(std::vector<unsigned int>* numeros);
	unsigned int valorMinimo(std::vector<unsigned int>* numeros);

};

#endif /* SRC_ADMINISTRADORDEGEN_H_ */
