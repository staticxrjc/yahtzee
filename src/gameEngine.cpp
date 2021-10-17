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
    DiceContainer = new diceContainer(window);
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
    delete DiceContainer;
}

void gameEngine::rollDice() {
    DiceContainer->rollDice();
}

void gameEngine::updateMousePosition() {
    mousePosition = sf::Mouse::getPosition(*this->window);
    mousePositionRelative = this->window->mapPixelToCoords(this->mousePosition);
    std::cout << "Mouse X: " << mousePositionRelative.x << std::endl;
    std::cout << "Mouse Y: " << mousePositionRelative.y << std::endl;
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
            case sf::Event::MouseButtonPressed:
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    this->updateMousePosition();
                    this->DiceContainer->checkIfSelected(&mousePositionRelative);
                }
                break;
        }
    }
}

void gameEngine::renderScreen(){
    this->window->clear(sf::Color(0,0,255,255));
    DiceContainer->drawDice();
    this->window->display();
}
