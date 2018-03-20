#include "tableaujeux.h"

TableauJeux::TableauJeux()
{

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
    while ( i < m_Brique.size() )
    {

            m_Brique[i]->display();

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
