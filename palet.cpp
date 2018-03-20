#include "palet.h"

Palet::Palet()
{
    couleur[0] = r;
    couleur[1] = v;
    couleur[2] = b;
    couleur[3] = 1.0;
    glEnable(GL_DEPTH_TEST);
}


void Palet::display(){

    glLoadIdentity();
    glPushMatrix();

    glTranslatef(posx,40,posy -15 );
    //glMaterialfv(GL_FRONT,GL_AMBIENT,couleur);
    //glEnable(GL_TEXTURE_2D);
    //glBindTexture( GL_TEXTURE_2D, texture);
     //glColor3f(couleur[0],couleur[1],couleur[2]);

    rectangle(0,0,0);
    //gluSphere(quadrique, 5, 50, 50);
    //glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void Palet::rectangle(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat longueur, GLfloat largeur, GLfloat hauteur){
    glColor3f(couleur[0],couleur[1],couleur[2]);
    glBegin(GL_POLYGON);

       glVertex3f(posX,posY,posZ);
       glVertex3f(posX,posY+ largeur,posZ);
       glVertex3f(posX,posY+ largeur,posZ+hauteur);
       glVertex3f(posX,posY,posZ+hauteur);
    glEnd();
    glBegin(GL_POLYGON);

       glVertex3f(posX+longueur,posY,posZ);
       glVertex3f(posX+longueur,posY+ largeur,posZ);
       glVertex3f(posX+longueur,posY+ largeur,posZ+hauteur);
       glVertex3f(posX+longueur,posY,posZ+hauteur);
    glEnd();
    glBegin(GL_POLYGON);

       glVertex3f(posX,posY,posZ);
       glVertex3f(posX,posY,posZ+hauteur);
       glVertex3f(posX+longueur,posY,posZ+hauteur);
       glVertex3f(posX+longueur,posY,posZ);
    glEnd();
    glBegin(GL_POLYGON);

       glVertex3f(posX,posY+largeur,posZ);
       glVertex3f(posX,posY+largeur,posZ+hauteur);
       glVertex3f(posX+longueur,posY+largeur,posZ+hauteur);
       glVertex3f(posX+longueur,posY+largeur,posZ);
    glEnd();
    glBegin(GL_POLYGON);

       glVertex3f(posX,posY,posZ);
       glVertex3f(posX,posY+largeur,posZ);
       glVertex3f(posX+longueur,posY+largeur,posZ);
       glVertex3f(posX+longueur,posY,posZ);
    glEnd();
    glBegin(GL_POLYGON);

       glVertex3f(posX,posY,posZ+hauteur);
       glVertex3f(posX,posY+largeur,posZ+hauteur);
       glVertex3f(posX+longueur,posY+largeur,posZ+hauteur);
       glVertex3f(posX+longueur,posY,posZ+hauteur);
    glEnd();
}


void Palet::setPos(float x, float y, float z){
    posx = x;
    posy = y;
    posz = z;
}
