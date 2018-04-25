#include "tableaujeux.h"
#include "palet.h"
#include "QDebug"
TableauJeux::TableauJeux()
{
    palet = new Palet(0,255,255,10);
/*    Brique *t = new Brique(10.0,-10.0,1.0,0,0,"");
    m_Brique.push_back(t); */
    for(int i=1 ;i <5; i++){
        for(int j=-5;j<5;j++){
            float v2 = rand() % 255 + 1;
            float v3 = rand() % 255 + 1;
            float v4 = rand() % 255 + 1;
            m_Brique.push_back(new Brique(float(j*5),float(i*10),v2/255,v3/255,v4/255,"") );
        }
    }

    myball = new boule(255,0,255);

    gauche = new mur(-30,-50,100,3);
}


void TableauJeux::affiche(){
    int i = 0;
     palet->display();
    //qDebug()<<  palet->getTaille();
    while ( i < m_Brique.size() )
    {

            m_Brique[i]->display();
            //qDebug()<< m_Brique[i]->getColour();

            i++ ;
    }
    if(myball->posdepart) // posdepart équivaut à posé sur le palet
    {
        myball->setPosX(palet->getPosX()+palet->getTaille()/2);
    }
    myball->display();
    gauche->display();

}

void TableauJeux::reset(){
    for(int i=11 ;i > 8; i--){
        for(int j=-5;j<5;j++){
            float v2 = rand() % 255 + 1;
            float v3 = rand() % 255 + 1;
            float v4 = rand() % 255 + 1;
            m_Brique.push_back(new Brique(float(j*5),float(i*4),v2,v3,v4,""));

        }
    }
}


void TableauJeux::setTaille(float x){
    this->palet->setTaille(x);

}

void TableauJeux::setPosPaletd(){
    this->palet->setPos(-2);

}
void TableauJeux::setPosPaletg(){
    this->palet->setPos(2);

}
