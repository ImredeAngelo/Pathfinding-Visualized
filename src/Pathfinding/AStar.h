#pragma once

namespace AStar {
    struct Node {
        float x, y;
    };

    typedef double (*Heuristic)(const Node &current, const Node &goal);

    Node *GetPath(const Node& grid, const Node &start, const Node &end, Heuristic h);

    /// In a real project one of these would be chosen and written inline in the algorithm.
    /// Heuristics explained at http://theory.stanford.edu/~amitp/GameProgramming/Heuristics.html
    namespace Heuristics {
        float Diagonal(const Node&, const Node&);
        float Manhattan(const Node&, const Node&);
        float Euclidean(const Node&, const Node&);
    }
}


