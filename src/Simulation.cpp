#include "Simulation.hpp"
#include <fstream>
#include <iostream>

Simulation::Simulation(int grid_width, int grid_height, std::unique_ptr<IAgent> agent) {
    grid_ = std::make_unique<Grid>(grid_width, grid_height);
    ant_ = std::move(agent);
}

void Simulation::run(int steps, const std::string& output_csv_path) {
    std::ofstream file(output_csv_path);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << output_csv_path << " for writing.\n";
        return;
    }

    // Write CSV Header
    file << "step,x,y,new_color,ant_dx,ant_dy\n";

    for (int i = 0; i < steps; ++i) {
        int cx = ant_->getX();
        int cy = ant_->getY();
        bool new_color = !grid_->isBlack(cx, cy);

        // Move forward and interact with the grid
        ant_->step(*grid_);

        // Record the action before moving (for frontend rendering)
        file << i << "," << cx << "," << cy << "," 
             << (new_color ? 1 : 0) << "," 
             << ant_->getDx() << "," << ant_->getDy() << "\n";

        // Stop if ant leaves the grid boundaries
        if (ant_->getX() < 0 || ant_->getX() >= grid_->getWidth() ||
            ant_->getY() < 0 || ant_->getY() >= grid_->getHeight()) {
            std::cout << "Ant left the grid at step " << i << ".\n";
            break;
        }
    }

    file.close();
    std::cout << "Simulation finished. Data written to " << output_csv_path << "\n";
    
    std::cout << "Final State: " << *grid_ << " | " << *ant_ << "\n";
}
