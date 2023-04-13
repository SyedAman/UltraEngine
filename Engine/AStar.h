#pragma once
#include <vector>

// TODO: Fix direct dependency on concrete Pair
#include "Pair.h"

using Coordinate = Pair<int, int>;

class AStar
{
    std::vector<std::vector<int>> FlippedMatrix;
    Coordinate StartingPoint;
    Coordinate DestinationPoint;

public:
    explicit AStar(const std::vector<std::vector<int>>& FlippedMatrix);
    explicit AStar(const std::vector<std::vector<int>>& FlippedMatrix, Coordinate StartingPoint);
    explicit AStar(const std::vector<std::vector<int>>& FlippedMatrix, const Coordinate& StartingPoint, const Coordinate& DestinationPoint);

    std::vector<Coordinate> GetPath();

    std::vector<std::vector<int>> GetMatrix();
    Coordinate GetStartingPoint();
    Coordinate GetDestinationPoint();
    bool IsInBounds(Coordinate Coordinate);
    bool IsAnObstacle(Coordinate RightNeighbor);
    std::vector<Coordinate> GetViableNeighbors(const Coordinate& Node);
    void SetStartingPoint(const Coordinate& Coordinate);
    void SetDestinationPoint(const Coordinate& Coordinate);
};
