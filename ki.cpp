// recursive function to find the sum of depths of all subtree
#include <bits/stdc++.h>
using namespace std;
// calling the dfs function for every node
void dfs(int sv, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[sv] = true;
    for (auto it : adj[sv])
    {
        if (!vis[it])
            dfs(it, adj, vis);
    }
    return;
}
// checking if all the nodes are visited are not
bool allVisited(vector<bool> &vis)
{
    for (int i = 0; i < vis.size(); i++)
    {
        if (!vis[i])
            return false;
    }
    return true;
}
int main()
{
    int v = 5;
    vector<vector<int>> adj(v);

        // graph given in sample case 2
        adj[0]
            .push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(0);

        // array to store the mother vertices
        vector<int>
            motherV;
    for (int i = 0; i < v; i++)
    {
                // intiliaze the visited vector
         // to keep check if the node is visited or not
            vector<bool>
                vis(v, false);
                // calling the dfs function
            dfs(i, adj, vis);
                //checking if all the nodes are visited or not
            if (allVisited(vis)) motherV.push_back(i);
    }
    cout << "Total Number of mother vertices are : " << motherV.size() << endl;

    for (auto it : motherV)
        cout
            << it << " ";
    cout << endl;
}