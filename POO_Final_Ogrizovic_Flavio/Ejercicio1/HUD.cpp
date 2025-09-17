#include "HUD.h"
#include "Enemy.h"
#include <iostream>
using namespace std;

HUD::HUD(Ship* player, int& scoreRef, int scoreToWin)
    : player(player), score(scoreRef), scoreToWin(scoreToWin) {}

void HUD::draw() const
{
    setForegroundColor(Color::BLUE);

    // Línea de datos
    goToCoordinates(2, 2);
    for (int i = 0; i < getScreenWidth(); ++i) cout << ' ';
    goToCoordinates(2, 2);
    cout << "Lives: ";
    for (int i = 0; i < player->getLives(); ++i)
        cout << (char)3 << ' ';
    cout << "   Score: " << score << "/" << scoreToWin;
    cout << "   Active enemies: " << Enemy::getActiveCount();

    // Línea divisoria
    goToCoordinates(1, 3);
    for (int i = 0; i < getScreenWidth() - 2; ++i) cout << '-';
}

void HUD::showGameOver() const
{
    setForegroundColor(Color::LRED);
    goToCoordinates(getScreenWidth() / 2 - 5, getScreenHeight() / 2);
    cout << "GAME OVER";
}

void HUD::showVictory() const
{
    setForegroundColor(Color::LGREEN);
    goToCoordinates(getScreenWidth() / 2 - 4, getScreenHeight() / 2);
    cout << "VICTORY";
}