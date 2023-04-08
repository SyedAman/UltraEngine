#include "gtest/gtest.h"
#include "AStar.h"


TEST(TestAStar, InstantiateAStarClassWithA2DMatrix)
{
    // Given a 2D matrix.
    std::vector<std::vector<int>> matrix = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    // When we instantiate the AStar class.
    AStar astar(matrix);

    // Then the matrix is set.
    EXPECT_EQ(astar.GetMatrix(), matrix);
}

TEST(TestAStar, ShouldBeAbleToSetStartingPoint)
{
    // Given a 2D matrix.
    std::vector<std::vector<int>> matrix = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    Coordinate starting_point = {1, 1};
    // When we instantiate the AStar class, we should be able to set the starting point.
    AStar astar(matrix);
    astar.SetStartingPoint(starting_point);

    // Then the starting point is set.
    EXPECT_EQ(astar.GetStartingPoint(), starting_point);
}

TEST(TestAStar, ShouldThrowAnErrorIfSettingStartingPointIsOutOfBounds)
{
    // Given an astar
    std::vector<std::vector<int>> matrix = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    AStar astar(matrix);

    // When we set the starting point to be out of bounds.
    Coordinate starting_point = {100, 100};
    
    // Then it should throw an error
    EXPECT_THROW(astar.SetStartingPoint(starting_point), std::invalid_argument);
}

TEST(TestAStar, ShouldPassStartingPointInConstructorAsCoordinate)
{
    // Given a 2D matrix.
    std::vector<std::vector<int>> Matrix = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    Coordinate StartingPoint = {1, 1};
    // When we instantiate the AStar class, we should be able to pass the starting point as a tuple.
    AStar astar(Matrix, StartingPoint);

    // Then the starting point is set.
    EXPECT_EQ(astar.GetMatrix(), Matrix);
    EXPECT_EQ(astar.GetStartingPoint(), StartingPoint);
}

TEST(TestAStar, ShouldBeAbleToSetDestinationPoint)
{
    // Given a 2D matrix.
    std::vector<std::vector<int>> matrix = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    Coordinate destination_point = {8, 7};
    // When we instantiate the AStar class, we should be able to set the destination point.
    AStar astar(matrix);
    astar.SetDestinationPoint(destination_point);

    // Then the destination point is set.
    EXPECT_EQ(astar.GetDestinationPoint(), destination_point);
}

TEST(TestAStar, ShouldThrowAnErrorIfSettingDestinationPointIsOutOfBounds)
{
    std::vector<std::vector<int>> matrix = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    AStar astar(matrix);

    // When we set the destination point to be out of bounds.
    Coordinate DestinationPoint = {100, 100};
    
    // Then it should throw an error
    EXPECT_THROW(astar.SetDestinationPoint(DestinationPoint), std::invalid_argument);
}

TEST(TestAStar, ShouldPassDestinationPointInConstructorAsCoordinate)
{
    // Given a 2D matrix.
    std::vector<std::vector<int>> Matrix = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    // When we instantiate the AStar class, we should be able to pass the starting point as a tuple.
    Coordinate StartingPoint = {1, 1};
    Coordinate DestinationPoint = {8, 7};
    AStar astar(Matrix, StartingPoint, DestinationPoint);

    // Then the matrix, starting point, and destination is set.
    EXPECT_EQ(astar.GetMatrix(), Matrix);
    EXPECT_EQ(astar.GetStartingPoint(), StartingPoint);
    EXPECT_EQ(astar.GetDestinationPoint(), DestinationPoint);
}

TEST(TestAStar, ShouldGetHorizontalAndVerticalNeighborsThatAreNotObstacles)
{
    // Given an AStar with a matrix, starting point, and destination
    std::vector<std::vector<int>> Matrix = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    Coordinate StartingPoint = {1, 1};
    Coordinate DestinationPoint = {8, 7};
    AStar astar(Matrix, StartingPoint, DestinationPoint);

    // When we get the neighbors of the starting point.
    std::vector<Coordinate> Neighbors = astar.GetViableNeighbors(StartingPoint);

    // Then we should get the neighbors, no need for the order to be the same.
    bool Combo1 = (Neighbors == std::vector<Coordinate>{{1, 2}, {2, 1}});
    bool Combo2 = (Neighbors == std::vector<Coordinate>{{2, 1}, {1, 2}});
    EXPECT_TRUE(Combo1 || Combo2);
    
    // When we check the neighbors of (1, 7)
    std::vector<Coordinate> NeighborsOf1X7Y = astar.GetViableNeighbors({1, 7});
    
    // Then we should only have (1, 6) as a neighbor, since it is the only neighbor that is not an obstacle
    std::vector<Coordinate> Expected = {{1, 6}};
    EXPECT_EQ(NeighborsOf1X7Y, Expected);
}

