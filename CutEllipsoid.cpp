#include <iostream>
#include "CutEllipsoid.h"
#include "FiguraGeometrica.h"

CutEllipsoid::CutEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz){
   this->xc=xc;
   this->yc=yc;
   this->zc=zc;
   this->rx=rx;
   this->ry=ry;
   this->rz=rz;
}

void CutEllipsoid::draw(sculptor &s){
int x,y,z;
    double dx, dy, dz;

    for(x = xc - rx; x<xc + rx; x++){
        for(y = yc - ry; y<yc + ry; y++){
            for(z = zc - rz; z<zc + rz; z++){

                dx = (((double)(x-xc)*(double)(x-xc))/(rx*rx));
                dy = (((double)(y-yc)*(double)(y-yc))/(ry*ry));
                dz = (((double)(z-zc)*(double)(z-zc))/(rz*rz));

                if((dx + dy + dz) <=1){
                    s.CutVoxel(x, y, z);

                }
            }
        }
    }
}
