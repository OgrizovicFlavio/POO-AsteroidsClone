#pragma once
#include "Entity.h"

class Enemy : public Entity
{
private:
    bool alive;
    static int activeCount;         // Contador est�tico de enemigos activos en pantalla

public:
    Enemy(int x, int y);

    void draw() const;              // Dibuja
    void clear() const;             // Borra
    void moveDown();                // Movimiento

    void kill();                    // Eliminaci�n del enemigo
    bool isAlive() const;

    // M�tdos static para chequear y reiniciar el contador
    static int getActiveCount();
    static void resetActiveCount();
};
