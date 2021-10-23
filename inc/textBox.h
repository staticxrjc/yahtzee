#ifndef TEXTBOX_H
#define TEXTBOX_H
#include <string>
#include <iostream>
#include <bitset>
#include <SFML/Graphics.hpp>

template<typename T>
class textBox {
private:
    T *m_value;
    int m_maxSize;
    int m_x,m_y;
    std::string m_prompt;
    sf::Event event;
    sf::RenderWindow *m_parentWindow;

    // initialize variables for textBox
    void initVariables(){
        m_x, m_y = 0;
        m_maxSize = 5;
        // Make this a reference to what is being changed
        // if player name is being changed for exmple
        m_value = nullptr;
    }

    void drawSelf(){
        sf::VertexArray quad(sf::Quads, 4);
        quad[0].position = sf::Vector2f(10,10);
        quad[1].position = sf::Vector2f(100,10);
        quad[2].position = sf::Vector2f(100,100);
        quad[3].position = sf::Vector2f(10,100);
        this->m_parentWindow->draw(quad);
    }

public:
    textBox(sf::RenderWindow *window){
        m_parentWindow = window;
        initVariables();
        *m_value = 0;
    }
    textBox(sf::RenderWindow *window, T* value){
        m_parentWindow = window;
        initVariables();
        m_value = value;
        *m_value = 0;
    }
    ~textBox(){};

    // Set/Get functions
    std::string getPrompt() { return m_prompt; }
    void setPrompt(const char* value) { m_prompt = value; }

    // enter text
    void enterText(sf::Uint32 key){
        std::cout << "unicode: " << key << std::endl;
        std::cout << "char: " << (char)key << std::endl;
    }

    // Display text box and read in input
    void promptForInput() {
        bool entryFinished = false;
        std::cout << "Enter Number of Players" << std::endl;
        while(!entryFinished){
            // read input event
            while (this->m_parentWindow->pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::TextEntered:
                        if(event.text.unicode == 27 || event.text.unicode == 13) {
                            entryFinished = true;
                            std::cout << *m_value << std::endl;
                        } else 
                            if(typeid(T) == typeid(int))
                                *m_value += (int)event.text.unicode - 48;
                        break;
                }
            }

            // draw prompt
            this->m_parentWindow->clear(sf::Color(0,0,255,255));
            this->drawSelf();
            this->m_parentWindow->display();

        }
    }
};
#endif