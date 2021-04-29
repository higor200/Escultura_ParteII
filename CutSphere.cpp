#include "CutSphere.h"
#include "FiguraGeometrica.h"

CutSphere::CutSphere (int xc, int yc, int zc, int radius){
   this->xc=xc;
   this->yc=yc;
   this->zc=zc;
   this->radius = radius;
}

void CutSphere::draw(sculptor &s){
    double calc;
    int x,y,z;
    calc = radius*radius;
    for(x = xc - radius; x<xc + radius; x++){
        for(y = yc - radius; y<yc + radius; y++){
            for(z = zc - radius; z<zc + radius; z++){
                if(static_cast<double>(x-xc)*static_cast<double>(x+xc) +
                   static_cast<double>(y-yc)*static_cast<double>(y+yc)+
                   static_cast<double>(z-xc)*static_cast<double>(z+xc) < calc){
                    s.CutVoxel(x, y, z);
                }
            }
        }
    }
}
