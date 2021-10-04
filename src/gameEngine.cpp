#include <gameEngine.h>

// Private Functions
void gameEngine::initVariables(){
    this->window = nullptr;
}

void gameEngine::initWindow(int width, int height){
    this->videoMode.height = height;
    this->videoMode.width = width;
    this->window = new sf::RenderWindow(this->videoMode, "Yahtzee!");
}

void gameEngine::initDice(){
    Dice1 = new dice(0, window, 10.0f, 10.0f, 100.0f);
    Dice2 = new dice(0, window, 120.0f, 10.0f, 100.0f);
    Dice3 = new dice(0, window, 230.0f, 10.0f, 100.0f);
    Dice4 = new dice(0, window, 340.0f, 10.0f, 100.0f);
    Dice5 = new dice(0, window, 450.0f, 10.0f, 100.0f);
}

gameEngine::gameEngine(){
    initVariables();
    initWindow(800, 600);
    initDice();
}

gameEngine::gameEngine(int height, int width){
    initVariables();
    initWindow(width, height);
}

gameEngine::~gameEngine() {
    delete this->window;
    delete Dice1;
    delete Dice2;
    delete Dice3;
    delete Dice4;
    delete Dice5;
}

void gameEngine::rollDice() {
    Dice1->rollDice();
    Dice2->rollDice();
    Dice3->rollDice();
    Dice4->rollDice();
    Dice5->rollDice();
}

bool gameEngine::isRunning(){
    return this->window->isOpen();
}

void gameEngine::processEvent(){
    while (this->window->pollEvent(event))
    {
        switch (event.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    window->close();
                if (event.key.code == sf::Keyboard::Enter)
                    this->rollDice();
                break;
        }
    }
}

void gameEngine::renderScreen(){
    this->window->clear(sf::Color(0,0,255,255));
    Dice1->drawSelf();
    Dice2->drawSelf();
    Dice3->drawSelf();
    Dice4->drawSelf();
    Dice5->drawSelf();
    this->window->display();
}
