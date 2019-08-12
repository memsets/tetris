#include "stack.h"

Stack::Stack() {
    stack.resize(15);
    for(int i = 0 ; i < 15 ; ++i) {
        stack[i].resize(10);
    }

    for (int col = 0; col < 15; col++) {
        for (int row = 0; row < 10; row++) {
            stack[col][row] = 0;
        }
    }
}

const std::vector<std::vector<int>> &Stack::getStack() const {
    return stack;
}

void Stack::pushStack(Figure figure) {
    for (auto &block : figure.getFigure()) {
        stack[block.getY() + figure.getY()][block.getX() + figure.getX()] = 1;
    }
}
