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
    ll n; cin>>n;
    map<ll,ll> m;
    ll i;
    for(i=0;i<n;i++)
    {
        ll x; cin>>x;
       m[-x]++;
    }
    ll mx=(n-4)/6;
   ll x=n/2;
     ll g=0,s=0,b=0;
     if(mx<=0)
     {
         cout<<0<<' '<<0<<' '<<0<<endl;
         return;
     }
    

   auto it=m.begin();
   m.erase(it);
   g=g+it->se;
 
    for(auto p : m)
    {
        if(s+p.se+g+b>x)
        break;
        if(s<=g){
        s=s+p.se;
        continue;}
        if(b+p.se+s+g<=x)
        {
            b=b+p.se;
        }
        else 
        break;

    }
  //cout<<g<<" "<<s<<' '<<b;
    if(b<=g)
    {
        cout<<0<<' '<<0<<' '<<0<<endl;
        return;
    }
    if(s<=g)
    {
        cout<<0<<' '<<0<<' '<<0<<endl;
        return;
    }
    cout<<g<<' '<<s<<' '<<b<<endl;
}
 
int main(){
  ll t; cin>>t;
  while(t--)
  solve();
}