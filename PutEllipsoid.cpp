#include "PutEllipsoid.h"
#include "FiguraGeometrica.h"
PutEllipsoid::PutEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz,
                           float r, float g, float b, float a){
    this-> xc = xc;
    this-> yc = yc;
    this-> zc = zc;

    this-> rx = rx;
    this-> ry = ry;
    this-> rz = rz;

    this-> r=r;
    this-> g=g;
    this-> b=b;
    this-> a=a;
}
void PutEllipsoid::draw(sculptor &s){
    s.setColor(r,g,b,a);
    float dx,dy,dz;
    int x1 = xc-rx, x2 = xc+rx, y1 = yc-ry,
        y2 = yc+ry, z1 = zc-rz, z2 = zc+rz;
    for(int x=x1; x<x2; x++){
        dx=((static_cast<float>(x)-xc)/rx)*((static_cast<float>(x)-xc)/rx);
        for(int y=y1; y<y2; y++){
            dy=((static_cast<float>(y)-yc)/ry)*((static_cast<float>(y)-yc)/ry);
            for (int z=z1; z<z2; z++) {
                dz=((static_cast<float>(z)-zc)/rz)*((static_cast<float>(z)-zc)/rz);
                if(dx+dy+dz<1){
                    s.putVoxel(x,y,z);
                }
            }
        }
    }
}
