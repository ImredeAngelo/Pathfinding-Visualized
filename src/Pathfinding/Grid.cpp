#include <iostream>
#include "Grid.h"

Grid::Grid(unsigned int size)
{
    nodes = Nodes();
    nodes.reserve(size * size);
    for(auto i = 0; i < size; i++)
    {
        for(auto j = 0; j < size; j++) {
            nodes.emplace_back(Node(i, j)); //, (i + j) % 2));
        }
    }
}