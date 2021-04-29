#include <iostream>
#include "PutSphere.h"
#include "FiguraGeometrica.h"

PutSphere::PutSphere(int xc, int yc, int zc, int radius, float r, float g, float b, float a){

   this->xc=xc;
   this->yc=yc;
   this->zc=zc;
   this->radius=radius;
   this->r=r;
   this->g=g;
   this->b=b;
   this->a=a;
}

void PutSphere::draw(sculptor &s){

    int x,y,z;
    double calc, dx, dy, dz;
    calc = radius * radius;
    s.setColor(r,g,b,a);

    for(x = xc - radius; x<xc + radius; x++){
        for(y = yc - radius; y<yc + radius; y++){
            for(z = zc - radius; z<zc + radius; z++){

                dx = ((double)(x-xc)*(double)(x-xc));
                dy = ((double)(y-yc)*(double)(y-yc));
                dz = ((double)(z-zc)*(double)(z-zc));

                if((dx + dy + dz) < calc){
                    s.putVoxel(x, y, z);

                }
            }
        }
    }
}
/*
void PutSphere::draw(sculptor &s){
    s.setColor(r,g,b,a);
    double dx, dy, dz;
    int x1 = xc - radius, x2 = xc + radius, y1 = yc - radius,
        y2 = yc + radius, z1 = zc - radius, z2 = zc + radius;

    for(int i = x1; i<x2; i++){
        dx=((static_cast<float>(i)-xc)/radius)*((static_cast<float>(i)-xc)/radius);
            for(int j=y1; j<y2; j++){
                dy=((static_cast<float>(j)-yc)/radius)*((static_cast<float>(j)-yc)/radius);
                for (int k=z1; k<z2; k++) {
                    dz=((static_cast<float>(k)-zc)/radius)*((static_cast<float>(k)-zc)/radius);

                        if(dx+dy+dz<1){
                            s.putVoxel(i,j,k);
                        }
                }
            }
    }
}
*/
