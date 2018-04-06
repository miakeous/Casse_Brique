#ifndef MYWIDGET_H
#define MYWIDGET_H

//#include <QWidget>
#include "glu.h"
#include <GLUT/glut.h>
#include <QApplication>
#include <QGLWidget>
#include "tableaujeux.h"

#include<stdio.h>

class MyWidget : public QGLWidget
{
    Q_OBJECT
public:
    TableauJeux *tableau;
    explicit MyWidget(QWidget * parent = nullptr);
    void setPos(float x, float y, float z);
    TableauJeux getTableau(){return *tableau;}

    void update(){updateGL();}
    void setTaille(float x);
private :

    GLUquadric* quadrique =  gluNewQuadric();
    float posx = 0;
    float posy = 0;
    float posz = 0;

    void initializeGL();

     // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

signals:

public slots:
    void setTaillep();
    void setTaillem();
    void setTailleg();
    void setPosPaletg();
    void setPosPaletd();
};

#endif // MYWIDGET_H
