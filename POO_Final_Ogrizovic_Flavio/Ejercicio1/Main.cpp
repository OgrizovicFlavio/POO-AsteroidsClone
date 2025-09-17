#include <windows.h>
#include "AwesomeLibrary.h"
#include "GameManager.h"

int main()
{
    hideCursor();

    while (true)
    {
        clearScreen(); // Limpio la consola antes de empezar

        GameManager game; // Instancia

        // Bucle principal
        while (game.running())
        {
            goToCoordinates(0, 0);

            game.update(); // Lógica del juego: inputs, movimiento, colisiones, etc.
            game.draw();   // Dibujo

            Sleep(15);     // Pausa para controlar la velocidad del juego
        }

        game.retryOrQuit();
    }

    showCursor();
    return 0;
}

