#include <gameEngine.h>

int main()
{
    gameEngine game;

    while (game.isRunning()) {
        // Event Loop
        game.processEvent();

        // Update

        //Render
        game.renderScreen();

    }

    return 0;
}