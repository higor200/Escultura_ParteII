#include <iostream>
#include "CutBox.h"
#include "CutEllipsoid.h"
#include "CutSphere.h"
#include "CutVoxel.h"
#include "FiguraGeometrica.h"
#include "PutBox.h"
#include "PutEllipsoid.h"
#include "PutSphere.h"
#include "PutVoxel.h"
#include "sculptor.h"
#include "Interpretador.h"

using namespace std;

int main()
{
    sculptor *s_;

    Interpretador parser;

    vector <FiguraGeometrica*> figs;

    figs = parser.parse ("FIGURA.txt");

    s_ = new sculptor (parser.getDimx(), parser.getDimy(), parser.getDimz());

    for (size_t i=0; i <figs.size(); i++){
        figs[i] -> draw(*s_);
    }

    s_ -> limpaVoxels();

    s_ -> writeOFF ((char*)"FIGURAGEOMETRICA.off");

    for (size_t i=0; i < figs.size(); i++){
        delete figs[i];
    }
    delete s_;

    return 0;
}
