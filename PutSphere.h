#ifndef PUTSPHERE_H_INCLUDED
#define PUTSPHERE_H_INCLUDED
#include "FiguraGeometrica.h"
#include "sculptor.h"

class PutSphere : public FiguraGeometrica{
    int xc, yc, zc, radius;
public:
    PutSphere(int xc, int yc, int zc, int radius, float r, float g, float b, float a);
    ~PutSphere(){};
    void draw(sculptor &s);

};


#endif // PUTSPHERE_H_INCLUDED
