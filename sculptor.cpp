#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include "sculptor.h"


using namespace std;

//Construtor da Classe
sculptor::sculptor(int _nx, int _ny, int _nz){

    nx = _nx;
    ny = _ny;
    nz = _nz;
    delta = 0;
    lado = 0.5 - delta;
    r = g = b = a = 0.5;

     v = new voxel**[nx];
    for (x = 0; x<nx; x++){
        v[x] = new voxel*[ny];
    }
    for (x = 0; x<nx; x++){
        for (y=0; y<ny; y++){
            v[x][y] = new voxel[nz];
        }
    }
    for(x = 0; x < nx; x++){
        for (y = 0; y < ny; y++){
            for (z = 0; z < nz; z++){
                v[x][y][z].isOn = false;

                v[x][y][z].r = r;
                v[x][y][z].g = g;
                v[x][y][z].b = b;
                v[x][y][z].a = a;
            }
        }
    }

}

//Destrutor da Classe
sculptor::~sculptor(){

    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}

//Isere Cores
void sculptor::setColor(float _r, float _g, float _b, float _a){
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}


//Desenha voxel na posição (x0,y0,z0) com a cor (r,g,b,a)
void sculptor::putVoxel(int x0, int y0, int z0){
    v[x0][y0][z0].isOn = true;
    v[x0][y0][z0].r = r;
    v[x0][y0][z0].g = g;
    v[x0][y0][z0].b = b;
    v[x0][y0][z0].a = a;

}

//Apaga voxel na posição (x0,y0,z0) com a cor  (r,g,b,a)
void sculptor::CutVoxel(int x0, int y0, int z0){
    v[x0][y0][z0].isOn = false;
}

//Desenha um paralelepípedo delimitado
void sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){

    for (int i = x0; i < x1; i++){
        for (int j = y0; j < y1; j++){
            for (int k = z0; k < z1; k++){

    v[i][j][k].isOn = true;
    v[i][j][k].r = r;
    v[i][j][k].g = g;
    v[i][j][k].b = b;
    v[i][j][k].a = a;
            }
        }
    }

}

//Apaga um paralelepípedo delimitado
void sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for (int i = x0; i < x1; i++){
        for (int j = y0; j < y1; j++){
            for (int k = z0; k < z1; k++){

    v[i][j][k].isOn = false;

            }
        }
    }
}

//Desenha um elipsóide com centro no ponto (x0,y0,z0), raios especificados e com a cor (r,g,b,a).
void sculptor::putEllipsoid (int x0, int y0, int z0, int rx, int ry, int rz){

    double dx, dy, dz;

    for (int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            for (int k = 0; k < nz; k++){
            dx = ((double)(i-x0)*(double)(i-x0))/(rx*rx);
            dy = ((double)(j-y0)*(double)(j-y0))/(ry*ry);
            dz = ((double)(k-z0)*(double)(k-z0))/(rz*rz);

            if ((dx + dy + dz) < 1){
                v[i][j][k].isOn = true;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;

            }
            }
        }
    }
}

//Apaga um elipsóide com centro no ponto (x0,y0,z0) e raios especificados.
void sculptor::cutEllipsoid (int x0, int y0, int z0, int rx, int ry, int rz){

    double dx, dy, dz;

    for (int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            for (int k = 0; k < nz; k++){
            dx = ((double)(i-x0)*(double)(i-x0))/(rx*rx);
            dy = ((double)(j-y0)*(double)(j-y0))/(ry*ry);
            dz = ((double)(k-z0)*(double)(k-z0))/(rz*rz);

            if ((dx + dy + dz) < 1){
                v[i][j][k].isOn = false;

            }
            }
        }
    }
}
void sculptor::putSphere(int x0, int y0, int z0, int r){

    double dx, dy, dz;

    for (int i = 0; i < nx; i++){
            for (int j = 0; j < ny; j++){
                for (int k = 0; k < nz; k++){
                dx = ((double)(i-x0)*(double)(i-x0));
                dy = ((double)(j-y0)*(double)(j-y0));
                dz = ((double)(k-z0)*(double)(k-z0));

                if ((dx + dy + dz) < (r*r)){
                v[i][j][k].isOn = true;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;

                }
                }
            }
    }
}

void sculptor::cutSphere(int x0, int y0, int z0, int r){

    double dx, dy, dz;

    for (int i = 0; i < nx; i++){
            for (int j = 0; j < ny; j++){
                for (int k = 0; k < nz; k++){
                dx = ((double)(i-x0)*(double)(i-x0));
                dy = ((double)(j-y0)*(double)(j-y0));
                dz = ((double)(k-z0)*(double)(k-z0));

                if ((dx + dy + dz) < (r*r)){
                v[i][j][k].isOn = false;

                }
                }
            }
    }
}

