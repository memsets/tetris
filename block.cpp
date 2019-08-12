#include "block.h"

int Block::getBlockSize() const {
    return blockSize;
}

Block::Block(int x, int y) : blockSize(30), x(x), y(y) {
}

sf::RectangleShape Block::paint() {
    sf::RectangleShape rect(sf::Vector2f(blockSize, blockSize));
    rect.setPosition(x * blockSize, y * blockSize);
    return rect;
}


int Block::getX() const {
    return x;
}

void Block::setX(int value) {
    x = value;
}

int Block::getY() const {
    return y;
}

void Block::setY(int value) {
    y = value;
}
