#pragma once
#include "Ship.h"
#include "Bullet.h"

class PlayerInput 
{
private:
    Ship& player;
    Bullet& bullet;

public:
    PlayerInput(Ship& player, Bullet& bullet);

    void handleInput(bool& isRunning);
};