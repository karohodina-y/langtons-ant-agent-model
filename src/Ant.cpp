#include "Ant.hpp"
#include "Grid.hpp"

Ant::Ant(int start_x, int start_y) : x_(start_x), y_(start_y), dx_(0), dy_(-1) {
    // Starts facing "UP" (y decreases going up in grid coordinates)
}

void Ant::turnRight() {
    // Rotation matrix for -90 degrees:
    // dx_new = -dy
    // dy_new = dx
    int temp_dx = dx_;
    dx_ = -dy_;
    dy_ = temp_dx;
}

void Ant::turnLeft() {
    // Rotation matrix for +90 degrees:
    // dx_new = dy
    // dy_new = -dx
    int temp_dx = dx_;
    dx_ = dy_;
    dy_ = -temp_dx;
}

void Ant::step(Grid& grid) {
    bool is_black = grid.isBlack(x_, y_);
    if (is_black) {
        turnLeft();
    } else {
        turnRight();
    }
    grid.flipColor(x_, y_);
    
    x_ += dx_;
    y_ += dy_;
}
