// これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました
//ジャイシュリーラム
#include <bits/stdc++.h>
#include <cmath>
#include <cstring>
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
    
ll longestPrefixSuffix(string s)
{
	ll n = s.length();
    
}
void solve()
{
   string s1,s2;
   cin>>s1>>s2;
   ll n=s1.size();
   ll m=s2.size();
   ll i;
   ll c0=0,c1=0;
   for(i=0;i<n;i++)
   {
       if(s1[i]=='0')
       c0++;
       else
       c1++;
   }
  ll x1=0,x0=0;
  string fstr=s2;
  string lstr="";
  
//   ll x=longestPrefixSuffix(s2);
//   cout<<x<<' ';
  if(x!=0)
  lstr=s2.substr(m-x,x);
  if(x!=0)
  fstr=s2.substr(0,m-x);
  string ans="";
//cout<<lstr<<' '<<fstr<<endl;
  for(i=0;i<fstr.size();i++)
  {
      if(fstr[i]=='1')
      x1++;
      else 
      x0++;
  }
  ll x2=0,x3=0;
  for(i=0;i<lstr.size();i++)
  {
      if(lstr[i]=='1')
      x2++;
      else 
      x3++;
  }
  while(c0>=x0 && c1>=x1)
  {
      ans.append(fstr);
      c0=c0-x0;
      c1=c1-x1;
  }
  
  while(c0>=x3 && c1>=x2 && x2!=0 && x3!=0)
  {
      ans.append(lstr);
      c0=c0-x3;
      c1=c1-x2;
  }
  //cout<<ans<<endl;
  //cout<<c1<<' '<<c0<<endl;
  while(c1)
  {
      c1--;
  ans.pb('1');
  //cout<<ans<<endl;
  }
  while(c0){
      c0--;
  ans.pb('0');}
  cout<<ans<<endl;


}
   int main() {
       FAST;
ll t;
t=1;
while(t--)
solve();
}