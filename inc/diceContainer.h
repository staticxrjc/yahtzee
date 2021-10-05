#ifndef DICECONTAINER_H
#define DICECONTAINER_H
#include <dice.h>

class diceContainer {
private:
    float m_xPosition, m_yPosition, m_padding, m_diceSize;
    std::array<dice*,5> diceSet; 
    sf::RenderWindow *m_window;

    void initVariables();
 
 public:
    diceContainer(sf::RenderWindow*);
    ~diceContainer();
    void drawDice();
    void rollDice();
};
#endif // DICECONTAINER_H