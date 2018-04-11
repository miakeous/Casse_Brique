#ifndef TABLEAUJEUX_H
#define TABLEAUJEUX_H
#include "brique.h"
#include "palet.h"
#include "boule.h"

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
    boule *myball;
    std::vector<Brique *> m_Brique;
};

#endif // TABLEAUJEUX_H
