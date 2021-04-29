#ifndef SCULPTOR_H_INCLUDED
#define SCULPTOR_H_INCLUDED
#include "string"

typedef struct{
    float r, g, b, a;
    bool isOn;

} voxel;

typedef struct{
    int x, y, z;
    bool exists;
} voxelCoords;

class sculptor{

    private:
        voxel ***v;
        float lado;
        float delta;
        float r, g, b, a;
        int nx, ny, nz;
        int i, x, y, z;

    public:
        sculptor(int _nx = 1, int _ny=1, int _nz=1);
        ~sculptor();

        void limpaVoxels();

        void setColor(float r, float g, float b, float a);

        void putBox(int x0, int x1, int y0, int y1, int z0, int z1);

        void putEllipsoid (int x0, int y0, int z0, int rx, int ry, int rz);

        void putSphere (int x0, int y0, int z0, int rr);

        void cutSphere(int x0, int y0, int z0, int r);

        void putVoxel (int x0, int y0, int z0);

        void clear(void);

        void CutVoxel(int x0, int y0, int z0);

        void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);

        void cutEllipsoid (int x0, int y0, int z0, int rx, int ry, int rz);

        void writeOFF (char* f);
};

#endif // SCULPTOR_H_INCLUDED
