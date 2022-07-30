// C++ program to Check if a path exists from a given cell of the matrix to any boundary element of the Matrix with addition of elements not exceeding K
#include <bits/stdc++.h>
using namespace std;

// Function to check validity on moving to the next index
bool validity(vector<vector<int>> &board, int i, int j, int K)
{
    if (board[i][j] <= K)
    {
        return true;
    }

    // else
    return false;
}

// Checking if a path exists from the given cell having coordinate (X, Y) of the matrix to any boundary cell with the sum of elements at most K.
bool findWay(vector<vector<int>> &board, int X, int Y, int M, int N, int K)
{

    if (X < 0 || X == M || Y < 0 || Y == N)
    {
        return true;
    }

    if (validity(board, X, Y, K))
    {

        // Storing the current element in a variable
        int board_XY = board[X][Y];

        // Marking the current(present) cell as visited
        board[X][Y] = INT_MAX;

        // Visiting all the adjacent cells and returning true
        if (findWay(board, X + 1, Y, M, N, K - board_XY) || findWay(board, X - 1, Y, M, N, K - board_XY) || findWay(board, X, Y + 1, M, N, K - board_XY) || findWay(board, X, Y - 1, M, N, K - board_XY))
        {
            return true;
        }

        // Marking the cell unvisited if above case does not hold.
        board[X][Y] = board_XY;
    }

    return false;
}

int main()
{
    vector<vector<int>> grid = {
        {2, 3, 4, 5},
        {1, 2, 3, 4},
        {1, 4, 5, 7}};

    int K;
    cin >> K;
    int M = grid.size();
    int N = grid[0].size();
    int X, Y;
    cin >> X >> Y;

    if (findWay(grid, X, Y, M, N, K))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
