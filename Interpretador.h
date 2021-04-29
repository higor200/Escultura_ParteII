#ifndef INTERPRETADOR_H_INCLUDED
#define INTERPRETADOR_H_INCLUDED
#include <vector>
#include "FiguraGeometrica.h"
#include "sculptor.h"
#include <string>
#include <stdlib.h>
using namespace std;

class Interpretador{
    int dimx, dimy, dimz;
    float r, g, b, a;
public:
    Interpretador();
    vector<FiguraGeometrica *> parse(string filename);
    int getDimx();
    int getDimy();
    int getDimz();
};


#endif // INTERPRETADOR_H_INCLUDED
