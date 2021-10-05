#ifndef GAME_H
#define GAME__H

#include <SFML/Graphics.hpp>
#include <diceContainer.h>

class gameEngine {
private:
    // SF Variables
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event event;

    // Dice variables
    diceContainer *DiceContainer;

    // Initialization of variables to null
    void initVariables();

    // Initialize Window
    void initWindow(int, int);

    // Initialize the dice
    void initDice();

public:
    gameEngine();
    gameEngine(int, int);
    ~gameEngine();
    void rollDice();
    bool isRunning();
    bool gameEvent();
    void processEvent();
    void renderScreen();
};
#endif