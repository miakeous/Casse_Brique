#ifndef PALET_H
#define PALET_H


class Palet
{
public:
    Palet();
    void display();
    void setPos(float x, float y, float z);

private:
    float posx= 0;
    float posy = 0;
    float posz = 20;
    void rectangle(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat longueur, GLfloat largeur, GLfloat hauteur);

};

#endif // PALET_H
