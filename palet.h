#ifndef PALET_H
#define PALET_H
#include "glu.h"
#include <GLUT/glut.h>
#include <QDebug>
class Palet
{
public:
    Palet(float r, float v, float b);
    void display();
    void setPos(float x, float y, float z);
    void setTaille(float x);

private:
    float posx= 0;
    float posy = 0;
    float posz = 20;
    float taille = 10;
    float couleur[4];
    void rectangle(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat longueur, GLfloat largeur, GLfloat hauteur);

};

#endif // PALET_H
