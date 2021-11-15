#include <iostream>
#include "Pathfinding/AStar.h"


int main() {
    using AStar::Node;

    Node* path = AStar::GetPath(nullptr, nullptr, AStar::Heuristics::Diagonal);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
