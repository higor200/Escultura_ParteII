#include <iostream>
#include "CutVoxel.h"
#include "FiguraGeometrica.h"

CutVoxel::CutVoxel(int x, int y, int z){
    this->x=x;
    this->y=y;
    this->z=z;
}

void CutVoxel::draw(sculptor &s){
    s.CutVoxel(x,y,z);
}
