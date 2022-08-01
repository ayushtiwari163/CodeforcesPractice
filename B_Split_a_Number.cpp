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
string mini(string s1,string s2)
{
    if(s1.size()>s2.size())
    return s2;
    if(s1.size()<s2.size())
    return s1;
    return min(s1,s2);
}
string sum(string s1,string s2)
{
    ll i;
    ll n=s1.size();
    ll m=s2.size();
    ll carry =0;
    ll j=m-1;
    i=n-1;
    string ans;
    while(i>=0 || j>=0)
    {
        ll p;
        if(i>=0 && j>=0){
       p=(s1[i]-'0')+(s2[j]-'0')+carry;
       i--;
       j--;
        }
       else if(i>=0)
        {
            p=(s1[i]-'0')+carry;
            i--;
        }
       else if(j>=0)
        {
           p=(s2[j]-'0')+carry;
           j--;
        }
        char c=p%10+'0';
        ans.pb(c);
        carry=p/10;
    }
    if(carry!=0)
    ans.pb(carry+'0');
    reverse(all(ans));
    return ans;
}
 void solve()
 {
     ll n;
     cin>>n;
    string s;
    cin>>s;
    bool f=false;
    ll i;
    for(i=0;i<n;i++)
        vector<string> ans;
    if(n%2==0 && s[n/2]!='0')
    {
        cout<<sum(s.substr(0,n/2),s.substr(n/2,n/2))<<endl;
        return;
    }
    if(n%2!=0 && s[n/2]!='0')
    {
        string x=sum(s.substr(0,n/2),s.substr(n/2,n/2+1));
        string y=sum(s.substr(0,n/2+1),s.substr(n/2+1,n/2));
        cout<<mini(x,y)<<endl;
        return;
    }
   ll fpoint=n/2;
   ll lpoint=n/2;
   while(s[fpoint]=='0')
   {
         fpoint--;
   }
    while(s[lpoint]=='0')
   {
         lpoint++;
   }
   string x=sum(s.substr(0,lpoint),s.substr(lpoint,n-lpoint));
   
   if(fpoint==0)
   {
       cout<<x<<endl;
       return;
   }
   string y=sum(s.substr(0,fpoint),s.substr(fpoint,n-fpoint));
   //cout<<fpoint<<' '<<lpoint<<endl;
   //cout<<x<<endl;
   // cout<<y<<endl;
   cout<<mini(x,y)<<endl;
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