TEST(TestAStar, ShouldThrowAnErrorIfStartingPointIsOutOfBounds)
{
    // Given an AStar with a matrix, starting point, and destination
    std::vector<std::vector<int>> Matrix = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    Coordinate StartingPoint = {100, 100};
    Coordinate DestinationPoint = {8, 8};

    EXPECT_THROW(AStar astar(Matrix, StartingPoint);, std::invalid_argument);
    EXPECT_THROW(AStar astar(Matrix, StartingPoint, DestinationPoint);, std::invalid_argument);
}

TEST(TestAStar, ShouldThrowAnErrorIfDestinationPointIsOutOfBounds)
{
    // Given an AStar with a matrix, starting point, and destination
    std::vector<std::vector<int>> Matrix = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    Coordinate StartingPoint = {1, 1};
    Coordinate DestinationPoint = {800, 800};

    EXPECT_THROW(AStar astar(Matrix, StartingPoint, DestinationPoint);, std::invalid_argument);
}

TEST(TestAStar, ShouldThrowErrorIfStartingPointOrDestinationPointIsAnObstacle)
{
    // Given an AStar with a matrix, starting point, and destination
    std::vector<std::vector<int>> Matrix = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    EXPECT_THROW(AStar astar(Matrix, {0,0}, {8,8});, std::invalid_argument);
    EXPECT_THROW(AStar astar(Matrix, {1,1}, {9,8});, std::invalid_argument);
}

TEST(TestAStar, ShouldThrowErrorIfPassingAnOutOfBoundsCoordinateWhenCallingIsAnObstacle)
{
    // Given an AStar with a matrix, starting point, and destination
    std::vector<std::vector<int>> Matrix = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    AStar astar(Matrix, {1,1}, {7,7});

    // If I call IsAnObstacle with an out of bounds point then it should throw an error
    EXPECT_THROW(astar.IsAnObstacle({-1, 0});, std::out_of_range);
}

TEST(TestAStar, CallingGetWhenStartingPointAndDestinationPointIsTheSameShouldReturnAnArrayWithThePoint)
{
    // Given an AStar with a matrix with the starting point and destination point being the same
    std::vector<std::vector<int>> Matrix = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    Coordinate StartingPoint = {1, 1};
    Coordinate DestinationPoint = StartingPoint;
    AStar astar(Matrix, StartingPoint, DestinationPoint);

    // When I call GetPath
    std::vector<std::pair<int,int>> path = astar.GetPath();

    // Then the path should be an array with the starting point
    EXPECT_EQ(path.size(), 1);
    EXPECT_EQ(path[0], StartingPoint);

    DestinationPoint = {7, 7};
    astar.SetStartingPoint(DestinationPoint);
    astar.SetDestinationPoint(DestinationPoint);
    EXPECT_EQ(astar.GetPath().size(), 1);
    EXPECT_EQ(astar.GetPath()[0], DestinationPoint);
}

TEST(TestAStar, CallingGetPathWhenStartingPointIsCompletelyBlockedOffReturnsAnEmptyArray)
{
    // Given an AStar with a matrix with the starting point being completely blocked off
    std::vector<std::vector<int>> Matrix = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    Coordinate StartingPoint = {1, 1};
    Coordinate DestinationPoint = {1, 3};
    AStar astar(Matrix, StartingPoint, DestinationPoint);

    // When I call GetPath
    std::vector<std::pair<int,int>> path = astar.GetPath();

    // Then the path should be an empty array
    EXPECT_EQ(path.size(), 0);

    // But when I set the destination point to the same point as the starting point
    astar.SetDestinationPoint(StartingPoint);

    // Then the path should be an array with the starting point
    path = astar.GetPath();
    EXPECT_EQ(path.size(), 1);
    EXPECT_EQ(path[0], StartingPoint);
}