//Grava a escultura no formato OFF no arquivo filename
void sculptor::writeOFF(char *filename){

    int total, index;
    ofstream f;
    total = 0;
    f.open(filename);
    f << "OFF\n";

    for (x=0; x < nx; x++){
        for (y = 0; y <ny; y++){
            for (z=0; z <nz; z++){

        if(v[x][y][z].isOn == true){
            total++;
        }
            }
        }
    }

    f << total*8 << " " << total * 6 <<" "<< 0 << "\n";

    for (x=0; x < nx; x++){
        for (y = 0; y <ny; y++){
            for (z=0; z <nz; z++){
        if(v[x][y][z].isOn == true){

        f << x - lado << " " << y + lado << " " << z - lado << "\n" << flush;
        f << x - lado << " " << y - lado << " " << z - lado << "\n" << flush;
        f << x + lado << " " << y - lado << " " << z - lado << "\n" << flush;
        f << x + lado << " " << y + lado << " " << z - lado << "\n" << flush;
        f << x - lado << " " << y + lado << " " << z + lado << "\n" << flush;
        f << x - lado << " " << y - lado << " " << z + lado << "\n" << flush;
        f << x + lado << " " << y - lado << " " << z + lado << "\n" << flush;
        f << x + lado << " " << y + lado << " " << z + lado << "\n" << flush;
        }
            }
        }
    }
    total = 0;

    for (x=0; x < nx; x++){
        for (y = 0; y <ny; y++){
            for (z=0; z <nz; z++){
        if(v[x][y][z].isOn == true){
            index = total*8;
            f << fixed;

            f<< 4 << " " << index + 0 << " " << index + 3 << " " << index + 2 << " " << index + 1 << " ";
            f << setprecision(2) << v[x][y][z].r << " " << setprecision(2) << v[x][y][z].g << " " << setprecision(2) << v[x][y][z].b << " " <<setprecision(2) << v[x][y][z].a << setprecision(2) << "\n";

            f<< 4 << " " << index + 4 << " " << index + 5 << " " << index + 6 << " " << index + 7 << " ";
            f << setprecision(2) << v[x][y][z].r << " " << setprecision(2) << v[x][y][z].g << " " << setprecision(2) << v[x][y][z].b << " " << setprecision(2) << v[x][y][z].a << setprecision(2) << "\n";

            f<< 4 << " " << index + 0 << " " << index + 1 << " " << index + 5 << " " << index + 4 << " ";
            f << setprecision(2) << v[x][y][z].r << " " << setprecision(2) << v[x][y][z].g << " " << setprecision(2) << v[x][y][z].b << " " << setprecision(2) << v[x][y][z].a << setprecision(2) << "\n";

            f<< 4 << " " << index + 0 << " " << index + 4 << " " << index + 7 << " " << index + 3 << " ";
            f << setprecision(2) << v[x][y][z].r << " " << setprecision(2) << v[x][y][z].g << " " << setprecision(2) << v[x][y][z].b << " " << setprecision(2) << v[x][y][z].a << setprecision(2) << "\n";

            f<< 4 << " " << index + 7 << " " << index + 6 << " " << index + 2 << " " << index + 3 << " ";
            f << setprecision(2) << v[x][y][z].r << " " <<setprecision(2) << v[x][y][z].g << " " << setprecision(2) << v[x][y][z].b << " " <<setprecision(2) << v[x][y][z].a << setprecision(2) << "\n";

            f<< 4 << " " << index + 1 << " " << index + 2 << " " << index + 6 << " " << index + 5 << " ";
            f << setprecision(2) << v[x][y][z].r << " " << setprecision(2) << v[x][y][z].g << " " << setprecision(2) << v[x][y][z].b << " " << setprecision(2) << v[x][y][z].a << setprecision(2) << "\n";

            total++;
        }
            }
        }
    }
    f.close();
}
void sculptor::limpaVoxels(void) {
  queue<int> q;
  int lx, ly, lz;
  for (x = 1; x < nx - 1; x++) {
    for (y = 1; y < ny - 1; y++) {
      for (z = 1; z < nz - 1; z++) {
        if ((v[x][y][z].isOn == true) && (v[x + 1][y][z].isOn == true) &&
            (v[x - 1][y][z].isOn == true) && (v[x][y + 1][z].isOn == true) &&
            (v[x][y - 1][z].isOn == true) && (v[x][y][z + 1].isOn == true) &&
            (v[x][y][z - 1].isOn == true))
                {
                q.push(x);
                q.push(y);
                }
            }
        }
    }
}
