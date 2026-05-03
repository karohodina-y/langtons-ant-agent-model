#pragma once
#include <iostream>

class Grid;

/**
 * @brief Abstract base class representing a generic agent in the simulation.
 */
class IAgent {
public:
    virtual ~IAgent() = default;

    /**
     * @brief Performs a single movement step, interacting with the grid.
     */
    virtual void step(Grid& grid) = 0;

    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual int getDx() const = 0;
    virtual int getDy() const = 0;

    virtual void print(std::ostream& os) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const IAgent& agent) {
        agent.print(os);
        return os;
    }
};
