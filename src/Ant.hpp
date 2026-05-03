#pragma once
#include "IAgent.hpp"
#include <iostream>

/**
 * @brief Represents Langton's Ant.
 * Inherits from IAgent to demonstrate.
 */
class Ant : public IAgent {
private:
    int x_, y_;
    int dx_, dy_;

public:
    Ant(int start_x, int start_y);

    /**
     * @brief Applies a -90 degree rotation matrix (clockwise) to the direction vector.
     */
    void turnRight();

    /**
     * @brief Applies a +90 degree rotation matrix (counter-clockwise) to the direction vector.
     */
    void turnLeft();

    /**
     * @brief Updates the ant's position and interacts with the grid.
     */
    void step(Grid& grid) override;

    // Getters
    int getX() const override { return x_; }
    int getY() const override { return y_; }
    int getDx() const override { return dx_; }
    int getDy() const override { return dy_; }

    void print(std::ostream& os) const override {
        os << "Ant[Pos:(" << x_ << "," << y_ 
           << ") Dir:(" << dx_ << "," << dy_ << ")]";
    }
};
