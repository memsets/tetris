#include <SFML/Graphics.hpp>
#include <iostream>
#include "figure.h"
#include "stack.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 700), "Tetris ultimate 0.001v");

    Stack stack;
    Figure figure;

    window.setFramerateLimit(60);
    sf::Clock clock;

    window.setKeyRepeatEnabled(false);
    while (window.isOpen()) {

        sf::Time time = clock.getElapsedTime();

        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    figure.rotate(stack);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    if (!figure.isCollisionLeft(stack)) {
                        figure.moveLeft();
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    if (!figure.isCollisionRight(stack)) {
                        figure.moveRight();
                    }
                }
            }
        }


        window.clear();

        std::cout << time.asSeconds() << std::endl;
        if (time.asSeconds() > 0.4f) {
            clock.restart();
            if (figure.isCollision(stack)) {
                stack.pushStack(figure);
                figure.removeFigure();
                figure.createFigure();
            }
            figure.moveDown();
        }

        for (size_t col = 0; col < 15; col++) {
            for (size_t row = 0; row < 10; row++) {
                sf::RectangleShape rect(sf::Vector2f(30, 30));


                rect.setPosition(30.0f * row, 30.0f * col);
                if (stack.getStack()[col][row] == 1) {
                    rect.setFillColor(sf::Color::Red);
                } else {
                    rect.setFillColor(sf::Color::Blue);
                }
                window.draw(rect);
            }
        }

        for (auto &block : figure.paint()) {
            window.draw(block);
        }

        window.display();
    }

    return 0;
}
