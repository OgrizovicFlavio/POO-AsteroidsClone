#include "Entity.h"

Entity::Entity(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height) {}

int Entity::getX() const
{
    return x;
}

int Entity::getY() const 
{
    return y;
}

int Entity::getWidth() const 
{
    return width;
}

int Entity::getHeight() const 
{
    return height;
}

void Entity::setPosition(int newX, int newY) 
{
    x = newX;
    y = newY;
}

// Verifica si esta entidad colisiona con otra usando detecci�n AABB (Axis-Aligned Bounding Box)
bool Entity::isCollidingWith(const Entity* other) const 
{
    return 
        (                                      
        x < other->x + other->width &&         // this izquierda < other derecha (this no est� completamente a la derecha de other)
        x + width > other->x &&                // this derecha > other izquierda (this no est� completamente a la izquierda)
        y < other->y + other->height &&        // this arriba < other abajo (this no est� completamente debajo)
        y + height > other->y                  // this abajo > other arriba (this no est� completamente encima) ---> si todas se cumplen, est�n colisionando; si una no se cumple, no colisionan
        );
}