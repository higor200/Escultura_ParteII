#ifndef CUTELLIPSOID_H_INCLUDED
#define CUTELLIPSOID_H_INCLUDED
#include "FiguraGeometrica.h"
#include "sculptor.h"

class CutEllipsoid : public FiguraGeometrica{
    int xc, yc, zc, rx, ry, rz;
public:
    CutEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz);
    ~CutEllipsoid(){};
    void draw(sculptor &s);

};

#endif // CUTELLIPSOID_H_INCLUDED
