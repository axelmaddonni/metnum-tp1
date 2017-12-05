#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

using std::unique_ptr;
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::to_string;

#define _USE_MATH_DEFINES
#include <math.h>

#include "TP.h"
//#include "src/Gauss.cpp"
//#include "src/Solve.cpp"
//#include "src/LU.cpp"
//#include "lautaro.cpp"

////// Para imprimir

void imprimirMatriz( std::vector< std::vector<double> > &matriz , ofstream &out) {
	for (int i=0; i < matriz.size(); i++) {
		for (int j=0; j < matriz.size(); j++) {
			out << to_string(matriz[i][j]) << "\t";
		}
		out << std::endl;
	}
	out  << std::endl;

out.close();
}

void imprimirVector( std::vector<double> &vec , ofstream &out) {
	int size = vec.size();
	int i,j;
	for (i=0; i<size; i++) {
		out << vec[i] << "\t";
	}
	out << std::endl << std::endl;
}

/**********************MAIN***********************/

int main (int argc, char **argv){

	////// Inicio Parametros //////////
        

        

        
	string entrada = string(argv[1]);
	string salida = string(argv[2]);
	int fact = std::stoi(argv[3]); // 0: EG, 1: LU, 2:EG con optimizacion para matriz banda
        //string salidaMatrizInicial = string(argv[4]);
        
        

	double ri;
	double re;
	double m; //cantidad de angulos 
	double n; //cantidad de radios
	double iso;
	double ninst;

	ifstream in;
	in.open(entrada);
	in >> ri;
	in >> re;
	in >> m;
	m--; //porque por parámetro me pasan m+1
	in >> n;
	in >> iso;
	in >> ninst;


	double deltaR = (re - ri)/m;
	double deltaA = (2 * M_PI)/n;

	//////// Terminé de iniciar parámetros ///////////

	/////// Creo Matriz Adjunta /////////



	/////// Creo Matriz A /////////

	vector< vector<double> > matrizA = crearMatriz(n, m, ri, deltaR, deltaA);



	////////////////////////////////////

	/* esto es para probar como queda la matriz impresa y ver que queda banda
	*/

	ofstream out;

	out.open(salida);



	//imprimirMatriz(matrizA, out);



        ofstream outMat;

        ofstream isoStream;
        isoStream.open("isoterma.out");

        //outMat.open(salidaMatrizInicial);

	//imprimirVector(matrizAdjunta, outMat);
        //imprimirMatriz(matrizA, outMat);

	//vector< vector<double> > matrizB = crearMatriz(3, 3, ri, deltaR, deltaA);
        //imprimirMatriz(matrizB, outMat);
	if (fact % 2 == 0)
        {
            //Resuelvo por Eliminación Gaussiana
            
            for (int j = 0; j < ninst; j++)
            {
                vector<vector<double>> copia(vector<vector<double>>((vector<vector<double>>&) matrizA));

                vector<double> matrizAdjunta(n*(m+1));

                for (int i = 0; i < n; i++)
                {
                    in >> matrizAdjunta[i];
                }
                for (int i = (n*(m+1) - n); i < n*(m+1); i++)
                {
                    in >> matrizAdjunta[i];
                }

                unique_ptr<vector<double>> res;

                if (fact == 0) 
                {
                    EliminacionGaussiana(copia, matrizAdjunta);
                    res = ResolverTriSuperior(copia, matrizAdjunta);
                }
                else
                {
                    EliminacionParaBanda(copia, n + 1, n + 1, matrizAdjunta);
                    res = ResolverTriSuperiorBanda(copia, n + 1, matrizAdjunta);
                }

                unique_ptr<vector<double>> isoVec = calcularIsoterma(*res, m + 1, n, iso, ri, re);
                imprimirResultado(*res, out);
                imprimirResultado(*isoVec, isoStream);

                if (estaEnPeligro(*isoVec, ri, re, 0.8)){
                	std::cout << "PELIGRO" << std::endl;
                }else{
                	std::cout << "No es peligroso" << std::endl;
                }

                if (estaEnPeligroPromedio(*isoVec, ri, re, 0.8)){
                	std::cout << "PELIGRO" << std::endl;
                }else{
                	std::cout << "No es peligroso" << std::endl;
                }

                /*
                   for (int i = 0; i < matrizA.size(); i++)
                   {
                   outMat << matrizA[i][i] << '\n';
                   }
                 */
                //mostrarVector(*res);

            }
	}
        else
        {
            //Resuelvo por LU

            descomposicionLU(matrizA);

            for (int j = 0; j < ninst; j++)
            {
                vector<double> matrizAdjunta(n*(m+1));

                for (int i = 0; i < n; i++)
                {
                    in >> matrizAdjunta[i];
                }
                for (int i = (n*(m+1) - n); i < n*(m+1); i++)
                {
                    in >> matrizAdjunta[i];
                }

                vector<double> sol = *resolverLU(matrizA, matrizAdjunta);
                unique_ptr<vector<double>> isoVec = calcularIsoterma(sol, m + 1, n, iso, ri, re);
                imprimirResultado(sol, out);
                imprimirResultado(*isoVec, isoStream);
            }
	}



        outMat.close();
        isoStream.close();
	out.close();
	in.close();
	return 0;

}



/**********************FUNCIONES***********************/
vector< vector<double> > crearMatriz (double n, double m, double ri, double deltaR, double deltaA){

	vector< vector<double> > matriz((m+1)*n, vector<double>((m+1)*n)); 

	//completo primeras n filas y ultimas n filas con 1s en la diagonal
	for (int i = 0; i < n; i++){
		matriz[i][i] = 1;
	}
	for (int i = (n*(m+1) - n); i < n*(m+1); i++){
		matriz[i][i] = 1;
	}

	//completo resto de las ecuaciones usando las formulas

	for (int j = 1; j < m; j++){
		double r = ri + j * deltaR;
		for (int k = 0; k < n; k++){
			//uso para calcular en la matriz la posicion j,k = n x j + k

			// t j,k
			//matriz[n*j + k][n*j + k] = 1; //IMPRIMO UNOS PARA PROBAR SI QUEDA BANDA Y VER LA MATRIZ ALINEADA
			matriz[n*j + k][n*j + k] = (-2*pow(r,2)*pow(deltaA, 2) + r*deltaR*pow(deltaA, 2) - 2*pow(deltaR, 2))/(pow(deltaR, 2)*pow(r, 2)*pow(deltaA, 2));
			
			// t j-1, k
			//matriz[n*j + k][n*(j-1) + k] = 1;
			matriz[n*j + k][n*(j-1) + k] = (r - deltaR)/(pow(deltaR, 2)* r);

			// t j+1, k
			//matriz[n*j + k][n*(j+1) + k] = 1;
			matriz[n*j + k][n*(j+1) + k] = 1 / pow(deltaR, 2);

			// t j, k-1
			//matriz[n*j + k][n*j + k-1] = 1;
			matriz[n*j + k][n*j + (k - 1 > 0? k - 1 : n - 1)] = 1 / (pow(r, 2)*pow(deltaA, 2));

			//t j, k+1
			//matriz[n*j + k][n*j + k+1] = 1;
			matriz[n*j + k][n*j + (k + 1 < n - 1? k + 1 : 0)] = 1 / (pow(r, 2)*pow(deltaA, 2));
			
		}
	}
	
	return matriz;

}


void imprimirResultado( std::vector<double> &vec , ofstream &out) 
{
	int size = vec.size();
	out.precision(6);
	for (int i=0; i<size; i++) {
		out << to_string(vec[i]) << std::endl;
	}
}
