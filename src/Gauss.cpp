#include <iostream>
#include <vector>
#include "TP.h"

using std::vector;

void EliminacionGaussiana (vector<vector<double>>& mat, vector<double>& adjunta)
{
    int h = mat.size();
    int w = mat[0].size();
    for (int PivoteDiagonal = 0; PivoteDiagonal < w; PivoteDiagonal++)
    {
        for (int FilaActual = PivoteDiagonal + 1; FilaActual < h; FilaActual++)
        {
            if ( mat [FilaActual][PivoteDiagonal] != 0)
            {
                double coeficiente = mat [FilaActual][PivoteDiagonal] / mat [PivoteDiagonal][PivoteDiagonal];
                adjunta [FilaActual] -= adjunta[PivoteDiagonal] * coeficiente;
                for (int ColumaEnSuma = PivoteDiagonal; ColumaEnSuma < w; ColumaEnSuma++)
                {
                    mat [FilaActual][ColumaEnSuma] -= mat [PivoteDiagonal][ColumaEnSuma] * coeficiente;
                }
            }
        }
    }
}

void EliminacionParaBanda (vector<vector<double>>& mat, int bandaAltura, int bandaAncho, vector<double>& adjunta)
{
    int h = mat.size();
    int w = mat[0].size();
    for (int PivoteDiagonal = 0; PivoteDiagonal < w; PivoteDiagonal++)
    {
        //corre desde la fila de abajo de la diagonal hasta la bandaAltura-iesima de abajo de la diagonal
        //el resto son 0 por la propiedad banda
        for (int FilaActual = PivoteDiagonal + 1; FilaActual < PivoteDiagonal + bandaAltura && FilaActual < h; FilaActual++)
        {
            if ( mat [FilaActual][PivoteDiagonal] != 0)
            {
                double coeficiente = mat [FilaActual][PivoteDiagonal] / mat [PivoteDiagonal][PivoteDiagonal];
                adjunta [FilaActual] -= adjunta[PivoteDiagonal] * coeficiente;
                //corre desde la columna de la diagonal hasta la bandaAncho-iesima de la derecha de la diagonal
                //el resto son 0 por la propiedad banda
                for (int ColumaEnSuma = PivoteDiagonal; ColumaEnSuma < FilaActual + bandaAncho && ColumaEnSuma < w; ColumaEnSuma++)
                {
                    mat [FilaActual][ColumaEnSuma] -= mat [PivoteDiagonal][ColumaEnSuma] * coeficiente;
                }
            }
        }
    }
}
