#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>

/**
 * @brief Represents the 2D environment (grid) using a 1D vector<bool> for memory optimization.
 */
class Grid {
private:
    int width_;
    int height_;
    std::vector<bool> cells_; // Optimized container (1 bit per element)

    /**
     * @brief Converts 2D coordinates to a 1D index.
     * Throws an exception if out of bounds.
     */
    int getIndex(int x, int y) const;

public:
    Grid(int width, int height);

    /**
     * @brief Checks if a specific cell is black (true).
     */
    bool isBlack(int x, int y) const;

    /**
     * @brief Flips the color of a specific cell (white <-> black).
     */
    void flipColor(int x, int y);

    int getWidth() const { return width_; }
    int getHeight() const { return height_; }

    /**
     * @brief Hidden friend idiom to seamlessly print the grid status.
     */
    friend std::ostream& operator<<(std::ostream& os, const Grid& grid) {
        os << "Grid(" << grid.width_ << "x" << grid.height_ 
           << ", total cells: " << grid.cells_.size() << ")";
        return os;
    }
};
