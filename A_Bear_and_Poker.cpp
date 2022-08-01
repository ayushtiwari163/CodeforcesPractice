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
     vll a(n);
     ll i;
     for(i=0;i<n;i++)
     cin>>a[i];
     ll mx2=0,mx3=0;
     vll fac2(n),fac3(n);
     for(i=0;i<n;i++)
     {
         ll x=a[i];
         ll y=a[i];
         ll c2=0,c3=0;
         while(x%2==0)
         {
             x=x/2;
             c2++;

         }
         while(y%3==0)
         {
             y=y/3;
             c3++;
         }
         mx2=max(mx2,c2);
         mx3=max(mx3,c3);
         fac2[i]=c2;
         fac3[i]=c3;
     }
  for(i=0;i<n;i++)
  {
      ll mul2=mx2-fac2[i];
      ll mul3=mx3-fac3[i];
      a[i]=a[i]*pow(2,mul2);
      a[i]=a[i]*pow(3,mul3);
  }
  for(i=1;i<n;i++)
  {
     if(a[i]!=a[i-1])
     {
         cout<<"No"<<endl;
         return;
     }
  }
  cout<<"Yes"<<endl;
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
