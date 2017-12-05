#include <memory>
#include <vector>
#include <cmath>
#include "TP.h"

using std::unique_ptr;
using std::vector;
using std::abs;

unique_ptr<vector<double>> calcularIsoterma (vector<double>& res, int m, int n, int iso, int ri,  int re)
{
    unique_ptr<vector<double>> isoVecUPtr(new vector<double>(n));
    vector<double>& isoVec = *isoVecUPtr;
    double deltaR = ((double) (re - ri)) / m;
    for (int iteradorAngulo = 0; iteradorAngulo < n; iteradorAngulo++)
    {
        int masCercanoIso = 0;
        for (int iteradorRadio = 0; iteradorRadio < m + 1; iteradorRadio++)
        {
            if (abs(res[iteradorRadio * n + iteradorAngulo] - (double) iso) <= abs(res [masCercanoIso * n + iteradorAngulo] - (double) iso))
            {
                masCercanoIso = iteradorRadio;
            }
        }
        isoVec [iteradorAngulo] = ri + deltaR * masCercanoIso;
    }
    return isoVecUPtr;
}

bool estaEnPeligro (vector<double>& isoVec, int ri, int re, double indiceDePeligro)
{
    double sePudrioTodo = ((double) re - ri) * indiceDePeligro;
    for (int i = 0; i < isoVec.size(); i++)
    {
        if (isoVec [i] >= sePudrioTodo) return true;
    }
    return false;
}

bool estaEnPeligroPromedio (vector<double>& isoVec, int ri, int re, double indiceDePeligro)
{
    double sePudrioTodo = ((double) re - ri) * indiceDePeligro;
    int peligrosos = 0;
    for (int i = 0; i < isoVec.size(); i++)
    {
        if (isoVec [i] >= sePudrioTodo) peligrosos++;
    }
    if (peligrosos/isoVec.size() >= 0.4 ){
        return true;
    }else{
        return false;
    }
}

unique_ptr<vector<double>> calcularIsotermaPromedio (vector<double>& res, int m, int n, int iso, int ri,  int re)
{
    unique_ptr<vector<double>> isoVecUPtr(new vector<double>(n));
    vector<double>& isoVec = *isoVecUPtr;
    double deltaR = ((double) (re - ri)) / m;
    for (int iteradorAngulo = 0; iteradorAngulo < n; iteradorAngulo++)
    {
        int masCercanoIsoMenor = 0;
        int masCercanoIsoMayor = 0;
        bool primMenor = true;
        bool primMayor = true;
        for (int iteradorRadio = 0; iteradorRadio < m + 1; iteradorRadio++)
        {
            if (res[iteradorRadio * n + iteradorAngulo] > iso) {
                if (primMayor) {
                    masCercanoIsoMayor = iteradorRadio;
                    primMayor = false;
                } else if (abs(res[iteradorRadio * n + iteradorAngulo] - (double) iso) <= abs(res [masCercanoIsoMayor * n + iteradorAngulo] - (double) iso) ) {
                    masCercanoIsoMayor = iteradorRadio;
                }
            } else {
                if (primMenor) {
                    masCercanoIsoMenor = iteradorRadio;
                    primMenor = false;
                } else if (abs(res[iteradorRadio * n + iteradorAngulo] - (double) iso) <= abs(res [masCercanoIsoMenor * n + iteradorAngulo] - (double) iso) ) {
                    masCercanoIsoMenor = iteradorRadio;
                }
            }
        }
        if (primMayor) {
            isoVec[iteradorAngulo] = ri + deltaR * masCercanoIsoMenor;
        } else if (primMenor) {
            isoVec[iteradorAngulo] = ri + deltaR * masCercanoIsoMayor;
        } else {
            isoVec[iteradorAngulo] = (ri + deltaR * masCercanoIsoMayor) + ((iso - res[masCercanoIsoMayor * n + iteradorAngulo]) * deltaR / (res[masCercanoIsoMenor * n + iteradorAngulo] - res[masCercanoIsoMayor * n + iteradorAngulo]));
        }
   }
    return isoVecUPtr;
}