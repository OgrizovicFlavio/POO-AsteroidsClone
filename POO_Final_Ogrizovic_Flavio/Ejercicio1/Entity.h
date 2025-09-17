#pragma once

// Rrepresenta cualquier entidad (nave, enemigos, balas y asteroides)
class Entity 
{
protected:
    int x, y;           //Posición de la entidad en consola (columna y fila)
    int width, height;  //Tamaño en caracteres (ancho y alto del sprite ASCII)

public:
    // Constructor que inicializa la pos y el tamaño
    Entity(int x, int y, int width, int height);

    // Destructor virtual
    virtual ~Entity() = default;

    // Getters
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;

    // Setter
    void setPosition(int newX, int newY);

    // Colisión con otra entidad (rectangular)
    bool isCollidingWith(const Entity* other) const;

    // Virtual puro: cada clase hija tiene su froma de dibujarse
    virtual void draw() const = 0;
};
