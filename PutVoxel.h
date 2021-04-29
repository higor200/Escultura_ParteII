#ifndef PUTVOXEL_H_INCLUDED
#define PUTVOXEL_H_INCLUDED
#include "FiguraGeometrica.h"
#include "sculptor.h"

class PutVoxel : public FiguraGeometrica{
    int x, y, z;
public:
    PutVoxel(int x, int y, int z,
             float r, float g, float b, float a);
    void draw(sculptor &s);
    ~PutVoxel(){}
};


#endif // PUTVOXEL_H_INCLUDED
