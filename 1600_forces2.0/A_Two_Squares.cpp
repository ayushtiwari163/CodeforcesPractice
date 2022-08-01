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
    
struct point
{
    ll x,y;
};
bool comp(pair<ll,ll> &p1,pair<ll,ll> &p2)
{
    if(p1.fi<p2.fi) return true;
    if(p1.fi>p2.fi) return false;
    else 
    {
        return p1.se<p2.se;
    }
     

} 
bool check(ll x,ll y ,vector<pair<ll,ll>> &h)
{
    ll val1=x-y-h[0].fi+h[0].se;
    ll val2=-x-y+h[0].fi+h[0].se;
    ll val3=x-y-h[1].fi+h[1].se;
    ll val4=x+y-h[2].fi+h[2].se;
     //if(x==3 && y==3)
     //cout<<val1<<' '<<val2<<' '<<val3<<' '<<val4<<endl;
    if(val1*val3<0 && val2*val4<0)
    return true;
    if(val1 * val3==0 && val2 * val4<0)
    return true;
    if(val1 * val3<0 && val2 * val4==0)
    return true;
    if((val1==0 && val2==0)||(val1==0 && val4==0) || (val2==0 && val3==0) || (val3==0 && val4==0))
    return true;
    return false;
}
void solve()
{
   point vp1,vp2,vp3,vp4;
   vector<pair<ll,ll>> v(4);
   vector<pair<ll,ll>> h(4);
   point l,d,r,u;
   ll i;
   for(i=0;i<4;i++)
   {
       ll fir,sec;
       cin>>fir>>sec;
       v[i]={fir,sec};
   }
    for(i=0;i<4;i++)
   {
       ll fir,sec;
       cin>>fir>>sec;
       h[i]={fir,sec};
   }
 sort(all(v),comp);

// vp1.x=v[0].fi; vp1.y=v[0].se;
// vp2.x=v[1].fi; vp2.y=v[1].se;
// vp3.x=v[2].fi; vp3.y=v[2].se;
// vp4.x=v[3].fi; vp4.y=v[3].se;
ll x_cor1=v[0].fi;
ll y_cor1=v[0].se;
ll y_cor2=v[3].se;
ll x_cor2=v[3].fi;
sort(all(h),comp);
ll j;
// cout<<"Debug ---starting....."<<endl;
// cout<<"vale of 45 --"<<endl;
// for(i=0;i<4;i++)
// {
//   cout<<h[i].fi<<' '<<h[i].se<<endl;
// }
// cout<<"...........  ";
// cout<<x_cor1<<' '<<x_cor2<<endl;
// cout<<"Vale of parllel"<<endl;
for(i=x_cor1;i<=x_cor2;i++)
{
    for(j=y_cor1;j<=y_cor2;j++)
    {
       // cout<<i<<' '<<j<<endl;
          if(check(i,j,h))
          {
             // cout<<i<<' '<<j<<endl;
              cout<<"YES"<<endl;
              return;
          }
    }
}
cout<<"NO"<<endl;



}
int main() {
ll t;
t=1;
while(t--)
solve();
}