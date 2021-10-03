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

gameEngine::gameEngine(){
    initVariables();
    initWindow(800, 600);
}

gameEngine::gameEngine(int height, int width){
    initVariables();
    initWindow(width, height);
}

gameEngine::~gameEngine() {
    delete this->window;
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
                break;
        }
    }
}

void gameEngine::renderScreen(){
    this->window->clear(sf::Color(0,0,255,255));
    dice Dice1(1, window, 10.0f, 10.0f, 100.0f);
    Dice1.drawSelf();
    dice Dice2(2, window, 120.0f, 10.0f, 100.0f);
    Dice2.drawSelf();
    dice Dice3(3, window, 230.0f, 10.0f, 100.0f);
    Dice3.drawSelf();
    dice Dice4(4, window, 340.0f, 10.0f, 100.0f);
    Dice4.drawSelf();
    dice Dice5(5, window, 450.0f, 10.0f, 100.0f);
    Dice5.drawSelf();
    dice Dice6(6, window, 560.0f, 10.0f, 100.0f);
    Dice6.drawSelf();
    this->window->display();
}
