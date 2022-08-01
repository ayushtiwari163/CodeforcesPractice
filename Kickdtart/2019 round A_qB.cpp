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
vector<string> s;
ll dx[]={1,0,-1,0};
ll dy[]={0,1,0,-1};
bool valid(ll x,ll y)
{
    if(x<0 || y<0 || x>=n || y>=m)
    return false;
    return true;
}
ll bfs(vector<pair<ll,ll>> s,ll a,ll b)
{
	queue<pair<ll,ll>> q;
    	vector<vll> dis(n+1,vll(m+1,-1));
    if(a!=-1)
    {
        q.push({a,b});
        dis[a][b]=0;
    }


	for (pair<ll,ll> src : s)
	{
		q.push(src);
		dis[src.fi][src.se] = 0;
	}
    ll mx=0;
	while (!q.empty())
	{
		pair<ll,ll> i = q.front();
		q.pop();
       
		for (ll p=0;p<4;p++)
		{
            ll x=dx[p]+i.fi;
            ll y=dy[p]+i.se;
          // cout<<dx[p]<<' '<<dy[p]<<endl;
            if(!valid(x,y)) continue;
			if (dis[x][y] != -1)
				continue;
                 

			q.push({x,y});
			dis[x][y] = dis[i.fi][i.se] + 1;
            mx=max(mx,dis[x][y]);
		}
	}

	return mx;
}
 void solve(ll t)
 {
      cin>>n>>m;
      s.resize(n+1);
      s.clear();
      ll i,j;
      for(i=0;i<n;i++)
      cin>>s[i];
      vector<pair<ll,ll>> sources;
      for(i=0;i<n;i++)
      {
          for(j=0;j<m;j++)
          {
              if(s[i][j]=='1')
              sources.pb({i,j});
          }
      }
      ll ans=INT_MAX;
      if(sources.size()>0)
       ans=bfs(sources,-1,-1);
      for(i=0;i<n;i++)
      {
          for(j=0;j<m;j++)
          {
              if(s[i][j]=='0')
              {
                  ll x=bfs(sources,i,j);
                  //cout<<"here my x  "<<x<<' ';
                  ans=min(ans,x);
              }
          }
      }
cout<<"Case #"<<t<<": "<<ans<<endl;;
      
 }
int main(){
  ll t=1; cin>>t;
  for(ll i=1;i<=t;i++)
  {
  
  solve(i);
  }
}
// Are you check all base case such as n=1,n=0 etc??
// check all out of bound of array or unitilalise value
// Donot stuck with same logic think out of box
// if do not strike let this problem go or see editorial
// This question doesnot decide your future so donot disappoint
