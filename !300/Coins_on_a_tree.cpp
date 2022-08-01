#include <iostream>
using namespace std;
#include <string>
#include <queue>
#include <vector>
#include <array>
#include <limits.h>
typedef long long int ll;
void add_edge(vector<ll> adj[],ll source,ll destination)
{
    adj[source].push_back(destination);
    adj[destination].push_back(source);
    return;
}
void DFS(ll vertex, vector<ll> adj[], vector<bool> &visited,ll &length,ll coins[],ll level)
{
    visited[vertex] = true;
    for (auto i : adj[vertex])
    {
        
        if (!visited[i])
        {
            length+=(coins[i]*level);
            DFS(i, adj, visited,length,coins,level+1);
        }
    }
}
int main()
{
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++)
    {
        ll n;cin>>n;
        vector<ll> adj[n+1];
        ll lengths[n+1]={0};
        ll coins[n+1];
        for(ll i=1;i<=n;i++)
            cin>>coins[i];
        for(ll j=0;j<n-1;j++)
        {
            ll source,destination;
            cin>>source>>destination;
            add_edge(adj,source,destination);
        }
        for(ll p=1;p<=n;p++)
        {
            vector<bool> visited;
            for(ll r=0;r<=n;r++)
            {
                visited.push_back(false);
            }
            DFS(p,adj,visited,lengths[p],coins,1);
        }
        for(ll i=1;i<=n;i++)
           cout<<lengths[i]<<" ";
        cout<<"\n";
    }
}
