#include "Bullet.h"
#include "AwesomeLibrary.h"

// Crea una bala inactiva fuera de pantalla
Bullet::Bullet()
    : Entity(0, 0, 1, 1), active(false) {}

// Dispara la bala desde una posición
void Bullet::fireFrom(int startX, int startY) 
{
    x = startX;
    y = startY;
    active = true;
}

// Movimiento hacia arriba
void Bullet::move() 
{
    if (active) 
    {
        clear();
        y--;

        // Si sale del área visible, se desactiva
        if (y < 4) 
        {
            deactivate();
        }
    }
}

void Bullet::draw() const
{
    if (active)
    {
        setForegroundColor(Color::LMAGENTA);
        goToCoordinates(x, y);
        cout << (char)179;                          // Caracter de la bala: │
        setForegroundColor(Color::WHITE);
    }
}

// Limpia la posición anterior de la bala
void Bullet::clear() const 
{
    if (active) 
    {
        goToCoordinates(x, y);
        cout << ' ';
    }
}

void Bullet::deactivate() 
{
    active = false;
}

bool Bullet::isActive() const 
{
    return active;
}