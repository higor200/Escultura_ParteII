#ifndef CUTSPHERE_H_INCLUDED
#define CUTSPHERE_H_INCLUDED
#include "FiguraGeometrica.h"
#include "sculptor.h"

class CutSphere : public FiguraGeometrica{
    int xc, yc, zc, radius;
public:
    CutSphere(int xc, int yc, int zc, int radius);
    void draw(sculptor &s);
    ~CutSphere(){};
};



#endif // CUTSPHERE_H_INCLUDED
