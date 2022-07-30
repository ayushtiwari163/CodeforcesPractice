// これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました
//ジャイシュリーラム
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#include <cmath>
#include <regex>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ba back
#define ppb pop_back
#define pqb   priority_queue<long long int>
#define eb emplace_back
#define eps 1e-6
#define vll vector<long long int>
#define pqs   priority_queue<int,vll,greater<long long int> >
#define sz(x) (int((x.size())))
#define all(x) (x).begin(),(x).end()
#define FAST ios_base :: sync_with_stdio (false); cin.tie (NULL)
using namespace std;
typedef long long int ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
ll ivalue(string s)  {  ll x=0;  stringstream obj(s);  obj >> x;  return x;  } 
const ll M = 1e9 + 7;
const ll N = 1e5 + 5;
const ll inf = 2e18;
ll mod(ll x){   return (x%M);}
ll mod_minus(ll a, ll b){ ll ans= (mod(a)-mod(b)); if(ans<0) ans=mod(ans+M); return ans;}
ll mod_mul(ll a,ll b){  return mod(mod(a)*mod(b));}
ll mod_add(ll a,ll b){ return mod(mod(a)+mod(b));}
ll power(ll a,ll n){  if(n==0) return 1;  else if(n==1) return a;  ll R=power(a,n/2)%M;  if(n%2==0) {  return mod(mod_mul(R,R)); }   else { return mod(mod_mul(mod_mul(R,a),mod(R)));  }}
ll mod_div(ll a,ll b){// only if M is prime
ll ans=mod(a);
ll b1=power(b,M-2);
 ans= mod(mod_mul(ans,b1));
 return ans;
}
ll mod_inv(ll n){  return power(n,M-2);}
ll fact_mod(ll n){
vll fact(n+1);
fact[0]=1;
for(ll i=1;i<n+1;i++){
 fact[i]=mod_mul(fact[i-1],i);
}
return fact[n];
}
ll nCr_mod(ll n,  ll r)
{
if (r == 0 || n==0)
return 1;
ll fac[n + 1];
fac[0] = 1;
for (ll i = 1; i <= n; i++)
fac[i] = (fac[i - 1] * i) % M;
return (fac[n] * mod_inv(fac[r]) % M * mod_inv(fac[n - r]) % M) % M;
}
ll upper_fraction(ll a, ll b)
{
if(a%b==0)
return a/b;
else
return (a/b)+1;
}
bool isInt( double d )
{
double dummy;
return modf( d, &dummy ) == 0.0;
}
 bool final_check=true;  
 ll ans=0; 
 void dfs(vector<vector<pair<ll,ll>>> &adj,ll curr,vll &vis,ll imposter)
 {
     vis[curr]=imposter;
     if(imposter==1) ans++;
     for(auto nb : adj[curr])
     {
         ll u=nb.fi;
         //cout<<u<<' '<<curr<<' '<<endl;
         ll wt=nb.se;
         ll req_post;
        if(imposter==1 && wt==1)
        req_post=0;
        else if(imposter==1 && wt==2)
        req_post=1;
        else if(imposter==1 && wt==-1)
        req_post=0;
        else if(imposter==1 && wt==-2)
        req_post=1;
         else if(imposter==0 && wt==1)
        req_post=1;
        else if(imposter==0 && wt==2)
        req_post=0;
        else if(imposter==0 && wt==-1)
        req_post=1;
        else if(imposter==0 && wt==-2)
        req_post=0;
        if(vis[u]==-1)
        {
            dfs(adj,u,vis,req_post);
        }
        else if(vis[u]!=-1){
            if(vis[u]!=req_post)
        final_check=false;
           // cout<<u<<' '<<curr<<' '<<final_check<<endl;
        }
    
     }
 }   
void solve()
{
   ll n,m;
   cin>>n>>m;
   vector<vector<pair<ll,ll>>> adj(n+1);
   ll i,j;
   while(m--)
   {
       ll u,v;
       cin>>u>>v;
       string s;
       cin>>s;
       if(s=="imposter")
       {
           adj[u].pb({v,1});
           adj[v].pb({u,-1});
       }
       else 
       {
          adj[u].pb({v,2});
          adj[v].pb({u,-2});
       }
   }
vll vis1(n+1,-1),vis2(n+1,-1);
ll main_ans=0;
for(i=1;i<=n;i++)
{
    if(vis1[i]==-1 && vis2[i]==-1)
    {
        ans=0;
        final_check=true;
        dfs(adj,i,vis1,0);
        ll x=0,y=0;
        bool p=final_check;
        //cout<<ans<<' ';
        if(final_check) x=ans;
        ans=0;
        final_check=true;
        dfs(adj,i,vis2,1);
        if(final_check)
        y=ans;
       // cout<<ans<<endl;
        if(p==false && final_check==false){
        cout<<-1<<endl;
        return;
        }
        main_ans+=max(x,y);

    }
}
cout<<main_ans<<endl;
}
int main() {
FAST;
ll t;
t=1;cin>>t;
while(t--)
solve();
}