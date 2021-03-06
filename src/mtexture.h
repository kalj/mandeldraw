/*
 * @(#)mtexture.h
 * @author Karl Ljungkvist
 * Last changed: <2010-03-14 18:17:31 CET>
 *
 *   
 */

#ifndef _MTEXTURE_H
#define _MTEXTURE_H

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/freeglut.h>
#else
#include <GL/freeglut.h>
#endif

#define INITIAL_DX 0.01

// #include "mousebox.h"
class Mousebox;


class Mtexture
{
public:
    Mtexture(double ulx, double uly, double dx, int width, int height,
	     int maxIter, int aaLvl);
    ~Mtexture();
    void reset(double ulx, double uly, double dx, int width, int height,
	       int maxIter, int aaLvl);
    const int getWidth() { return width;}
    const int getHeight() { return height;}
    void zoomToBox(Mousebox &box);
    void resize(int w, int h);
    void incrementInitialMaxIter() { initialMaxIter += 10; outdate(); }
    void decrementInitialMaxIter() { initialMaxIter -= 10; outdate(); }
    void setAALvl(int lvl);    
    void outdate(){uptodate = false;}
    void compute();
    void draw();
    void writeToBMP(const char *filename);
    GLuint textureId;
private:
    void bind();
    bool uptodate;
    double ulx;
    double uly;
    double dx;
    int width;
    int height;
    int initialMaxIter;
    int aaLvl;
    float *pixels;
    // vector pixels;
};



#endif /* _MTEXTURE_H */

