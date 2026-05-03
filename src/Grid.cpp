#include "Grid.hpp"

Grid::Grid(int width, int height) : width_(width), height_(height) {
    // Initialize with all false (white)
    cells_.resize(width_ * height_, false);
}

int Grid::getIndex(int x, int y) const {
    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        throw std::out_of_range("Coordinates out of grid bounds.");
    }
    return y * width_ + x;
}

bool Grid::isBlack(int x, int y) const {
    try {
        return cells_[getIndex(x, y)];
    } catch (const std::out_of_range&) {
        // If ant goes out of bounds, treat as white
        return false;
    }
}

void Grid::flipColor(int x, int y) {
    try {
        int index = getIndex(x, y);
        cells_[index] = !cells_[index];
    } catch (const std::out_of_range&) {
        // Ignore out of bounds flips
    }
}
