#pragma once
#include "Entity.h"
#include "AwesomeLibrary.h"

class Ship : public Entity
{
private:
    int lives;


public:
    Ship(int x, int y);

    //Dibuja la nave con color predeterminado. Sobrecarga para "pintar" la nave de otro color cuando recibe da�o
    void draw() const override;
    void draw(Color customColor) const;

    void clear() const;

    //Movimiento
    void moveLeft();
    void moveRight();

    int getLives() const;
    void takeDamage();

    //Animaci�n de parpadeo al recibir da�o
    void flashOnHit() const;
};
