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
    sf::VertexArray quad(sf::Quads, 4);
    quad[0].position = sf::Vector2f(10.f,10.f);
    quad[1].position = sf::Vector2f(110.f,10.f);
    quad[2].position = sf::Vector2f(110.f,110.f);
    quad[3].position = sf::Vector2f(10.f,110.f);
    this->window->draw(quad);
    this->window->display();
}
