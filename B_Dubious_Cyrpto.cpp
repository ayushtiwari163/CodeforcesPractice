#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void dfs(ll curr, ll par, vector<vector<pair<ll, ll>>> &adj, vector<ll> &dis)
{
    dis[curr]++;
    // cout << curr << ' ';
    for (auto nb : adj[curr])
    {
        ll u = nb.first;
        if (par == u)
            continue;

        dfs(u, curr, adj, dis);
        dis[curr] += dis[u];
    }
}
void solve()
{
    ll n, C, src;
    cin >> n >> C >> src;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    map<pair<ll, ll>, ll> m;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        m[{min(u, v), max(u, v)}] = w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<ll> w(n + 1, 0), dis(n + 1, 0);
    dfs(src, 0, adj, dis);

    queue<ll> q;
    q.push(src);
    w[src] = 0;
    vector<ll> vis(n + 1, 0);
    vis[src] = 1;
    while (!q.empty())
    {
        ll curr = q.front();
        q.pop();
        for (auto nb : adj[curr])
        {
            ll u = nb.first;
            ll wt = nb.second;
            if (vis[u])
                continue;
            ll x = m[{min(curr, u), max(curr, u)}];
            m[{min(curr, u), max(curr, u)}] = x * dis[u];
            w[u] = w[curr] + wt;
            q.push(u);
            vis[u] = 1;
        }
    }
    ll ans = 0;
    vector<ll> p;
    for (ll i = 1; i <= n; i++)
        ans += w[i];
    for (auto nb : m)
        p.push_back(nb.second);
    sort(p.begin(), p.end(), greater<ll>());
    ll i = 0;
    while (C-- && i < p.size())
    {
        ans -= p[i];
        i++;
    }
    cout << ans << endl;
}
int main()
{
    // write your code here
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}