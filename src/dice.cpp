#include <dice.h>

void dice::initVariables() {
    sf::Color dotColor(0,0,0,255);
    float dotRadius = m_size/12;
    m_selected = false;
    // Set center dot location
    m_diceDots[0].setRadius(dotRadius);
    m_diceDots[0].setFillColor(dotColor);
    m_diceDots[0].setPosition(m_xPosition + (m_size/2) - m_diceDots[0].getRadius(),m_yPosition + (m_size/2) - m_diceDots[0].getRadius());

    // Set top left dot location
    m_diceDots[1].setRadius(dotRadius);
    m_diceDots[1].setFillColor(dotColor);
    m_diceDots[1].setPosition((m_xPosition + (m_size/4) - m_diceDots[1].getRadius()),m_yPosition + (m_size/4) - m_diceDots[1].getRadius());

    // Set left dot location
    m_diceDots[2].setRadius(dotRadius);
    m_diceDots[2].setFillColor(dotColor);
    m_diceDots[2].setPosition((m_xPosition + (m_size/4) - m_diceDots[2].getRadius()),m_yPosition + (m_size/2) - m_diceDots[2].getRadius());
    
    // Set bottom left dot location
    m_diceDots[3].setRadius(dotRadius);
    m_diceDots[3].setFillColor(dotColor);
    m_diceDots[3].setPosition((m_xPosition + (m_size/4) - m_diceDots[3].getRadius()),m_yPosition + (m_size * 3/4) - m_diceDots[3].getRadius());
    
    // Set top right dot location
    m_diceDots[4].setRadius(dotRadius);
    m_diceDots[4].setFillColor(dotColor);
    m_diceDots[4].setPosition((m_xPosition + (m_size * 3/4) - m_diceDots[4].getRadius()),m_yPosition + (m_size/4) - m_diceDots[4].getRadius());
    
    // Set right dot location
    m_diceDots[5].setRadius(dotRadius);
    m_diceDots[5].setFillColor(dotColor);
    m_diceDots[5].setPosition((m_xPosition + (m_size * 3/4) - m_diceDots[5].getRadius()),m_yPosition + (m_size/2) - m_diceDots[5].getRadius());
    
    // Set bottom right dot location
    m_diceDots[6].setRadius(dotRadius);
    m_diceDots[6].setFillColor(dotColor);
    m_diceDots[6].setPosition((m_xPosition + (m_size * 3/4) - m_diceDots[6].getRadius()),m_yPosition + (m_size * 3/4) - m_diceDots[6].getRadius());

}

dice::dice(int value, sf::RenderWindow *window) 
    : m_value(value), m_window(window) {
        m_xPosition = 0.0f;
        m_yPosition = 0.0f;
        m_size = 100.0f;
        initVariables();
        if (m_value == 0) {
            rollDice();
        }
}

dice::dice(int value, sf::RenderWindow *window, float x, float y, float size) 
    : m_value(value), m_window(window), m_xPosition(x), m_yPosition(y), m_size(size) {
        initVariables();
        if (m_value == 0) {
            rollDice();
        }
    }

void dice::setValue(int value) {
    m_value = value;
}

void dice::rollDice() {
    if(!m_selected) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6);

        m_value = dist6(rng);
    }
}

bool dice::getSelected(){ return m_selected; }

void dice::setSelected(bool selected) {
    m_selected = selected;
}

void dice::toggleSelected(){
    m_selected = !m_selected;
}

bool dice::vertexInBounds(sf::Vector2f *mousePosition){
    if (mousePosition->y >= m_yPosition && mousePosition->y <= (m_yPosition + m_size))
        if (mousePosition->x >= m_xPosition && mousePosition->x <= (m_xPosition + m_size))
            return true;
    return false;
}

int dice::getValue() { return m_value; }

void dice::drawSelf() {
    sf::VertexArray quad(sf::Quads, 4);
    quad[0].position = sf::Vector2f(m_xPosition,m_yPosition);
    quad[1].position = sf::Vector2f(m_xPosition + m_size,m_yPosition);
    quad[2].position = sf::Vector2f(m_xPosition + m_size,m_yPosition + m_size);
    quad[3].position = sf::Vector2f(m_xPosition,m_yPosition + m_size);
    this->m_window->draw(quad);

    // If selected draw box around dice
    if (m_selected) {
        sf::Color lineColor(255,0,0,255);
        sf::VertexArray box(sf::LineStrip, 5);
        int thickness = 4;
        for (int i = 0; i < thickness; i++) {
            box[0].position = sf::Vector2f(m_xPosition,m_yPosition + i);
            box[0].color = lineColor;
            box[1].position = sf::Vector2f(m_xPosition + m_size - i,m_yPosition + i);
            box[1].color = lineColor;
            box[2].position = sf::Vector2f(m_xPosition + m_size - i,m_yPosition + m_size - i);
            box[2].color = lineColor;
            box[3].position = sf::Vector2f(m_xPosition + i,m_yPosition + m_size - i);
            box[3].color = lineColor;
            box[4].position = sf::Vector2f(m_xPosition + i,m_yPosition + i);
            box[4].color = lineColor;
            this->m_window->draw(box);
        }
    }

    // Middle position
    if( m_value == 1 || m_value == 3 || m_value == 5 ) {
        this->m_window->draw(m_diceDots[0]);
    }

    // Toop left position
    // bottom right position
    if( m_value > 1 ) {
        this->m_window->draw(m_diceDots[1]);
        this->m_window->draw(m_diceDots[6]);
    }

    // left position
    // right position
    if( m_value == 6 ) {
        this->m_window->draw(m_diceDots[2]);
        this->m_window->draw(m_diceDots[5]);
    }

    // bottom left position
    // top right position
    if( m_value > 3 ) {
        this->m_window->draw(m_diceDots[3]);
        this->m_window->draw(m_diceDots[4]);
    }
}