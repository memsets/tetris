#ifndef FIGURE_H
#define FIGURE_H

#include "block.h"

#include <vector>
#include <SFML/Graphics.hpp>

class Stack;
class Figure
{
    const int shapeSize;
    int SHAPES[7][4][4][4] = {
        {   { {0,0,0,0}, {1,1,1,1}, {0,0,0,0}, {0,0,0,0} },
            { {0,1,0,0}, {0,1,0,0}, {0,1,0,0}, {0,1,0,0} },
            { {0,0,0,0}, {1,1,1,1}, {0,0,0,0}, {0,0,0,0} },
            { {0,1,0,0}, {0,1,0,0}, {0,1,0,0}, {0,1,0,0} }
        }, // I

        {   { {0,0,0,0}, {0,1,1,0}, {0,1,1,0}, {0,0,0,0} },
            { {0,0,0,0}, {0,1,1,0}, {0,1,1,0}, {0,0,0,0} }

        }, // O

        {   { {1,0,0,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0} },
            { {0,1,1,0}, {0,1,0,0}, {0,1,0,0}, {0,0,0,0} }
        }, // J

        {   { {0,0,1,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0} },
            { {0,0,1,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0} }
        }, // L

        {   { {0,1,1,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0} },
            { {0,1,1,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0} }
        }, // S

        {   { {1,1,1,0}, {0,1,0,0}, {0,0,0,0}, {0,0,0,0} },
            { {1,1,1,0}, {0,1,0,0}, {0,0,0,0}, {0,0,0,0} }
        }, // T

        {   { {1,1,0,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0} },
            { {1,1,0,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0} }
        }  // Z
    };

    int x, y;
    std::vector<Block> figure;
public:
    int getX() const;

    int getY() const;

    const std::vector<Block> &getFigure() const;

    Figure();
    void createFigure(int shape = 0, int shapeRotation = 0);
    std::vector<Block> createVirtualFigure(int shape = 0, int shapeRotation = 0);
    bool isWrongPosition(std::vector<Block> vf, Stack &stack);
    void removeFigure();
    void rotate(Stack &stack);
    void moveDown();
    void moveLeft();
    void moveRight();
    bool isCollisionLeft(Stack &stack);
    bool isCollisionRight(Stack &stack);
    bool isCollision(Stack &stack);
    std::vector<sf::RectangleShape> paint();
};

#endif // FIGURE_H
