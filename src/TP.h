#ifndef TP_H
#define TP_H 

#include <vector>
#include <memory>
#include <iostream>

using std::vector;
using std::unique_ptr;
using std::ofstream;

vector< vector<double> > crearMatriz (double n, double m, double ri, double deltaR, double deltaA);
void imprimirResultado( vector<double> &vec , ofstream &out);
unique_ptr<vector<double>> calcularIsoterma (vector<double>& res, int m, int n, int iso, int ri,  int re);
void EliminacionGaussiana (vector<vector<double>>& mat, vector<double>& adjunta);
unique_ptr<vector<double>> ResolverTriSuperior (vector<vector<double>>& mat, vector<double>& adjunta);
unique_ptr<vector<double>> ResolverTriInferior (vector<vector<double>>& matLower, vector<double>& adjunta);
unique_ptr<vector<double>> ResolverLU (vector<vector<double>>& matUpper, vector<vector<double>>& matLower, vector<double>& adjunta);
unique_ptr<vector<vector<double>>> DescomposicionLU (vector<vector<double>>& matUpper);
unique_ptr<vector<double>> calcularIsoterma (vector<double>& res, int m, int n, int iso, int ri,  int re);
bool estaEnPeligro (vector<double>& isoVec, int ri, int re, double indiceDePeligro);
bool estaEnPeligroPromedio (vector<double>& isoVec, int ri, int re, double indiceDePeligro);
void EliminacionParaBanda (vector<vector<double>>& mat, int bandaAltura, int bandaAncho, vector<double>& adjunta);
unique_ptr<vector<double>> ResolverTriSuperiorBanda (vector<vector<double>>& mat, int BandaAncho, vector<double>& adjunta);
void descomposicionLU( vector< vector<double> > &matriz_a );
vector<double>* resolverTriangular( vector< vector<double> > &matriz_a, bool superior, vector<double> &matriz_b );
vector<double>* resolverLU( vector< vector<double> > &matriz_a, vector<double> &matriz_b );

unique_ptr<vector<double>> calcularIsotermaPromedio (vector<double>& res, int m, int n, int iso, int ri,  int re);

#endif //TP_h
