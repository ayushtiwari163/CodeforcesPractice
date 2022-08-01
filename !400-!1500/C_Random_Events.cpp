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

 void solve()
 {
     ll n,q;
     cin>>n>>q;
     vll a(n+1);
     ll i;
     for(i=1;i<=n;i++)
     cin>>a[i];
     ll k=0;
     for(i=n;i>0;i--)
     {
         if(a[i]==i)
         k++;
         else 
         break;
     }
  
     double ans=1.0;
     cout<<fixed<<setprecision(6);
     vector<pair<ll,double>> v;
    ll t=q; 
     while (q--)
     {
       ll x;
       double p;
       cin>>x>>p;
    //    if(k==0)
    //    {
    //        if(x==n)
    //        {
    //            cout<<p<<endl;
    //            return;
    //        }
    //    }
       pair<ll,double> c={x,p};
       v.pb(c);
     }
       if(k==n)
     {
     cout<<1.00000000<<endl;
     return;}
    ll f=n-k;
   //  cout<<f<<endl;
     sort(all(v));
     for(i=t-1;i>=0;i--)
     {
         pair<ll,double> x=v[i];
       //  cout<<x.fi<<' '<<x.se<<endl;
         if(x.fi>=f)
         ans=ans*(1.0-x.se);
         else 
         break;

     }
   

     ans=1.0-ans;
   
     cout<<ans<<endl;
   
     

 }
int main(){
  ll t; cin>>t;
  while(t--)
  solve();
}