#include <dice.h>

dice::dice(int value, sf::RenderWindow *window) 
    : m_value(value), m_window(window) {
        m_xPosition = 0.0f;
        m_yPosition = 0.0f;
        m_size = 100.0f;
}

dice::dice(int value, sf::RenderWindow *window, float x, float y, float size) 
    : m_value(value), m_window(window), m_xPosition(x), m_yPosition(y), m_size(size) {}

void dice::setValue(int value) {
    m_value = value;
}

int dice::getValue() { return m_value; }

void dice::drawSelf() {
    sf::CircleShape shape(5.f);
    sf::VertexArray quad(sf::Quads, 4);
    quad[0].position = sf::Vector2f(m_xPosition,m_yPosition);
    quad[1].position = sf::Vector2f(m_xPosition + m_size,m_yPosition);
    quad[2].position = sf::Vector2f(m_xPosition + m_size,m_yPosition + m_size);
    quad[3].position = sf::Vector2f(m_xPosition,m_yPosition + m_size);
    this->m_window->draw(quad);

    switch (m_value) {
        case 1:
        shape.setFillColor(sf::Color(0,0,0,255));
        shape.setPosition(m_xPosition + (m_size/2) - shape.getRadius(),m_yPosition + (m_size/2) - shape.getRadius());
        break;
        default:
        break;
    }
    this->m_window->draw(shape);
}