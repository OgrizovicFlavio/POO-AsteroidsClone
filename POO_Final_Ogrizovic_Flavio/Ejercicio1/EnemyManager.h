#pragma once
#include <vector>
#include "Enemy.h"
#include "Bullet.h"
#include "Ship.h"

class EnemyManager
{
private:
    std::vector<Enemy> enemies;         // Lista de enemigos en pantalla
    int spawnCooldown;                  // Intervalo entre spawneo de enemigos
    int cooldownCounter;                // Contador para controlar el spawn

    int movementCooldown;               // Intervalo entre movimientos
    int movementCounter;                // Contador

public:
    EnemyManager(int spawnCooldown, int movementCooldown);

    void update();
    void draw();
    void clear();

    // Verifica colisiones: bala-enemigo, enemigo-jugador
    void checkCollisions(Bullet& bullet, Ship& player, bool& isRunning, int& score);
    void reset();
};
