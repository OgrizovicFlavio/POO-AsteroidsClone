#include "EnemyManager.h"
#include "AwesomeLibrary.h"
#include <cstdlib>

EnemyManager::EnemyManager(int spawnCooldown, int movementCooldown) : spawnCooldown(spawnCooldown), cooldownCounter(0), movementCooldown(movementCooldown), movementCounter(0) {}

void EnemyManager::update()
{
    // Spawneo 
    cooldownCounter++;
    if (cooldownCounter >= spawnCooldown)
    {                                
        int spawnX = rand() % (getScreenWidth() - 3); // Cuenta el ancho del enemigo
        enemies.emplace_back(spawnX, 4);              // 4 para que no spawneen arriba del HUD
        cooldownCounter = 0;
    }

    // Movimiento cada X frames
    movementCounter++;
    if (movementCounter >= movementCooldown)
    {
        for (auto& enemy : enemies)
        {
            if (enemy.isAlive())
            {
                enemy.clear();      // Limpia
                enemy.moveDown();   // Avanza
            }
        }
        movementCounter = 0;
    }

    // Eliminación de enemigos que llegan al fondo
    for (auto& enemy : enemies)
    {
        if (enemy.isAlive() && enemy.getY() + enemy.getHeight() >= getScreenHeight())
        {
            enemy.kill();
        }
    }
}

void EnemyManager::draw()
{
    for (const auto& enemy : enemies)
    {
        if (enemy.isAlive())
            enemy.draw();
    }
}

void EnemyManager::clear()
{
    for (auto& enemy : enemies)
    {
        if (enemy.isAlive())
            enemy.clear();
    }
}

void EnemyManager::checkCollisions(Bullet& bullet, Ship& player, bool& isRunning, int& score)
{
    for (auto& enemy : enemies)
    {
        if (enemy.isAlive())
        {
            if (bullet.isActive() && bullet.isCollidingWith(&enemy))
            {
                bullet.deactivate();
                enemy.kill();
                score += 10;
            }

            if (enemy.isCollidingWith(&player))
            {
                enemy.kill();
                player.takeDamage();
                player.flashOnHit();

                if (player.getLives() <= 0)
                {
                    isRunning = false;
                }
            }
        }
    }
}

// Reseteo de la lista y contador estático
void EnemyManager::reset()
{
    enemies.clear();
    Enemy::resetActiveCount();
}