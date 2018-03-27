#include "tableaujeux.h"

TableauJeux::TableauJeux()
{
    palet = new Palet(0,255,255);
    for(int i=1 ;i <5; i++){
        for(int j=-5;j<5;j++){
            float v2 = rand() % 255 + 1;
            float v3 = rand() % 255 + 1;
            float v4 = rand() % 255 + 1;
            Brique *v = new Brique(float(j*5),float(i*10),v2,v3,v4,"");

            m_Brique.push_back(v );

        }
    }


}


void TableauJeux::affiche(){
    int i = 0;
     palet->display();
    while ( i < m_Brique.size() )
    {
            glPopMatrix();
            m_Brique[i]->display();
            glPushMatrix();
            i++ ;
    }


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

