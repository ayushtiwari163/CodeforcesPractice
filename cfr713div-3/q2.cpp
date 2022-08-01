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
    
    
void solve()
{
  ll n; cin>>n;

  vll a(n+2);
  ll i;
  map<ll,ll> m;
  ll sum=0;
  for(i=0;i<n+2;i++)
  {
      cin>>a[i];
      m[a[i]]++;

      sum=sum+a[i];
  }
 

  bool f=true;
  sort(all(a));
ll x1=sum-a[n]*2;
ll x2=sum-a[n+1]*2;
if(x1==a[n])
{
    if(m[x1]>=2)
    {
        m[x1]=m[x1]-2;
        f=false;
    }
}
else 
{
    if(m[x1]>=1)
    {
        m[x1]--;
        m[a[n]]--;
        f=false;
    }
}

if(f==true)
{
    if(x2==a[n+1])
   {
    if(m[x2]>=2)
    {
        m[x1]=m[x1]-2;
        f=false;
    }
    }
  else 
  {
    if(m[x2]>=1)
    {
        m[x2]--;
        m[a[n+1]]--;
        f=false;
    }
}
}
if(f)
{
    cout<<-1<<endl;
    return;
}
for(auto nb : m)
{
    for(i=0;i<nb.se;i++)
    {
        cout<<nb.fi<<' ';
    }
}
  cout<<endl;
}
int main() {
ll t;
t=1; cin>>t;
while(t--)
solve();
}