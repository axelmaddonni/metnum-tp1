#include <vector>
#include <memory>
#include "TP.h"

using std::vector;
using std::unique_ptr;

unique_ptr<vector<vector<double>>> DescomposicionLU (vector<vector<double>>& matUpper)
{
    int h = matUpper.size();
    int w = matUpper[0].size();
    vector<vector<double>> *matLowerPtr = new vector<vector<double>>(h);
    unique_ptr<vector<vector<double>>> matLowerUPtr(matLowerPtr);
    vector<vector<double>>& matLower = *matLowerPtr;
    for (int i = 0; i < h; i++) matLower[i] = vector<double>(w); 
    for (int i = 0; i < h; i++) 
    {
        for (int j = 0; j < w; j++)
        {
            if (i == j) matLower[i][i] = 1;
            else matLower[i][j] = 0;
        }
    }
    for (int PivoteDiagonal = 0; PivoteDiagonal < w; PivoteDiagonal++)
    {
        for (int FilaActual = PivoteDiagonal + 1; FilaActual < h; FilaActual++)
        {
            if ( matUpper [FilaActual][PivoteDiagonal] != 0)
            {
                double coeficiente = matUpper [FilaActual][PivoteDiagonal] / matUpper [PivoteDiagonal][PivoteDiagonal];
                matLower[FilaActual][PivoteDiagonal] = coeficiente;
                for (int ColumaEnSuma = PivoteDiagonal; ColumaEnSuma < w; ColumaEnSuma++)
                {
                    matUpper [FilaActual][ColumaEnSuma] -= matUpper [PivoteDiagonal][ColumaEnSuma] * coeficiente;
                }
            }
        }
    }
    return matLowerUPtr;
}
