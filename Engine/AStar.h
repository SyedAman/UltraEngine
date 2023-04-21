// Copyright Syed Aman. All Rights Reserved.#pragma once
#include <vector>

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
    Coordinate GetStartingPoint() const;
    Coordinate GetDestinationPoint() const;
    bool IsInBounds(Coordinate Coordinate) const;
    bool IsAnObstacle(Coordinate RightNeighbor) const;
    std::vector<Coordinate> GetViableNeighbors(const Coordinate& Node) const;
    void SetStartingPoint(const Coordinate& Coordinate);
    void SetDestinationPoint(const Coordinate& Coordinate);
};
