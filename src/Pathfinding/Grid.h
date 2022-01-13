#pragma once

#include <vector>
#include "Node.h"

typedef std::vector<Node> Nodes;

// TODO: make templated
class Grid
{
public:
    Grid(unsigned int size);

    operator Nodes&() { return nodes; };

private:
    // TODO: Separate grids for each algortihm to run in parallell
    Nodes nodes;
};


