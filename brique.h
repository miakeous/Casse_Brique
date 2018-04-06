#ifndef BRIQUE_H
#define BRIQUE_H
#include <QGLWidget>
#include "glu.h"
#include <GLUT/glut.h>
#include <string>
#include <QImage>
#include  <QDebug>

class Brique
{
public:
    Brique(float x,float y, float r, float v, float b,QString filename);
    virtual ~Brique();
    void display();
    int getCol(QString a){return posy/4;}
    GLfloat getColour(){return couleur[0];}
private :
    float posx = 0;
    float posy = 0;
    //GLUquadric* quadrique =  gluNewQuadric();
    float couleur[4];
    QImage imgText;
    GLuint texture;
    void rectangle(GLfloat posX, GLfloat posY, GLfloat posZ);

};

#endif // BRIQUE_H
