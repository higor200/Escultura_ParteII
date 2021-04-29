#ifndef PUTELLIPSOID_H_INCLUDED
#define PUTELLIPSOID_H_INCLUDED
#include "FiguraGeometrica.h"
#include "sculptor.h"

class PutEllipsoid : public FiguraGeometrica{
    int xc, yc, zc, rx, ry, rz;
public:
    PutEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz,
                    float r, float g, float b, float a);
    void draw(sculptor &s);
    ~PutEllipsoid(){};
};



#endif // PUTELLIPSOID_H_INCLUDED
