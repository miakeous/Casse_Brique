#ifndef TABLEAUJEUX_H
#define TABLEAUJEUX_H
#include "brique.h"

class TableauJeux
{
public:
    TableauJeux();
    void reset();
    void affiche();
private :
    std::vector<Brique *> m_Brique;
};

#endif // TABLEAUJEUX_H