TEST(TestAStar, CallingGetPathWhenDestinationIsAdjacentToTheStartingPointShouldReturnThePathWithBothPoints)
{
    // Given an AStar with a matrix with the destination point being adjacent to the starting point
    std::vector<std::vector<int>> Matrix = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    Coordinate StartingPoint = {1, 1};
    Coordinate DestinationPoint = {1, 2};
    AStar astar(Matrix, StartingPoint, DestinationPoint);

    // When I call GetPath
    std::vector<std::pair<int,int>> path = astar.GetPath();

    // Then the path should be an array with the starting point and destination point
    EXPECT_EQ(path.size(), 2);
    EXPECT_EQ(path[0], StartingPoint);
    EXPECT_EQ(path[1], DestinationPoint);

    // When I update the destination point to be adjacent to the starting point on a different point
    DestinationPoint = {2, 1};
    astar.SetDestinationPoint(DestinationPoint);

    // Then the path should be an array with the starting point and destination point
    path = astar.GetPath();
    EXPECT_EQ(path.size(), 2);
    EXPECT_EQ(path[0], StartingPoint);
}

TEST(TestAStar, CallingGetPathWhenTheMatrixIsANarrowCorridorShouldGiveMeTheFullPath)
{
    // Given an AStar with a corridor matrix and points on opposite sides
    std::vector<std::vector<int>> Matrix = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    Coordinate StartingPoint = {1, 1};
    Coordinate DestinationPoint = {8, 1};
    AStar astar(Matrix, StartingPoint, DestinationPoint);

    // When I call GetPath
    std::vector<std::pair<int,int>> path = astar.GetPath();

    // Then the path should be an array with the starting point, and all the points to and including destination point
    std::vector<std::pair<int,int>> expectedPath = {
        {1, 1},
        {2, 1},
        {3, 1},
        {4, 1},
        {5, 1},
        {6, 1},
        {7, 1},
        {8, 1}
    };
    EXPECT_EQ(path, expectedPath);

    // Given an AStar with a 1 row corridor matrix
    Matrix = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    AStar astar2(Matrix, {0,0}, {9,0});

    // When I call GetPath
    path = astar2.GetPath();

    // Then the path should be an array with the starting point, and all the points to and including destination point
    expectedPath = {
        {0, 0},
        {1, 0},
        {2, 0},
        {3, 0},
        {4, 0},
        {5, 0},
        {6, 0},
        {7, 0},
        {8, 0},
        {9, 0}
    };

    EXPECT_EQ(path, expectedPath);
}

TEST(TestAStar, CallPathShouldGiveMeTheFullPath)
{
    std::vector<std::vector<int>> Matrix = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1, 1}
    };
    AStar astar(Matrix, {1, 1}, {8, 3});

    std::vector<std::pair<int,int>> path = astar.GetPath();

    std::vector<std::pair<int,int>> Expected = {
        {1,1},
        {1,2},
        {1,3},
        {1,4},
        {2,4},
        {3,4},
        {3,3},
        {4,3},
        {5,3},
        {5,4},
        {6,4},
        {7,4},
        {7,3},
        {8,3}
    };
    EXPECT_EQ(path, Expected);
}

TEST(TestAStar, ThisTimeGoingTheOtherDirection)
{
    std::vector<std::vector<int>> Matrix = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1, 1}
    };
    AStar astar(Matrix, {1, 1}, {8, 3});

    std::vector<std::pair<int,int>> path = astar.GetPath();

    std::vector<std::pair<int,int>> Expected = {
        {1,1},
        {2,1},
        {3,1},
        {4,1},
        {5,1},
        {6,1},
        {6,2},
        {7,2},
        {8,2},
        {8,3}
    };
    EXPECT_EQ(path, Expected);
}


TEST(TestAStar, ThisTimeBigMap)
{
    std::vector<std::vector<int>> Matrix = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    AStar astar(Matrix, {1, 1}, {13,8});

    std::vector<std::pair<int,int>> path = astar.GetPath();

    std::vector<std::pair<int,int>> Expected = {
        {1,1},
        {2,1},
        {3,1},
        {4,1},
        {5,1},
        {6,1},
        {6,2},
        {7,2},
        {8,2},
        {9,2},
        {10,2},
        {11,2},
        {12,2},
        {12,3},
        {13,3},
        {13,4},
        {13,5},
        {13,6},
        {12,6},
        {12,7},
        {12,8},
        {13,8}
    };
    EXPECT_EQ(path, Expected);
}