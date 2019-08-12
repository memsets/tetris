#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>

class Block {
    const int blockSize;
    int x, y;
public:
    Block(int x, int y);

    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    sf::RectangleShape paint();
    int getBlockSize() const;
};

#endif // BLOCK_H
