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
    float m_x,m_y,m_width,m_height,m_padding;
    sf::Text m_prompt;
    sf::Event event;
    sf::RenderWindow *m_parentWindow;
    sf::Font *m_font;

    // initialize variables for textBox
    void initVariables(){
        m_x, m_y = 0.0f;
        m_width = 400.0f;
        m_height = 50.0f;
        m_padding = 5.0f;
        m_maxSize = 5;
        // Make this a reference to what is being changed
        // if player name is being changed for exmple
        m_value = nullptr;
    }

    void initText(){
        this->m_prompt.setFont(*m_font);
        this->m_prompt.setCharacterSize(22);
        this->m_prompt.setFillColor(sf::Color::White);
        this->m_prompt.setPosition(sf::Vector2f(m_x+m_padding*2,m_y+m_padding*2));
    }

    void drawSelf(){
        sf::VertexArray quad(sf::Quads, 4);
        quad[0].position = sf::Vector2f(m_x,m_y);
        quad[1].position = sf::Vector2f(m_x+m_width,m_y);
        quad[2].position = sf::Vector2f(m_x+m_width,m_y+m_height);
        quad[3].position = sf::Vector2f(m_x,m_y+m_height);
        this->m_parentWindow->draw(quad);
        quad[0].position = sf::Vector2f(m_x+m_padding,m_y+m_padding);
        quad[0].color = sf::Color::Black;
        quad[1].position = sf::Vector2f(m_x+m_width-m_padding,m_y+m_padding);
        quad[1].color = sf::Color::Black;
        quad[2].position = sf::Vector2f(m_x+m_width-m_padding,m_y+m_height-m_padding);
        quad[2].color = sf::Color::Black;
        quad[3].position = sf::Vector2f(m_x+m_padding,m_y+m_height-m_padding);
        quad[3].color = sf::Color::Black;
        this->m_parentWindow->draw(quad);
        this->m_parentWindow->draw(this->m_prompt);
    }

public:
    textBox(sf::RenderWindow *window){
        m_parentWindow = window;
        initVariables();
        *m_value = 0;
    }
    textBox(sf::RenderWindow *window, T* value, sf::Font *font){
        m_parentWindow = window;
        m_font = font;
        initVariables();
        initText();
        m_value = value;
        *m_value = 0;
    }
    ~textBox(){};

    // Set/Get functions
    std::string getPrompt() { return this->m_prompt.getString(); }
    void setPrompt(std::string value) { this->m_prompt.setString(value); }

    // enter text
    void enterText(sf::Uint32 key){
        std::cout << "unicode: " << key << std::endl;
        std::cout << "char: " << (char)key << std::endl;
    }

    // Display text box and read in input
    void promptForInput() {
        bool entryFinished = false;
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