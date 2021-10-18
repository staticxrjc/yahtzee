#include <diceContainer.h>

void diceContainer::initVariables() {
    m_diceSize = 80.0f;
    m_padding = 15.0f;
    m_xPosition = 0.0f;
    m_yPosition = 0.0f;
    for (int i = 0; i < diceSet.size(); i++) {
        diceSet[i] = new dice(0,this->m_window,m_xPosition + (i+1)*m_padding + (i*m_diceSize),m_yPosition + m_padding,m_diceSize);
    }

}

diceContainer::diceContainer(sf::RenderWindow* window) {
    m_window = window;
    initVariables();
    drawDice();
}

diceContainer::~diceContainer() {
    // DELETE THE NEW DICE
    for (int i = 0; i < diceSet.size(); i++) {
        delete diceSet[i];
    }
}

void diceContainer::drawDice() {
    for (int i = 0; i < diceSet.size(); i++) {
        diceSet[i]->drawSelf();
    }
}

void diceContainer::rollDice() {
    for (int i = 0; i < diceSet.size(); i++) {
        diceSet[i]->rollDice();
    }
}

void diceContainer::checkIfSelected(sf::Vector2f *mousePosition) {
    for (int i = 0; i < diceSet.size(); i++) {
        if(diceSet[i]->vertexInBounds(mousePosition)) {
            diceSet[i]->toggleSelected();
        }
    }
}