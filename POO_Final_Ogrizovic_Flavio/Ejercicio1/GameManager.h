#pragma once
#include "Ship.h"
#include "Bullet.h"
#include "HUD.h"
#include "EnemyManager.h"
#include "PlayerInput.h"

//Controla el game loop
class GameManager
{
private:
    //Instancias de cada clase
    Ship player;
    Bullet bullet;
    EnemyManager enemyManager;

    int score;
    int scoreToWin;

    HUD hud;
    PlayerInput input;
    bool isRunning;

public:
    GameManager();

    void update();
    void draw();            //Dibuja todos los elementos visuales
    bool running() const; 
    void retryOrQuit();     //Maneja la lógica para el fin de juego
    void reset();           //Reseteo de variables para volver a jugar
};

