#include <iostream>
#include <memory>
#include <vector>
#include "TP.h"

using std::unique_ptr;
using std::vector;

unique_ptr<vector<double>> ResolverTriSuperior (vector<vector<double>>& mat, vector<double>& adjunta)
{
    int h = mat.size();
    int w = mat[0].size();
    vector<double> *solPtr = new vector<double>(h);
    unique_ptr<vector<double>> solUPtr(solPtr);
    vector<double>& sol = *solPtr;
    for (int IndiceActual = w - 1; IndiceActual >= 0; IndiceActual--)
    {
        double CopiaAdjuntaActual = adjunta[IndiceActual];
        for (int IndiceResueltos = IndiceActual + 1; IndiceResueltos < w; IndiceResueltos++)
        {
            CopiaAdjuntaActual -= sol[IndiceResueltos] * mat[IndiceActual][IndiceResueltos];
        }
        CopiaAdjuntaActual /= mat[IndiceActual][IndiceActual];
        sol[IndiceActual] = CopiaAdjuntaActual;
    }
    return solUPtr;
}

unique_ptr<vector<double>> ResolverTriSuperiorBanda (vector<vector<double>>& mat, int BandaAncho, vector<double>& adjunta)
{
    int h = mat.size();
    int w = mat[0].size();
    vector<double> *solPtr = new vector<double>(h);
    unique_ptr<vector<double>> solUPtr(solPtr);
    vector<double>& sol = *solPtr;
    for (int IndiceActual = w - 1; IndiceActual >= 0; IndiceActual--)
    {
        double CopiaAdjuntaActual = adjunta[IndiceActual];
        for (int IndiceResueltos = IndiceActual + 1; IndiceResueltos < IndiceActual + BandaAncho; IndiceResueltos++)
        {
            CopiaAdjuntaActual -= sol[IndiceResueltos] * mat[IndiceActual][IndiceResueltos];
        }
        CopiaAdjuntaActual /= mat[IndiceActual][IndiceActual];
        sol[IndiceActual] = CopiaAdjuntaActual;
    }
    return solUPtr;
}

unique_ptr<vector<double>> ResolverTriInferior (vector<vector<double>>& matLower, vector<double>& adjunta)
{
    int h = matLower.size();
    int w = matLower[0].size();
    vector<double> *solPtr = new vector<double>(h);
    unique_ptr<vector<double>> solUPtr(solPtr);
    vector<double>& sol = *solPtr;
    for (int IndiceActual = 0; IndiceActual < w; IndiceActual++)
    {
        double CopiaAdjuntaActual = adjunta[IndiceActual];
        for (int IndiceResueltos = 0; IndiceResueltos < IndiceActual; IndiceResueltos++)
        {
            CopiaAdjuntaActual -= sol[IndiceResueltos] * matLower[IndiceActual][IndiceResueltos];
        }
            CopiaAdjuntaActual /= matLower[IndiceActual][IndiceActual];
            sol[IndiceActual] = CopiaAdjuntaActual;
    }
    return solUPtr;
}

unique_ptr<vector<double>> ResolverLU (vector<vector<double>>& matUpper, vector<vector<double>>& matLower, vector<double>& adjunta)
{
    unique_ptr<vector<double>> sol1 = ResolverTriInferior(matLower, adjunta);
    unique_ptr<vector<double>> sol2 = ResolverTriSuperior(matUpper, *sol1);
    return sol2;
}

