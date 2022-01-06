#include "AStar.h"
#include "Math/Math.h"

#define HCOST_D  10
#define HCOST_DD 14

AStar::Node *AStar::GetPath(Node *start, Node *end, Heuristic h) {
    return nullptr;
}

float AStar::Heuristics::Manhattan(const Node &current, const Node &goal) {
    double dx = Math::Abs(goal.x - current.x);
    double dy = Math::Abs(goal.y - current.y);
    return HCOST_D * (dx + dy);
}

float AStar::Heuristics::Diagonal(const Node &current, const Node &goal) {
    double dx = Math::Abs(goal.x - current.x);
    double dy = Math::Abs(goal.y - current.y);
    return HCOST_D * (dx + dy) + (HCOST_DD - 2 * HCOST_D) * Math::Min(dx, dy);
}

float AStar::Heuristics::Euclidean(const Node &current, const Node &goal) {
    float dx = Math::Abs(goal.x - current.x);
    float dy = Math::Abs(goal.y - current.y);
    float dSqr = dx*dx + dy*dy;
    return HCOST_D * Math::InvSqr(dSqr) * dSqr;
}