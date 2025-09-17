#include "Enemy.h"
#include "AwesomeLibrary.h"
#include <iostream>

// Inicialización del contador estático
int Enemy::activeCount = 0;

Enemy::Enemy(int x, int y)
    : Entity(x, y, 3, 1), alive(true) // "Sprite" de 3 caracteres de ancho y 1 de alto
{
    activeCount++;
}

// Dibuja al enemigo si está vivo
void Enemy::draw() const
{
    if (!alive) return;

    setForegroundColor(Color::YELLOW);
    goToCoordinates(x, y);
    std::cout << "(@)";
    setForegroundColor(Color::WHITE);
}

void Enemy::clear() const
{
    goToCoordinates(x, y);
    std::cout << "   "; // Borra los 3 caracteres que ocupa el enemigo
}

// Movimiento hacia abajo si hay espacio
void Enemy::moveDown()
{
    if (alive && y + height < getScreenHeight())
        y++;
}

// Borra, desactiva y actualiza el contador estático
void Enemy::kill()
{
    if (alive)
    {
        clear();
        alive = false;
        activeCount--;
    }
}

bool Enemy::isAlive() const
{
    return alive;
}

int Enemy::getActiveCount()
{
    return activeCount;
}

void Enemy::resetActiveCount()
{
    activeCount = 0;
}