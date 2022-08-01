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
ll ivalue(string s)  {  ll x=0;  stringstream obj(s);  obj >> x;  return x;  } 
const ll M = 1e9 + 7;
const ll N = 1e5 + 5;
const ll inf = 9e18;
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
    
    
void solve()
{
    ll n,m,seg;
    cin>>n>>m>>seg;
    ll c[n+1];
    ll col[n+1][m+1];
    ll i,j,k,k1;
    ll dp[n+1][m+1][seg+1];
    for(i=0;i<=n;i++)
    {
      for(j=0;j<=seg;j++)
      {
          for(k=0;k<=m;k++)
          dp[i][j][k]=inf;
      }
    }
    for(i=1;i<=n;i++) cin>>c[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        cin>>col[i][j];
    }
    if(c[1]==0)
    {
        //ek segment lagaoo lagaoo har col try maro;
        for(j=1;j<=m;j++)
        dp[1][1][j]=col[1][j];
    }
    else 
    {
        dp[1][1][c[1]]=0;
    }
    // for(j=1;j<=m;j++)
    // cout<<dp[1][1][j]<<' ';
    for(i=2;i<=n;i++)
    {
        for(k=1;k<=seg;k++)
        {
            if(c[i]==0)
            {
                for(j=1;j<=m;j++)
                {
                    ll x=dp[i-1][k][j]+col[i][j];
                    ll y=inf;
                    for(k1=1;k1<=m;k1++)
                    {
                        if(j==k1) continue;
                        y=min(y,dp[i-1][k-1][k1]+col[i][j]);
                    }
                    dp[i][k][j]=min(x,y);
                    
                }
            }
            else 
            {
                ll x=dp[i-1][k][c[i]];
                ll y=inf;
                for(j=1;j<=m;j++)
                {
                    if(j==c[i]) continue;
                    y=min(y,dp[i-1][k-1][j]);
                }
                dp[i][k][c[i]]=min(x,y);
            }
        }

        
    }
    ll ans=inf;
    for(i=1;i<=m;i++)
    {
       
        ans=min(ans,dp[n][seg][i]);
        
    }
    if(ans==inf) cout<<-1<<endl;
    else cout<<ans<<endl;
}
int main() {
    FAST;
ll t;
t=1;
while(t--)
solve();
}