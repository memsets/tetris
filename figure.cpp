#include "figure.h"
#include "stack.h"

Figure::Figure() : shapeSize(4)
{
    this->x = 3;
    this->y = 0;
    createFigure(1);
}

void Figure::createFigure(int shape, int shapeRotation)
{
    for (int row = 0; row < shapeSize; row++) {
        for (int col = 0; col < shapeSize; col++) {
            if (SHAPES[shape][shapeRotation][row][col] == 1) {
                figure.emplace_back(col, row);
            }
        }
    }
}

std::vector<Block> Figure::createVirtualFigure(int shape, int shapeRotation)
{
    std::vector<Block> virtualFigure;
    for (int row = 0; row < shapeSize; row++) {
        for (int col = 0; col < shapeSize; col++) {
            if (SHAPES[shape][shapeRotation][row][col] == 1) {
                virtualFigure.emplace_back(col, row);
            }
        }
    }

    return virtualFigure;
}

bool Figure::isWrongPosition(std::vector<Block> vf, Stack &stack)
{
    for (auto &block : vf) {
        auto xPos = static_cast<size_t>(block.getY() + y);
        auto yPos = static_cast<size_t>(block.getX() + x);

        if (block.getX() + x >= 10 || block.getX() + x < 0 ||
                stack.getStack()[yPos][xPos] == 1) {
            return true;
        }
    }
    return false;
}

void Figure::removeFigure()
{
    figure.clear();
    this->x = 3;
    this->y = 0;
}

void Figure::rotate(Stack &stack)
{
    static int rotation = 0;
    switch (rotation) {
        case 0:
        if (!isWrongPosition(createVirtualFigure(0, 1), stack)) {
            figure.clear();
            rotation = 1;
            createFigure(0, 1);
        }
            break;
        case 1:
        if (!isWrongPosition(createVirtualFigure(0, 2), stack)) {
            figure.clear();
            rotation = 2;
            createFigure(0, 2);
        }
            break;
        case 2:
        if (!isWrongPosition(createVirtualFigure(0, 3), stack)) {
            figure.clear();
            rotation = 3;
            createFigure(0, 3);
        }
            break;
        case 3:
        if (!isWrongPosition(createVirtualFigure(0, 0), stack)) {
            figure.clear();
            rotation = 0;
            createFigure(0, 0);
        }
            break;
    default:
        rotation = 0;
        createFigure(0);
    }
}

void Figure::moveDown()
{
    y++;
}

std::vector<sf::RectangleShape> Figure::paint()
{
    std::vector<sf::RectangleShape> shapes;
    for (auto &block : figure) {
        auto b = block.paint();

        auto xPos = static_cast<float>(block.getX() * block.getBlockSize() + x * block.getBlockSize());
        auto yPos = static_cast<float>(block.getY() * block.getBlockSize() + y * block.getBlockSize());

        b.setPosition(xPos, yPos);
        shapes.push_back(b);
    }
    return shapes;
}

void Figure::moveLeft()
{
    x--;
}

void Figure::moveRight()
{
    x++;
}

bool Figure::isCollisionRight(Stack &stack)
{
    for (auto &block : figure) {
        auto yPos = static_cast<size_t>(y + block.getY());
        auto xPos = static_cast<size_t>(x + block.getX() + 1);

        if (x + block.getX() + 1 == 10 ||
                stack.getStack()[yPos][xPos] == 1) {
            return true;
        }
    }
    return false;
}

bool Figure::isCollisionLeft(Stack &stack)
{
    for (auto &block : figure) {
        auto yPos = static_cast<size_t>(y + block.getY());
        auto xPos = static_cast<size_t>(x + block.getX() - 1);

        if (x + block.getX() == 0 || stack.getStack()[yPos][xPos] == 1) {
            return true;
        }
    }
    return false;
}

bool Figure::isCollision(Stack &stack)
{
    for (auto &block : figure) {
        auto yPos = static_cast<size_t>(y + block.getY() + 1);
        auto xPos = static_cast<size_t>(x + block.getX());

        if (y + block.getY() + 1 == 15 || stack.getStack()[yPos][xPos]) {
            return true;
        }
    }
    return false;
}

const std::vector<Block> &Figure::getFigure() const
{
    return figure;
}

int Figure::getX() const
{
    return x;
}

int Figure::getY() const
{
    return y;
}
