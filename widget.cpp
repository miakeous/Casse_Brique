#include "widget.h"
#include "ui_widget.h"




Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    workingRect = new Rect((frameWidth-subImageWidth)/2,frameHeight/2+(frameHeight/2-subImageHeight)/2,subImageWidth,subImageHeight);
    templateRect = new Rect((workingRect->width-templateWidth)/2,(workingRect->height-templateHeight)/2,templateWidth,templateHeight);
    workingCenter = new Point(workingRect->x+subImageWidth/2,workingRect->y+subImageHeight/2);


    //Création de la Caméra
    webCam_=new VideoCapture(0);
    //webCam_->set(CV_CAP_PROP_FRAME_WIDTH,300);
    //webCam_->set(CV_CAP_PROP_FRAME_HEIGHT,200);
    webCam_->set(CV_CAP_PROP_FRAME_WIDTH,frameWidth);
    webCam_->set(CV_CAP_PROP_FRAME_HEIGHT,frameHeight);
    //qDebug()<< "dans constructeur";
    if(webCam_->isOpened())
    {

        timer2 = new QTimer();
        timer2->start();
        timer2->connect(timer2, SIGNAL(timeout()),this, SLOT(affiche()));
        timer2->connect(timer2, SIGNAL(timeout()),this, SLOT(match()));
        ui->petit->setChecked(true);
        connect(ui->petit, SIGNAL(released()),this,SLOT(setTaille()));
        connect(ui->moyen, SIGNAL(released()),this,SLOT(setTaille1()));
        connect(ui->grand, SIGNAL(released()),this,SLOT(setTaille2()));
        //qDebug() << "dans l'open";
       // timer2->connect(timer2, SIGNAL(timeout()),this, SLOT(tire()));
        //timer2->connect(timer2,SIGNAL(timeout()),this,SLOT(deplace()));
    }
}

Widget::~Widget()
{
    delete ui;
    delete webCam_;
}

void Widget::setTaille(){
    if(ui->petit->isChecked()){
        if(ui->moyen->isChecked()){
            ui->moyen->setChecked(false);
        }
        if(ui->grand->isChecked()){
            ui->grand->setChecked(false);
        }
        ui->openGLWidget->setTaille(5);
        ui->openGLWidget->update();

    }

}


void Widget::setTaille1(){

    if(ui->moyen->isChecked()){
        if(ui->petit->isChecked()){
            ui->petit->setChecked(false);
        }
        if(ui->grand->isChecked()){
            ui->grand->setChecked(false);
        }
        ui->openGLWidget->setTaille(50);
        ui->openGLWidget->update();
    }

}

void Widget::setTaille2(){

    if(ui->grand->isChecked()){
        if(ui->moyen->isChecked()){
            ui->moyen->setChecked(false);
        }
        if(ui->petit->isChecked()){
            ui->petit->setChecked(false);
        }
        ui->openGLWidget->setTaille(100);
        ui->openGLWidget->update();
    }


}
void Widget::affiche(){


    if (webCam_->read(frame1)) {   // Capture a frame
      //  qDebug()<< "dans l'affichage";
        //image = match(image.clone());
        //frame2 = frame1.clone();
        // Flip to get a mirror effect
        flip(frame1,frame1,1);
        cvtColor(Mat(frame1,*workingRect),frameRect1,COLOR_BGR2GRAY);

        int result_cols =  frame1.cols-templateWidth  + 1;
        int result_rows = frame1.rows-templateHeight + 1;
        resultImage.create( result_cols, result_rows, CV_32FC1 );

        // Invert Blue and Red color channels
        //match();



    }
}


void Widget::match(){
    if(webCam_->read(frame2)){


    // Mirror effect
        flip(frame2,frame2,1);
    // Extract working rect in frame2 and convert to gray
        cvtColor(Mat(frame2,*workingRect),frameRect2,COLOR_BGR2GRAY);

    // Extract template image in frame1
        Mat templateImage (frameRect1,*templateRect);
    // Do the Matching between the working rect in frame2 and the templateImage in frame1
        matchTemplate( frameRect2, templateImage, resultImage, TM_CCORR_NORMED );
    // Localize the best match with minMaxLoc
        double minVal; double maxVal; Point minLoc; Point maxLoc;
        minMaxLoc( resultImage, &minVal, &maxVal, &minLoc, &maxLoc);
    // Compute the translation vector between the origin and the matching rect
        Point vect(maxLoc.x-templateRect->x,maxLoc.y-templateRect->y);

    // Draw green rectangle and the translation vector
        rectangle(frame2,*workingRect,Scalar( 0, 255, 0),2);
       // qDebug() << workingCenter->x;
        //qDebug() << workingCenter->x+vect.x;
        position = vect.x;
        ui->openGLWidget->setPos(position*2,0,0);
        Point p(workingCenter->x+vect.x,workingCenter->y+vect.y);
        arrowedLine(frame2,*workingCenter,p,Scalar(255,255,255),2);

    // Display frame2

         cvtColor(frame2,frame2,CV_BGR2RGB);
         QImage img= QImage((const unsigned char*)(frame2.data),frame2.cols,frame2.rows,QImage::Format_RGB888);
   // Display on label
         ui->imageLabel->setPixmap(QPixmap::fromImage(img));
   // Resize the label to fit the image
        ui->imageLabel->resize(ui->imageLabel->pixmap()->size());
    // Swap matrixes
     swap(frameRect1,frameRect2);
}
}
