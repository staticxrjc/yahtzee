#include <player.h>

player::player(std::string name) {
    m_name = name;
}

player::~player() {}

// Set/Get Functions
std::string player::getName() {
    return m_name;
}

void player::setName(std::string name) {
    m_name = name;
}