#pragma once
#include "Grid.hpp"
#include "IAgent.hpp"
#include <memory>
#include <string>

/**
 * @brief Manages the interaction between the Grid and the Ant.
 * Handles data serialization to CSV to decouple compute from rendering.
 */
class Simulation {
private:
    std::unique_ptr<Grid> grid_;
    std::unique_ptr<IAgent> ant_;

public:
    Simulation(int grid_width, int grid_height, std::unique_ptr<IAgent> agent);

    /**
     * @brief Runs the simulation for a specified number of steps and outputs to CSV.
     */
    void run(int steps, const std::string& output_csv_path);
};
