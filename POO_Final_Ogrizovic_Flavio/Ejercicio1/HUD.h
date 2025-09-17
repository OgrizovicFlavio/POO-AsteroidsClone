#pragma once
#include "Ship.h"

class HUD
{
private:
    Ship* player;
    int& score;
    int scoreToWin;

public:
    HUD(Ship* player, int& scoreRef, int scoreToWin);

    void draw() const;
    void showGameOver() const;
    void showVictory() const;
};

