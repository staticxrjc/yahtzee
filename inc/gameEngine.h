#ifndef GAME_H
#define GAME__H

#include <SFML/Graphics.hpp>
#include <diceContainer.h>
#include <player.h>

class gameEngine {
private:
    // SF Variables
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event event;
    sf::Vector2i mousePosition;
    sf::Vector2f mousePositionRelative;

    // Dice variables
    diceContainer *DiceContainer;

    // Players variables
    player *m_player[6];
    int m_numberOfPlayers;

    // Initialization of variables to null
    void initVariables();

    // Initialize Window
    void initWindow(int, int);

    // Initialize the dice
    void initDice();

    // Initialize Players
    void initPlayers();

    // Prompting functions
    int promptInt(std::string);
    std::string promptString(std::string);

public:
    gameEngine();
    gameEngine(int, int);
    ~gameEngine();
    void rollDice();
    void updateMousePosition();
    bool isRunning();
    bool gameEvent();
    void processEvent();
    void renderScreen();
};
#endif