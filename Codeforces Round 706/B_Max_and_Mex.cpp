#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef long double lld;
typedef priority_queue <lli , vector<lli>, greater<lli> > min_heap;
typedef priority_queue <lli> max_heap;

#define FOR(i,l,u) for(lli i=l;i<=u;i++)
//Graphs
void add_edge(vector<vector<lli>> adj[],lli source, lli destination,lli weight,string name)
{
    adj[source].push_back({destination,weight});
    return;
}
void DFS_lite(vector<vector<lli>> adj[],lli source,lli visited[],lli arrival[],lli departure[],lli &timer)
{
    visited[source]=1;
    arrival[source]=timer++;
    lli size = adj[source].size();
    for(lli i=0;i<size;i++)
    {
        if(visited[adj[source][i][0]]==0)
        {
            DFS_lite(adj,adj[source][i][0],visited,arrival,departure,timer);
            adj[source].erase(adj[source].begin()+i);
        }
    }
    departure[source]=timer++;
    return;
}
void DFS(vector<vector<lli>> adj[],lli N,lli arrival[],lli departure[],lli &timer)
{
    lli visited[N+1] = {0};
    for(lli i=1;i<N+1;i++)
    {
        if(visited[i]==0)
        {
            DFS_lite(adj,i,visited,arrival,departure,timer);
        }
    }
    return;
}
lli extended_gcd(lli a ,lli b,lli &x,lli &y){
    if(a==0){
        x=0;y=1;return b;}
    lli x1,y1,ans = extended_gcd(b%a,a,x1,y1);
    x = y1-(b/a)*x1;y = x1;
    return ans;
}
lli power_mod(lli a,lli b,lli m)
{
    lli ans =1;
    while(b!=0)
    {
        if(b%2==1)
           ans=(ans*a)%m;
        a=a*a;
        a%=m;
        b/=2;
    }
    return ans;
}
lli mod_inverse(lli a,lli m)
{
    return power_mod(a,m-2,m);
}
void mod_inverse_array(lli inv[],lli u,lli m)
{
    inv[1]=1;
    FOR(i,2,u){
        inv[i]=((-(m/i)*inv[m%i]%m)+m)%m;
    }
}
void prime_factorization(lli n,unordered_map<lli,lli> &m)
{
     lli i;
     for(i=2;i*i<=n;i++)
     {
         while(n%i==0)
         {
             m[i]++;
             n=n/i;
         }
     }
     if(n!=1)
     m[n]++;
}
void linear_sieve(vector<lli> &pr,int lp[],int N)
{
    for (int i=2; i<=N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back (i);
    }
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
        lp[i * pr[j]] = pr[j];
    }
}
void solve()
{
    lli t;cin>>t;
    while(t--)
    {
        lli n,k;cin>>n>>k;
        unordered_map<lli,lli> S;
        vector<lli> mex;
        lli a =0;
        lli b =0;
        lli c=0;
        FOR(i,0,n-1)
        {
            lli d;cin>>d;
            if(S.find(d)==S.end())
            {
                c++;
                S[d]=1;
            }
            mex.push_back(d);
            b = max(b,d);
        }
        sort(mex.begin(),mex.end());
        bool flag = false;
        FOR(i,0,n-2)
        {
            if(mex[0]>0)
            {
                a=0;
                flag = true;
                break;
            }
            if(mex[i+1]>mex[i]+1)
            {
                a=mex[i]+1;
                flag = true;
                break;
            }
        }
        if(!flag)
            a=b+1;
            cout<<a<<' '<<mex[0];
        //cout<<b<<" "<<a<<" "<<c<<"\n";
        if(b==a-1)
          cout<<c+k<<"\n";
        else if((a+b)%2==0)
        {
            if(S.find((a+b)/2)==S.end())
               cout<<c+min(lli(1),k)<<"\n";
            else
               cout<<c<<"\n";
        }
        else
        {
            if(S.find(((a+b)/2)+1)==S.end())
               cout<<c+min(lli(1),k)<<"\n";
            else
               cout<<c<<"\n";
        }
    }
}
int main()
{
    solve();
}