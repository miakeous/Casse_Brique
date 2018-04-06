#include "mywidget.h"
#include "ui_widget.h"

MyWidget::MyWidget(QWidget *parent) :
    QGLWidget(parent)
{
    // Reglage de la taille/position
    gluQuadricDrawStyle(quadrique, GLU_FILL);
    tableau = new TableauJeux();

}


void MyWidget::initializeGL(){
    glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
    // Activation du zbuffer

    glEnable(GL_DEPTH_TEST);


}

void MyWidget::resizeGL(int w, int h){
      glViewport(0, 0, w, h);
      // Definition de la matrice de projection
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();

      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();

}
void MyWidget::paintGL(){


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50,50,-50,50,-50,50);
    //glFrustum(-50,50,-50,50,-20,50);
    gluLookAt(0,20,20,0,0,0,0,1,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
        gluQuadricDrawStyle(quadrique, GLU_FILL);
        glColor3f(255,0,255);
        glTranslatef(posx+0,posy+0,posz+0);
        gluSphere(quadrique, 2.5, 50, 50);
    glPopMatrix();
    tableau->affiche();

    // glPushMatrix();
    //glBegin(GL_POLYGON);
        //glColor3f(0,255,0);
  //     glVertex3f(-20,0,10);
  //     glVertex3f(20,0,10);
   //    glVertex3f(20,0,-10);
    //   glVertex3f(-20,0,-10);
    //glEnd();
    //glPopMatrix();


}

void MyWidget::setPos(float x, float y, float z){
    posx = x;
    posy = y;
    posz = z;
    updateGL();
}

void MyWidget::setTaillep(){
   this->getTableau().setTaille(10.0);
    updateGL();
}
void MyWidget::setTaillem(){
   this->getTableau().setTaille(15.0);
    updateGL();
}
void MyWidget::setTailleg(){
   this->getTableau().setTaille(20.0);
    updateGL();
}

void MyWidget::setPosPaletd(){
     //qDebug()<<"droite";
    this->getTableau().setPosPaletd();
    updateGL();
}

void MyWidget::setPosPaletg(){
     //qDebug()<<"gauche";
    this->getTableau().setPosPaletg();
     updateGL();
}

