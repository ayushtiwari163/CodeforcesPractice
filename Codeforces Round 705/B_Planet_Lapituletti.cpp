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
   vector<bool> v(10,false);
    
bool valid(ll h,ll m,string s)
{
 
    ll i;
    ll p1=s[0]-'0';
    if(p1==2)
    p1=5;
    else if(p1==5)
    p1=2;
    ll p2=s[1]-'0';
     if(p2==2)
    p2=5;
    else if(p2==5)
    p2=2;
    ll hrs=p1+10*p2;

    ll m1=s[3]-'0';
     if(m1==2)
    m1=5;
    else if(m1==5)
    m1=2;
    ll m2=s[4]-'0';
     if(m2==2)
    m2=5;
    else if(m2==5)
    m2=2;
    ll min=m1+10*m2;
    if(min>h-1|| hrs>m-1)
    return false;
    if(v[p1] && v[p2] && v[m1] && v[m2])
    return true;
    else 
    return false;


}
 void solve()
 {
     ll h,m; cin>>h>>m;
  string s; cin>>s;
  ll i,j,k,l;
  ll p1=(s[0]-'0');
    ll p2=(s[1]-'0');
    ll hrs=10*p1+p2;
    ll m1=(s[3]-'0');
    ll m2=s[4]-'0';
    ll min=10*m1+m2;
    string s1=s;
    while(true)
    {
        if(valid(h,m,s))
        {
            cout<<s<<endl;
            return;
        }
        min=(min+1)%m;
        if(min==0)
        hrs=(hrs+1)%h;
        //cout<<hrs<<' '<<min<<endl;
        ll p1=hrs/10;
        ll p2=hrs%10;
        ll m1=min/10;
        ll m2=min%10;
        s[0]=p1+'0';
        s[1]=p2+'0';
        s[3]=m1+'0';
        s[4]=m2+'0';
        //cout<<s<<endl;
    }
     
 }
int main(){
    v[0]=true;
    v[1]=true;
    v[2]=true;
    v[5]=true;
    v[8]=true;
  ll t=1; cin>>t;
  while(t--)
  solve();
}
// Are you check all base case such as n=1,n=0 etc??
// check all out of bound of array or unitilalise value
// Donot stuck with same logic think out of box
// if do not strike let this problem go or see editorial
// This question doesnot decide your future so donot disappoint
