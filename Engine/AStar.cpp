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

Coordinate AStar::GetStartingPoint()
{
    return StartingPoint;
}

Coordinate AStar::GetDestinationPoint()
{
    return DestinationPoint;
}

bool AStar::IsInBounds(Coordinate Coordinate)
{
    return Coordinate.Second < FlippedMatrix.size() && Coordinate.Second >= 0 && Coordinate.First < FlippedMatrix[0].size() &&
        Coordinate.First >= 0;
}

bool AStar::IsAnObstacle(Coordinate RightNeighbor)
{
    if (!IsInBounds(RightNeighbor))
    {
        throw std::out_of_range("Coordinate is out of bounds");
    }
    return FlippedMatrix[RightNeighbor.Second][RightNeighbor.First] == 1;
}

std::vector<Coordinate> AStar::GetViableNeighbors(const Coordinate& Node)
{
    std::vector<Coordinate> AvailableNeighbors;

    Coordinate RightNeighbor(Node.First + 1, Node.Second);
    Coordinate DownNeighbor(Node.First, Node.Second + 1);
    Coordinate LeftNeighbor(Node.First - 1, Node.Second);
    Coordinate UpNeighbor(Node.First, Node.Second - 1);
    
    // Get rid of all neighbors that are out of bounds
    if (IsInBounds(RightNeighbor) && !IsAnObstacle(RightNeighbor))
    {
        AvailableNeighbors.push_back(RightNeighbor);
    }

    if (IsInBounds(DownNeighbor) && !IsAnObstacle(DownNeighbor))
    {
        AvailableNeighbors.push_back(DownNeighbor);
    }

    if (IsInBounds(LeftNeighbor) && !IsAnObstacle(LeftNeighbor))
    {
        AvailableNeighbors.push_back(LeftNeighbor);
    }

    if (IsInBounds(UpNeighbor) && !IsAnObstacle(UpNeighbor))
    {
        AvailableNeighbors.push_back(UpNeighbor);
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
    Node(const Coordinate& coordinate, int distanceFromStart, int distanceToDestination, int totalDistance, std::shared_ptr<Node> parent)
        : Coordinate(coordinate), DistanceFromStart(distanceFromStart), DistanceToDestination(distanceToDestination), TotalDistance(totalDistance), Parent(parent) {}
    
    Coordinate Coordinate;
    int DistanceFromStart;
    int DistanceToDestination;
    int TotalDistance;
    std::shared_ptr<Node> Parent;
};

std::vector<Coordinate> ConstructPath(const std::shared_ptr<Node>& node)
{
    std::vector<Coordinate> path;
    std::shared_ptr<Node> current = node;
    while (current)
    {
        path.push_back(current->Coordinate);
        current = current->Parent;
    }
    
    std::reverse(path.begin(), path.end());
    return path;
}

using NodePtr = std::shared_ptr<Node>;

struct NodeComparator
{
    bool operator()(const NodePtr& left, const NodePtr& right) const
    {
        return left->TotalDistance < right->TotalDistance;
    }
};

std::vector<Coordinate> AStar::GetPath()
{
    if (StartingPoint == DestinationPoint)
    {
        return {StartingPoint};
    }

    std::set<Coordinate> Visited;
    PriorityQueue<NodePtr, std::vector<NodePtr>, NodeComparator> PotentialCandidates;
    const NodePtr startingNode = std::make_shared<Node>(StartingPoint, 0, 0, 0, nullptr);
    PotentialCandidates.push(startingNode);

    while (!PotentialCandidates.empty())
    {
        const NodePtr currentNode = PotentialCandidates.top();
        PotentialCandidates.pop();

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

                    NodePtr newNode = std::make_shared<Node>(Node{neighbor, distanceFromStart, distanceToDestination, totalDistance, currentNode});
                    PotentialCandidates.push(newNode);
                }
            }
        }
    }

    return {};
}
