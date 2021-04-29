#include "Interpretador.h"
#include "FiguraGeometrica.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "PutBox.h"
#include "PutVoxel.h"
#include "PutEllipsoid.h"
#include "CutEllipsoid.h"
#include "CutBox.h"
#include "PutBox.h"
#include "CutVoxel.h"
#include "PutSphere.h"
#include "CutSphere.h"
#include <iostream>

using namespace std;

Interpretador::Interpretador(){
}

    vector <FiguraGeometrica *> Interpretador::parse(string filename){
    vector <FiguraGeometrica *> figs;
    ifstream fin;
    stringstream ss;
    string s, token;

    fin.open("FIGURA.txt");

    if(!fin.is_open()){
        cout << "NAO FOI POSSIVEL ABRIR O ARQUIVO " << filename << endl;
        exit(0);
    }
    cout << "ARQUIVO ABERTO!" << endl;
    while(fin.good()){
        getline(fin, s);
        if(fin.good()){
            ss.clear();
            ss.str(s);
            ss >> token;
        if(ss.good()){

            if(token.compare("dim") == 0){
                ss >> dimx >> dimy >> dimz;

            }else if(token.compare("putvoxel") == 0){
                int x0, y0, z0;
                ss >> x0 >> y0 >> z0 >> r >> g >> b >> a;
                figs.push_back(new PutVoxel(x0, y0, z0, r, g, b, a));
                cout << "ENTROU NO PUTVOXEL" << endl;

            }else if(token.compare("putsphere") == 0){
                int xc, yc, zc, radius;
                ss >> xc >> yc >> zc >> radius >> r >> g >> b >> a;
                figs.push_back(new PutSphere(xc, yc, zc, radius, r, g, b, a));
                cout << "ENTROU NO PUTSPHERE" << endl;

            }else if (token.compare("cutsphere")== 0){
                int xc, yc, zc, radius;
                ss >> xc >> yc >> zc >> radius;
                figs.push_back(new CutSphere(xc, yc, zc, radius));
                cout << "ENTROU NO CUTSPHERE" << endl;

            }else if(token.compare("putbox") == 0){
                int x0, x1, y0, y1, z0, z1;
                ss >> x0 >> x1 >>  y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
                cout << "ENTROU NO PUTBOX" << endl;

            }else if(token.compare("cutvoxel") == 0){
                int x, y, z;
                ss >> x >> y >> z;
                figs.push_back(new CutVoxel(x, y, z));
                cout << "ENTROU NO CUTVOXEL" << endl;

            }else if(token.compare("putellipsoid") == 0){
                int xc, yc, zc, rx, ry, rz;
                ss >> xc >> yc >> zc >> rx >> ry >> rz >>  r >> g >> b >> a;
                figs.push_back(new PutEllipsoid(xc, yc, zc, rx, ry, rz, r, g, b, a));
                cout << "ENTROU NO PUTELLIPSOID" << endl;

            }else if (token.compare("cutellipsoid")== 0){
                int xc, yc, zc, rx, ry, rz;
                ss >> xc >> yc >> zc >> rx >> ry >> rz;
                figs.push_back(new CutEllipsoid(xc, yc, zc, rx, ry, rz));
                cout << "ENTROU NO CUTELLIPSOID" << endl;

            }else if(token.compare("cutbox") ==0){
                int x0, x1, y0, y1, z0, z1;
                ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                figs.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
                cout << "ENTROU NO CUTBOX" << endl;
            }
        }
        }
    }
    cout << "\nESCULTURA FEITA!" << endl;

    return(figs);
}
int Interpretador::getDimx(){
    return dimx;
    }

    int Interpretador::getDimy(){
    return dimy;
    }
    int Interpretador::getDimz(){
    return dimz;
    }
