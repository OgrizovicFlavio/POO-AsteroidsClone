#include "GameManager.h"
#include "AwesomeLibrary.h"
using namespace std;

GameManager::GameManager()
    : player(getScreenWidth() / 2 - 2, getScreenHeight() - 4), //Posición inicial del Player
    bullet(),
    enemyManager(40, 20), 
    hud(&player, score, scoreToWin),                           // HUD conectado al Player y puntaje
    input(player, bullet),                                     // Sistema de input referenciado al Player y a su disparo
    score(0),                                                  // Puntaje inicial
    scoreToWin(1000),                                          // Puntaje para ganar            
    isRunning(true)                                            // Comienza activo
{}

// Actualiza el estado del juego en cada frame
void GameManager::update()
{
    input.handleInput(isRunning);                                   // Manejo de input
    bullet.move();                                                  // Movimiento del disparo
    enemyManager.update();                                          // Spawn + movimiento enemigos
    enemyManager.checkCollisions(bullet, player, isRunning, score); // Colisiones entre Bullet y enemigos

    // Win condition
    if (score >= scoreToWin)
        isRunning = false;
}

void GameManager::draw()
{
    hud.draw();

    player.draw();
    bullet.draw();
    enemyManager.draw();

    // Mensajes de victoria y derrota
    if (player.getLives() <= 0)
        hud.showGameOver();
    else if (score >= scoreToWin)
        hud.showVictory();
}

bool GameManager::running() const
{
    return isRunning;
}

void GameManager::retryOrQuit()
{
    int centerX = getScreenWidth() / 2;
    int centerY = getScreenHeight() / 2;

    string retryText = "Press R to Retry";
    string quitText = "Press ESC to Quit";

    setForegroundColor(Color::WHITE);
    goToCoordinates(centerX - retryText.length() / 2, centerY + 2);
    cout << retryText;

    goToCoordinates(centerX - quitText.length() / 2, centerY + 3);
    cout << quitText;

    while (true)
    {
        if (_kbhit())
        {
            char key = _getch();
            if (key == 27) // ESC
            {
                exit(0);
            }
            else if (key == 'r' || key == 'R')
            {
                reset();
                break;
            }
        }
    }
}

void GameManager::reset()
{
    player = Ship(getScreenWidth() / 2 - 2, getScreenHeight() - 4);
    bullet.deactivate();
    enemyManager.reset();
    score = 0;
    isRunning = true;
}