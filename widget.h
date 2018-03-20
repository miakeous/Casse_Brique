#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "opencv2/opencv.hpp"
#include <QTimer>
#include <QDebug>

#include <cstdio>
#include <iostream>

//#include <glwidget.h>

using namespace cv;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    //Mat match(Mat frame);
    Mat frame1,frame2,frameRect1,frameRect2;
    Mat resultImage;
    //Mat templateImage;
    //Mat templateFinale;
    bool templi= false;
    double taillex = 100.;
    double distance = 0.;
    double tailley= 150.;
    Rect *workingRect;
    Rect *templateRect;
    Point *workingCenter;
    QTimer *timer2;
    VideoCapture * webCam_;

    int frameWidth=(300);
    int frameHeight=200;

    int subImageWidth=100;
    int subImageHeight=100;
    int templateWidth=25;
    int templateHeight=25;

    float position = 0;

//    void match();


private slots :
    void affiche();
    void match();
};

#endif // WIDGET_H
