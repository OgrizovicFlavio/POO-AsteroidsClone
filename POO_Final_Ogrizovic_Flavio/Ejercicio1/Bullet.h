#pragma once
#include "Entity.h"

// Disparo del Player
class Bullet : public Entity 
{
private:
    bool active; //Flag para saber cu�ndo desactivar la bala (colisi�n o salida de la pantalla)

public:
    Bullet();

    void fireFrom(int startX, int startY); //Activa la bala desde una posici�n (Player)
    void move();
    void draw() const override;
    void clear() const;                    //Borra visualmente la bala
    void deactivate();                     //La desactiva
    bool isActive() const;
};
