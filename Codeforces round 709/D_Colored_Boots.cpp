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
  ll n;
  cin>>n;
  string s1,s2;
  cin>>s1>>s2;
  vector<pair<ll,ll>> ans;
  vll a[27],b[27];
  ll i;
  vll c1(27),c2(28);
  for(i=0;i<n;i++)
  {
      if(s1[i]=='?')
      a[26].pb(i+1);
      else 
      a[s1[i]-'a'].pb(i+1);
      if(s2[i]=='?')
      b[26].pb(i+1);
      else 
      b[s2[i]-'a'].pb(i+1);
  }
  for(i=0;i<26;i++)
  {
      ll p=0,q=0;
      while(p<a[i].size() && q<b[i].size())
      {
          pair<ll,ll> x={a[i][p],b[i][q]};
          ans.pb(x);
          p++;
          q++;

      }
      c1[i]=p;
      c2[i]=q;
  }
  ll p=0,q=0;
  i=0;
  ll j=0;
      for(i=0;i<26;i++)
      {
          ll x1=c2[i];
          while(x1<b[i].size() && p<a[26].size())
          {
              pair<ll,ll> x={a[26][p],b[i][x1]};
              ans.pb(x);
              x1++;
              p++;
          }
      }
      c1[26]=p;
   p=0;
     for(i=0;i<26;i++)
      {
          ll x1=c1[i];
          while(x1<a[i].size() && p<b[26].size())
          {
              pair<ll,ll> x={a[i][x1],b[26][p]};
              ans.pb(x);
              x1++;
              p++;
          }
      }
     c2[26]=p;
     p=c1[26];
     q=c2[26];
     while(p<a[26].size() && q<b[26].size())
     {
         pair<ll,ll> x={a[26][p],b[26][q]};
         ans.pb(x);
         p++;
         q++;
     }
     cout<<ans.size()<<endl;
     for(auto x : ans)
     cout<<x.fi<<' '<<x.se<<endl;
  

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
