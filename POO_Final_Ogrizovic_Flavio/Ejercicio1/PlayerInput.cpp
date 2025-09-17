#include "PlayerInput.h"
#include <conio.h>

PlayerInput::PlayerInput(Ship& player, Bullet& bullet)
    : player(player), bullet(bullet) {}

void PlayerInput::handleInput(bool& isRunning)
{
    if (_kbhit())
    {
        char key = _getch();

        if (key == 27) //ESC
        {
            isRunning = false;
        }
        else if (key == 75) //Left
        {
            player.clear();
            player.moveLeft();
        }
        else if (key == 77) //Right
        {
            player.clear();
            player.moveRight();
        }
        else if (key == ' ') //Space
        {
            if (!bullet.isActive())
            {
                int bulletX = player.getX() + player.getWidth() / 2;
                int bulletY = player.getY() - 1;
                bullet.fireFrom(bulletX, bulletY);
            }
        }
    }
}