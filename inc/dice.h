#ifndef DICE_H
#define DICE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

class dice {
private:
    int m_value;
    sf::CircleShape m_diceDots[7];
    float m_xPosition;
    float m_yPosition;
    float m_size;
    bool m_selected;
    sf::RenderWindow *m_window;

    // private functions
    void initVariables();

public:
    dice(int, sf::RenderWindow*, float, float, float);
    dice(int, sf::RenderWindow*);
    void setValue(int);
    void rollDice();
    bool getSelected();
    void setSelected(bool);
    void toggleSelected();
    bool vertexInBounds(sf::Vector2f*);
    int getValue();
    void drawSelf();
};

#endif