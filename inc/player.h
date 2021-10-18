#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

class player {
private:
    // player name
    std::string m_name;
public:
    player(std::string);
    ~player();

    // Set/Get Functinos
    std::string getName();
    void setName(std::string);
};

#endif