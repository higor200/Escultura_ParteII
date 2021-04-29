#ifndef CUTVOXEL_H_INCLUDED
#define CUTVOXEL_H_INCLUDED
#include "FiguraGeometrica.h"
#include "sculptor.h"

class CutVoxel : public FiguraGeometrica{
    int x, y, z;
public:
    CutVoxel(int x, int y, int z);
    ~CutVoxel(){};
    void draw(sculptor &s);

};


#endif // CUTVOXEL_H_INCLUDED
