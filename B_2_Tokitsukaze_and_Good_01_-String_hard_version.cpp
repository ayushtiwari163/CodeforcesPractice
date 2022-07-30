#include <bits/stdc++.h>
using namespace std;
int bfs(vector<vector<int>> &adj, int curr, vector<int> &par, int n)
{

   vector<int> dis(n + 1, -1);
   dis[curr] = 0;
   queue<int> q;
   q.push(curr);
   par[curr] = curr;
   while (q.empty() == false)
   {
      int x = q.front();
      q.pop();
      for (auto nb : adj[x])
      {
         if (dis[nb] == -1)
         {
            dis[nb] = dis[x] + 1;
            q.push(nb);
            par[nb] = x;
         }
      }
   }
   int end_point = 1;
   int val = 0;
   for (int i = 1; i <= n; i++)
   {
      if (dis[i] >= val)
      {
         val = dis[i];
         end_point = i;
      }
   }
   return end_point;
}
int bfs1(vector<vector<int>> &adj, int curr, int n, int xx)
{

   queue<int> q;
   q.push(curr);
   int count = 1;
   vector<int> vis(n + 1, 0);
   vis[curr] = 1;
   vis[xx] = 1;
   while (q.empty() == false)
   {
      int x = q.front();
      count++;
      q.pop();

      for (auto nb : adj[x])
      {
         if (vis[nb] == 0)
         {
            q.push(nb);
            vis[nb] = 1;
         }
      }
   }
   return count - 1;
}

int solve(vector<vector<int>> &A)
{
   int mod = 1000000007;
   int n = (int)A.size() + 1;
   vector<vector<int>> adj(n + 1);
   for (int i = 0; i < n - 1; i++)
   {
      adj[A[i][0]].push_back(A[i][1]);
      adj[A[i][1]].push_back(A[i][0]);
   }
   vector<int> par(n + 1, 0);
   int point1 = bfs(adj, 1, par, n);
   par.assign(n + 1, 0);
   int point2 = bfs(adj, point1, par, n);
   vector<int> path;
   set<int> s;
   int x = point2;
   while (par[x] != x)
   {
      path.push_back(x);
      s.insert(x);
      x = par[x];
   }
   s.insert(point1);
   path.push_back(point1);
   int ans = 0;
   for (auto nb : path)
   {
      // cout << nb << ' ';
      for (auto x : adj[nb])
      {
         if (s.count(x))
            continue;
         int node = bfs1(adj, x, n, nb);
         cout << nb << ' ' << x << ' ' << node << endl;
         int z = ((node % mod) * (node - 1) % mod) % mod;
         z = z / 2;
         ans = (ans % mod + z % mod) % mod;
      }
      // cout << endl;
   }
   cout << endl;
   return ans;
}
int main()
{
   int n;
   cin >> n;
   vector<vector<int>> A(n - 1, vector<int>(2));
   for (int i = 0; i < n - 1; i++)
   {
      cin >> A[i][0] >> A[i][1];
   }
   cout << solve(A);
}
