#ifndef TETRIS_STACK_H
#define TETRIS_STACK_H

#include <vector>
#include "figure.h"

class Stack {
    std::vector<std::vector<int>> stack;
public:
    const std::vector<std::vector<int>> &getStack() const;
    Stack();
    void pushStack(Figure figure);
};


#endif //TETRIS_STACK_H
