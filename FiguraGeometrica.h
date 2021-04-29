#ifndef FIGURAGEOMETRICA_H_INCLUDED
#define FIGURAGEOMETRICA_H_INCLUDED
#include <iostream>
#include "sculptor.h"

class FiguraGeometrica{
protected:
    float r,g,b,a;
public:
    FiguraGeometrica();
    virtual  ~FiguraGeometrica(){};
    virtual void draw(sculptor &s)=0;

};


#endif // FIGURAGEOMETRICA_H_INCLUDED
