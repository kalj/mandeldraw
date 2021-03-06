/*
 * @(#)mwindow.cpp
 * Last changed: <2010-03-15 18:51:03 CET>
 * @author Karl Ljungkvist
 *
 * 
 *
 */

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/freeglut.h>
#else
#include <GL/freeglut.h>
#endif

#include <iostream>

using namespace std;
#include "log.h"
#include "mwindow.h"


bool Mwin::reshape(int w, int h){

    DBGLOG("Mwin::reshape(%d, %d)\n",w,h);
    
    if(width != w || height != h)
    {
	width=w;
	height=h;
	return true;
    }
    else
	return false;
}

// --- set up matrix for drawing in window coordinates ----

void Mwin::beginWinCoord(){
    // DBGLOG("beginWinCoord()%c",'\n');
    glDisable(GL_TEXTURE_2D);
    glMatrixMode(GL_MODELVIEW);
    
    glPushMatrix();
    glTranslatef(0,1.0,0);
    glScalef(1.0,-1.0, 0.0);
 }

// --- ...and reset it ----

void Mwin::endWinCoord(){
    // DBGLOG("endWinCoord()%c",'\n');
    glPopMatrix();

}


