#include <vector>
#include <iostream>
#include "TP.h"


void descomposicionLU( std::vector< std::vector<double> > &matriz_a ) {
	int size = matriz_a.size();
	int i,j,k;
	double divisor;

	for (i=0; i<size; i++) {
		for (j=i+1; j<size; j++) {
            if (matriz_a[j][i]) {
            	//calculo el divisor
                divisor = matriz_a[j][i] / matriz_a[i][i] ;
                //lo pongo en la posición i,j (en la diagonal) ya que se que ahí debería haber un 1
                matriz_a[j][i] = divisor;
                //para cada uno de su derecha
                for (k=i+1; k<size; k++) {
                	//hago fila J - (divisor * fila I)
                   matriz_a[j][k] = matriz_a[j][k] - (divisor*matriz_a[i][k]);
                }
            }
		}
	}
	return;
}

std::vector<double>* resolverTriangular( std::vector< std::vector<double> > &matriz_a, bool superior, std::vector<double> &matriz_b ) {
	int size = matriz_a.size();
	static std::vector<double> solucion(size);
	double aux;
	int i,j, min, max;

	if (superior) {
		i=size-1;
	} else {
		i=0;
	}

	while (i>=0 && i<size) {
		//en aux se guarda la cuenta parcial y se le va restando
		aux = matriz_b[i];

		if (superior) {
			//si es superior (U) recorre la derecha de la diagonal
			min=i+1;
			max=size-1;
		} else {
			//si es inferior (L) recorre la izquierda de la diagonal
			min = 0;
			max = i-1;
		}
		j=min;
		while (j>=min && j<=max) {
			//va restando los valores que ya calculó antes
			aux = aux - (matriz_a[i][j]*solucion[j]);
			j++;
		}
		//almacena el valor calculado en la posición del vector solución
		if (superior) {
			//si es superior
			solucion[i] = aux / matriz_a[i][i];
		} else {
			//si es inferior debo tomar como que la diagonal es de "1"s
			solucion[i] = aux;
		}

		//si es superior (U) va hacia arriba, sino (L) va hacia abajo
		if (superior) {
			i--;
		} else {
			i++;
		}
	}
	return &solucion;
}

std::vector<double>* resolverLU( std::vector< std::vector<double> > &matriz_a, std::vector<double> &matriz_b ) {


	std::vector<double> *sol1;
	sol1 = resolverTriangular(matriz_a, false, matriz_b);

	std::vector<double> *sol2;
	sol2 = resolverTriangular(matriz_a, true, *sol1);

	return sol2;
}