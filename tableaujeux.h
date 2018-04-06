#ifndef TABLEAUJEUX_H
#define TABLEAUJEUX_H
#include "brique.h"
#include "palet.h"
class TableauJeux
{
public:
    TableauJeux();
    Palet *palet ;
    void reset();
    void affiche();
    Palet getPalet(){return *palet;}
    void setTaille(float x);
    void setPosPaletd();
    void setPosPaletg();
private :

    std::vector<Brique *> m_Brique;
};

#endif // TABLEAUJEUX_H
