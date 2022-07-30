// C++ code for Water Connection Problem
#include <bits/stdc++.h>
using namespace std;

int ans;
void printSolution(vector<int> &st, vector<int> &en, vector<int> &dm)
{
    cout << st.size() << endl;
    for (int j = 0; j < st.size(); ++j)
        cout << st[j] << " " << en[j]
             << " " << dm[j] << endl;
}
int dfs(int w, vector<int> &diameter, vector<int> &start)
{
    if (start[w] == 0)
        return w;
    if (diameter[w] < ans)
        ans = diameter[w];
    return dfs(start[w], diameter, start);
}

// function for water connection problem
void water_connection(int arr[][3], int n, int pipes)
{
    // to store the starting vertex of the pipe
    vector<int> start(1100, 0);
    // to store the ending vertex of the pipe
    vector<int> ed(1100, 0);
    // to store the diameter of pipe
    vector<int> diameter(1100);
    int i = 0;

    for (i = 0; i < pipes; i++)
    {
        start[arr[i][0]] = arr[i][1];
        diameter[arr[i][0]] = arr[i][2];
        ed[arr[i][1]] = arr[i][0];
    }
    // st---> to store the starting vertex
    // en--> to store the ending vertex
    //  dm-->to store the minimum diameter of the pipe
    vector<int> st, en, dm;
    for (int j = 1; j <= n; ++j)

        // If there is a pipe that has no ending vertex but has
        // starting vertex then we will start DFS with this vertex
        if (ed[j] == 0)
        {
            if (start[j])
            {
                ans = INT_MAX;
                int w = dfs(j, diameter, start);

                // we will store the details of components in these final arrays
                st.push_back(j);
                en.push_back(w);
                dm.push_back(ans);
            }
        }
    printSolution(st, en, dm);
}

// driver function
int main()
{
    // to store the no of houses and pipes
    int n = 9, pipes = 6;
    int arr[][3] = {{2, 3, 45},
                    {4, 5, 10},
                    {5, 8, 22},
                    {1, 2, 33},
                    {7, 6, 17},
                    {3, 7, 66}};

    water_connection(arr, n, pipes);
    return 0;
}