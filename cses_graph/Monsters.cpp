// これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました 
//ジャイシュリーラム

#include <bits/stdc++.h>
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
const ll M = 1e9 + 7;
const ll N = 2e5 + 5;
const ll inf = 2e18;
ll mod(ll x){   return (x%M);}
ll mod_minus(ll a, ll b){ ll ans= (mod(a)-mod(b)); if(ans<0) ans=mod(ans+M); return ans;}
 
ll mod_mul(ll a,ll b){  return mod(mod(a)*mod(b));}
 
ll mod_add(ll a,ll b){ return mod(a+b);}
 
ll power(ll a,ll n){  
    if(n==0) return 1; 
     else if(n==1) return a; 
      ll R=power(a,n/2)%M; 
       if(n%2==0) {    return mod(mod_mul(R,R));  } 
    
      else {   return mod(mod_mul(mod_mul(R,a),mod(R)));  }
    }
 
ll mod_inv(ll n){  return power(n,M-2);}
 
// only if M is prime
ll mod_div(ll a,ll b){  
     ll ans=mod(a);   ll b1=power(b,M-2); 
       ans= mod(mod_mul(ans,b1));  
        return ans;
        }
 
ll fact_mod(ll n){ 
    vll fact(n+1);
     fact[0]=1;   
     for(ll i=1;i<n+1;i++){  
          fact[i]=mod_mul(fact[i-1],i);
           }  
            return fact[n];
    }
 //-------------------------------------
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
ll n,m;
vector<vll> dm(1001,vll(1001,-1));
vector<string> s;
vector<vll> dis(1001,vll(1001,-1));
ll dx[]={1,0,-1,0};
ll dy[]={0,1,0,-1};
vector<vector<pair<ll,ll>>> par(1001,vector<pair<ll,ll>>(1001,{-1,-1}));
bool valid(ll x,ll y)
{
    if(x<0 || y<0 || x>=n || y>=m)
    return false;
    if(s[x][y]=='#')
    return false;
    return true;
}
void bfs(pair<ll,ll> st)
{
        queue<pair<ll,ll>> q;
    q.push(st);
    dis[st.fi][st.se]=0;
    while (q.empty()==false)
    {
        pair<ll,ll> x=q.front();
        q.pop();
        for(ll p=0;p<4;p++)
        {
            ll x1=x.fi+dx[p];
            ll y1=x.se+dy[p];
            if(!valid(x1,y1)) continue;
            if(dis[x1][y1]==-1)
            {
                if((1+dis[x.fi][x.se])<dm[x1][y1]||dm[x1][y1]==-1){
                dis[x1][y1]=1+dis[x.fi][x.se];
                q.push({x1,y1});
                par[x1][y1]={x.fi,x.se};
                }
            }
        }
        
    }
}
void bfs_multi(vector<pair<ll,ll>> so)
{
    queue<pair<ll,ll>> q;
    for(pair<ll,ll> x : so){
        dm[x.fi][x.se]=0;
        q.push(x);
    }
    while (q.empty()==false)
    {
        pair<ll,ll> x=q.front();
        q.pop();
        for(ll p=0;p<4;p++)
        {
            ll x1=x.fi+dx[p];
            ll y1=x.se+dy[p];
            if(!valid(x1,y1)) continue;
            if(dm[x1][y1]==-1)
            {
                dm[x1][y1]=1+dm[x.fi][x.se];
                q.push({x1,y1});
            }
        }
        
    }
    
    
    
}
 void solve()
 {
     cin>>n>>m;
     s.resize(n+1);
    ll i,j;
    vector<pair<ll,ll>> sources;
    pair<ll,ll> a;
    for(i=0;i<n;i++)
    cin>>s[i];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(s[i][j]=='M')
            sources.pb({i,j});
            if(s[i][j]=='A')
            a={i,j};
        }
    }
    bfs_multi(sources);
    bfs(a);
    pair<ll,ll> dst={-1,-1};
    for(i=0;i<n;i++)
    {
      if(dis[i][0]!=-1)
      {
          dst={i,0};
          break;
      }
      if(dis[i][m-1]!=-1)
      {
          dst={i,m-1};
          break;
      }
    }
    //----------
    if(dst.fi==-1)
    {
           for(i=0;i<m;i++)
          {
             if(dis[0][i]!=-1)
              {
               dst={0,i};
                   break;
               }
             if(dis[n-1][i]!=-1)
               {
                dst={n-1,i};
               break;
               }
         }
    }
   if(dst.fi==-1)
   {
       cout<<"NO"<<endl;
       return;
   }

//cout<<dst.fi<<' '<<dst.se<<endl;
//cout<<par[7][1].fi<<' '<<par[7][1].se<<endl;

vector<char> ans;
 cout<<"YES"<<endl;
       
        pair<ll,ll> curr=dst;
        while(curr!=a)
        {
            ll x=curr.fi;
           ll y=curr.se;
           ll x1=par[x][y].fi;
           ll y1=par[x][y].se;
           if(x==x1 && y!=y1)
           {
               if(y==y1+1)
               ans.pb('R');
               else 
               ans.pb('L');
           }
           if(x!=x1 && y==y1)
           {
               if(x==x1+1)
               ans.pb('D');
               else
               ans.pb('U');
           }
           curr={x1,y1};
        }
         reverse(all(ans));
    cout<<ans.size()<<endl;
    for(auto x : ans)
    cout<<x;


 }
int main(){
  ll t=1;
  while(t--)
  solve();
}
// Are you check all base case such as n=1,n=0 etc??
// check all out of bound of array or unitilalise value
// Donot stuck with same logic think out of box
// if do not strike let this problem go or see editorial
// This question doesnot decide your future so donot disappoint
