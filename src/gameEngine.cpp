#include <gameEngine.h>

// Private Functions
void gameEngine::initVariables(){
    this->window = nullptr;
    m_numberOfPlayers = 0;
}

void gameEngine::initWindow(int width, int height){
    this->videoMode.height = height;
    this->videoMode.width = width;
    this->window = new sf::RenderWindow(this->videoMode, "Yahtzee!");
}

void gameEngine::initDice(){
    DiceContainer = new diceContainer(window);
}

void gameEngine::initPlayers(){
    // 1) Dialogue that prompts number of players
    m_numberOfPlayers = promptInt("How many players?");
    // 2) For each player, prompt name and create no player class
    for (int i = 0; i < m_numberOfPlayers; i++) {
        m_player[i] = new player(promptString("Enter player # name: "));
    }
    std::cout << m_player[0]->getName() << std::endl;
}

int gameEngine::promptInt(const std::string question) {
    return 1;
}

std::string gameEngine::promptString(const std::string question) {
    return "taco";
}

gameEngine::gameEngine(){
    initVariables();
    initWindow(800, 600);
    initPlayers();
    initDice();
}

gameEngine::gameEngine(int height, int width){
    initVariables();
    initWindow(width, height);
    initPlayers();
    initDice();
}

gameEngine::~gameEngine() {
    delete this->window;
    delete DiceContainer;
    for(int i = 0; i < m_numberOfPlayers; i++){
        delete m_player[i];
    }
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
