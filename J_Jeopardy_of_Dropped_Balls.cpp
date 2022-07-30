#include <bits/stdc++.h>
using namespace std;

// Function to get the result
int getResult(int x1, int y1, int x2, int y2, int count)
{
    // Meeting the destination
    if (x1 == x2 || y1 == y2)
    {
        count++;
        return count;
    }

    // All unique paths using Right Movement
    count = getResult(x1, y1 + 1, x2, y2, count);

    // All unique paths using Down Movement
    count = getResult(x1 + 1, y1, x2, y2, count);

    return count;
}

int main()
{
    vector<vector<int>> input = {{1, 2, 3},
                                 {4, 5, 6},
                                 {7, 8, 9}};
    int x1 = 0, y1 = 0;
    int x2 = 2, y2 = 2;
    cout << "Total Number of Unique paths are:- ";
    cout << getResult(x1, y1, x2, y2, 0) << endl;
    return 0;
}
