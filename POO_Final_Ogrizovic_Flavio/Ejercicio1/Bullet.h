#pragma once
#include "Entity.h"

// Disparo del Player
class Bullet : public Entity 
{
private:
    bool active; //Flag para saber cuándo desactivar la bala (colisión o salida de la pantalla)

public:
    Bullet();

    void fireFrom(int startX, int startY); //Activa la bala desde una posición (Player)
    void move();
    void draw() const override;
    void clear() const;                    //Borra visualmente la bala
    void deactivate();                     //La desactiva
    bool isActive() const;
};
