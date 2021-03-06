#include <gameEngine.h>

// Private Functions
void gameEngine::initVariables(){
    this->window = nullptr;
    gameOver = false;
}

// init fonts
void gameEngine::initFonts(){
    if(!this->font.loadFromFile("../fonts/Nasa21-l23X.ttf")){
        std::cout << "ERROR: Failed to load font\n";
    }
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
    // Create a new textBox
    // m_textBoxPrompt = new textBox((std::string*)m_numberOfPlayers);
    textBox<int> numPlayers(window, &m_numberOfPlayers, &font);
    numPlayers.setPrompt("Enter Number of players: _");
    numPlayers.promptForInput();
    // 2) For each player, prompt name and create no player class
    for (int i = 0; i < m_numberOfPlayers; i++) {
        m_player[i] = new player();
        std::cout << "Player " << i+1 << " name: ";
        std::string name;
        std::cin >> name;
        m_player[i]->setName(name);
        // m_textBoxPrompt = new textBox(m_player[i]->getPlayerNameReference());
        interuptTextEntry();
        std::cout << "Player " << m_player[i]->getPlayerName() << std::endl;
    }
}

int gameEngine::promptInt(const std::string question) {
    return 1;
}

std::string gameEngine::promptString(const std::string question) {
    return "taco";
}

gameEngine::gameEngine(){
    initVariables();
    initFonts();
    initWindow(800, 600);
    initPlayers();
    initDice();
}

gameEngine::gameEngine(int height, int width){
    initVariables();
    initFonts();
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

void gameEngine::interuptTextEntry(){
    while(this->window->pollEvent(event)){
        switch (event.type) {
            case sf::Event::TextEntered:

                // If escape is pressed (for testing)
                if(event.text.unicode == 27) {
                }
            break;
        }
    }
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
