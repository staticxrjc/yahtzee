#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

class player {
private:
    // player name
    std::string m_name;

    //init vairables
    void initVariables();
public:
    player();
    player(std::string);
    ~player();

    // Set/Get Functinos
    std::string* getPlayerNameReference();
    std::string getPlayerName();
    void setName(std::string);
};

#endif