// Copyright Syed Aman. All Rights Reserved.

#include "AStar.h"

#include <memory>
#include <set>
#include <stdexcept>

#include "PriorityQueue.h"


AStar::AStar(const std::vector<std::vector<int>>& FlippedMatrix)
{
    this->FlippedMatrix = FlippedMatrix;
}

AStar::AStar(const std::vector<std::vector<int>>& FlippedMatrix, Coordinate StartingPoint)
{
    this->FlippedMatrix = FlippedMatrix;
    SetStartingPoint(StartingPoint);
}

AStar::AStar(const std::vector<std::vector<int>>& FlippedMatrix, const Coordinate& StartingPoint,
    const Coordinate& DestinationPoint)
{
    this->FlippedMatrix = FlippedMatrix;
    SetStartingPoint(StartingPoint);
    SetDestinationPoint(DestinationPoint);
}

std::vector<std::vector<int>> AStar::GetMatrix()
{
    return FlippedMatrix;
}

Coordinate AStar::GetStartingPoint() const
{
    return StartingPoint;
}

Coordinate AStar::GetDestinationPoint() const
{
    return DestinationPoint;
}

bool AStar::IsInBounds(Coordinate Coordinate) const
{
    return Coordinate.Second < FlippedMatrix.size() && Coordinate.Second >= 0 && Coordinate.First < FlippedMatrix[0].size() &&
        Coordinate.First >= 0;
}

bool AStar::IsAnObstacle(const Coordinate RightNeighbor) const
{
    if (!IsInBounds(RightNeighbor))
    {
        throw std::out_of_range("Coordinate is out of bounds");
    }
    return FlippedMatrix[RightNeighbor.Second][RightNeighbor.First] == 1;
}

std::vector<Coordinate> AStar::GetViableNeighbors(const Coordinate& Node) const
{
    std::vector<Coordinate> AvailableNeighbors;

    Coordinate RightNeighbor(Node.First + 1, Node.Second);
    Coordinate DownNeighbor(Node.First, Node.Second + 1);
    Coordinate LeftNeighbor(Node.First - 1, Node.Second);
    Coordinate UpNeighbor(Node.First, Node.Second - 1);
    
    for (const auto& Neighbor : {RightNeighbor, DownNeighbor, LeftNeighbor, UpNeighbor})
    {
        if (IsInBounds(Neighbor) && !IsAnObstacle(Neighbor))
        {
            AvailableNeighbors.push_back(Neighbor);
        }
    }
    
    return AvailableNeighbors;
}

void AStar::SetStartingPoint(const Coordinate& Coordinate)
{
    if (!IsInBounds(Coordinate))
    {
        throw std::invalid_argument("Coordinate is out of bounds");
    }
    if (IsAnObstacle(Coordinate))
    {
        throw std::invalid_argument("Coordinate is an obstacle");
    }
    StartingPoint = Coordinate;
}

void AStar::SetDestinationPoint(const Coordinate& Coordinate)
{
    if (!IsInBounds(Coordinate))
    {
        throw std::invalid_argument("Coordinate is out of bounds");
    }
    if (IsAnObstacle(Coordinate))
    {
        throw std::invalid_argument("Coordinate is an obstacle");
    }
    DestinationPoint = Coordinate;
}

struct Node
{
    Node(const Coordinate& InCoordinate, const int InDistanceFromStart, const int InDistanceToDestination, const int InTotalDistance, std::shared_ptr<Node> parent)
        : Coordinate(InCoordinate), DistanceFromStart(InDistanceFromStart), DistanceToDestination(InDistanceToDestination), TotalDistance(InTotalDistance), Parent(
              std::move(parent)) {}
    
    Coordinate Coordinate;
    int DistanceFromStart;
    int DistanceToDestination;
    int TotalDistance;
    std::shared_ptr<Node> Parent;
};

std::vector<Coordinate> ConstructPath(const std::shared_ptr<Node>& InNode)
{
    std::vector<Coordinate> Path;
    std::shared_ptr<Node> Current = InNode;
    while (Current)
    {
        Path.push_back(Current->Coordinate);
        Current = Current->Parent;
    }
    
    std::reverse(Path.begin(), Path.end());
    return Path;
}

using NodePtr = std::shared_ptr<Node>;

struct NodeComparator
{
    bool operator()(const NodePtr& Left, const NodePtr& Right) const
    {
        return Left->TotalDistance < Right->TotalDistance;
    }
};

std::vector<Coordinate> AStar::GetPath()
{
    if (StartingPoint == DestinationPoint)
    {
        return {StartingPoint};
    }

    std::set<Coordinate> Visited;
    PriorityQueue<NodePtr, DynamicArray<NodePtr>, NodeComparator> PotentialCandidates;
    const NodePtr startingNode = std::make_shared<Node>(StartingPoint, 0, 0, 0, nullptr);
    PotentialCandidates.Push(startingNode);

    while (!PotentialCandidates.Empty())
    {
        const NodePtr currentNode = PotentialCandidates.Top();
        PotentialCandidates.Pop();

        if (currentNode->Coordinate == DestinationPoint)
        {
            return ConstructPath(currentNode);
        }

        if (!Visited.contains(currentNode->Coordinate))
        {
            Visited.insert(currentNode->Coordinate);

            for (std::vector<Coordinate> viableNeighbors = GetViableNeighbors(currentNode->Coordinate); const Coordinate& neighbor : viableNeighbors)
            {
                if (!Visited.contains(neighbor))
                {
                    const int distanceFromStart = currentNode->DistanceFromStart + 1;
                    const int distanceToDestination = std::abs(neighbor.First - DestinationPoint.First) + std::abs(neighbor.Second - DestinationPoint.Second);
                    const int totalDistance = distanceFromStart + distanceToDestination;

                    const NodePtr NewNode = std::make_shared<Node>(Node{neighbor, distanceFromStart, distanceToDestination, totalDistance, currentNode});
                    PotentialCandidates.Push(NewNode);
                }
            }
        }
    }

    return {};
}
