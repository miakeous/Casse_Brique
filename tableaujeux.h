#ifndef TABLEAUJEUX_H
#define TABLEAUJEUX_H
#include "brique.h"
#include "palet.h"
class TableauJeux
{
public:
    TableauJeux();
    void reset();
    void affiche();
    Palet getPalet(){return *palet;}
private :
    Palet *palet ;
    std::vector<Brique *> m_Brique;
};

#endif // TABLEAUJEUX_H
