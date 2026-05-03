#include "Simulation.hpp"
#include "Ant.hpp"
#include <iostream>

int main() {
    std::cout << "Starting Langton's Ant Simulation...\n";
    
    // Grid size 200x200
    int width = 200;
    int height = 200;
    
    // 15,000 steps to clearly see the highway formation
    int steps = 15000; 

    // Center the ant in the grid and inject it into the simulation
    auto my_ant = std::make_unique<Ant>(width / 2, height / 2);
    Simulation sim(width, height, std::move(my_ant));
    
    // Run the simulation and write the results to a CSV file
    sim.run(steps, "docs/data.csv");

    return 0;
}
