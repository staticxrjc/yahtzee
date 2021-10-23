#include <player.h>

void player::initVariables() {
    m_name = "";
}

player::player(){
    initVariables();
}

player::player(std::string name) {
    m_name = name;
}

player::~player() {}

// Set/Get Functions
std::string* player::getPlayerNameReference(){
    return &m_name;
}
std::string player::getPlayerName() {
    return m_name;
}

void player::setName(std::string name) {
    m_name = name;
}