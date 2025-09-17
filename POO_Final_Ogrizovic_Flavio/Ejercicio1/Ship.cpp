#include "Ship.h"
#include "AwesomeLibrary.h"

// Constructor que inicializa la nave en x, y, con tamaño 5x3 y 3 vidas
Ship::Ship(int x, int y)
    : Entity(x, y, 5, 3), lives(3) {}

void Ship::draw() const
{
    setForegroundColor(Color::LMAGENTA);

    goToCoordinates(x + 2, y);          // Parte superior de la nave
    cout << (char)30;

    goToCoordinates(x + 1, y + 1);
    cout << '(' << (char)206 << ')';    // Parte central

    goToCoordinates(x, y + 2);          // Ala izquierda
    cout << (char)30 << (char)188;

    goToCoordinates(x + 3, y + 2);
    cout << (char)200 << (char)30;      // Ala derecha

    setForegroundColor(Color::WHITE);
}

void Ship::draw(Color customColor) const
{
    setForegroundColor(customColor);

    goToCoordinates(x + 2, y);
    std::cout << (char)30;

    goToCoordinates(x + 1, y + 1);
    std::cout << '(' << (char)206 << ')';

    goToCoordinates(x, y + 2);
    std::cout << (char)30 << (char)188;

    goToCoordinates(x + 3, y + 2);
    std::cout << (char)200 << (char)30;

    setForegroundColor(Color::WHITE);
}


void Ship::clear() const
{
    // Borra el área ocupada por la nave
    for (int i = 0; i < height; ++i)
    {
        goToCoordinates(x, y + i);
        for (int j = 0; j < width; ++j)
            cout << ' '; // Imprimo blank spaces para "borrar" esa fila
    }
}

void Ship::moveLeft()
{
    if (x > 1) 
        x--; // Izquierda
}

void Ship::moveRight()
{
    if (x + width < getScreenWidth()) 
        x++; // Derecha
}

int Ship::getLives() const 
{
    return lives;
}

void Ship::takeDamage() 
{
    if (lives > 0) 
        lives--;
}

void Ship::flashOnHit() const
{
    const int flashes = 3;
    const int delay = 70;

    for (int i = 0; i < flashes; ++i)
    {
        clear();
        draw(Color::LRED);
        Sleep(delay);
        clear();
        draw();
        Sleep(delay);
    }
}