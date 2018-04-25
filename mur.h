#ifndef MUR_H
#define MUR_H

//include Pierre (mac)
/*
#include "glu.h"
#include <GLUT/glut.h>
#include <QDebug>
*/

//include Manon (windows)
#include <GL/glu.h>
#include <GL/gl.h>
#include <QDebug>

class mur
{
public:
    mur(int X, int Z, int height, int width);
    void display();
    void rectangle(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat profondeur, GLfloat hauteur, GLfloat taille);


private:
    int posX;
    int posZ;
    int hauteur;
    int largeur;
};

#endif // MUR_H
