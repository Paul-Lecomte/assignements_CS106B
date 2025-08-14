#include <SFML/Graphics.hpp>

void drawSierpinski(sf::RenderWindow& window, sf::Vector2f a, sf::Vector2f b, sf::Vector2f c, int depth) {
    if (depth == 0) {
        sf::ConvexShape triangle;
        triangle.setPointCount(3);
        triangle.setPoint(0, a);
        triangle.setPoint(1, b);
        triangle.setPoint(2, c);
        triangle.setFillColor(sf::Color::White);
        window.draw(triangle);
    } else {
        sf::Vector2f ab = (a + b) / 2.f;
        sf::Vector2f ac = (a + c) / 2.f;
        sf::Vector2f bc = (b + c) / 2.f;
        drawSierpinski(window, a, ab, ac, depth - 1);
        drawSierpinski(window, ab, b, bc, depth - 1);
        drawSierpinski(window, ac, bc, c, depth - 1);
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sierpinski Triangle");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        drawSierpinski(window, {400, 50}, {50, 550}, {750, 550}, 6); // profondeur 6
        window.display();
    }
    return 0;
}