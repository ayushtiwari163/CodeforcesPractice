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
  string s;
  cin>>s;
  ll n=s.size();
  ll i;
  unordered_set<char> s1;
  string rem="";
  vll count(26,0),count_last(26,0);
  for(i=n-1;i>=0;i--)
  {
      ll x=s1.size();
      s1.insert(s[i]);
      if(x<s1.size())
      rem=s[i]+rem;
      count[s[i]-'a']++;
  }
  ll x=rem.size();
  //cout<<rem<<endl;
  for(i=0;i<rem.size();i++)
  {
      
      ll occ=i+1;
      ll p=count[rem[i]-'a'];
      //cout<<rem[i]<<' '<<occ<<' '<<p<<endl;
      if(p%occ==0)
      count_last[rem[i]-'a']=p/occ;
      else{ 
      cout<<-1<<endl;
      return;
      }

  }
  vll last(26,0);
  for(i=0;i<n;i++)
  {
      last[s[i]-'a']++;
      bool f=true;
      for(ll j=0;j<26;j++)
      {
          if(count_last[j]!=last[j])
          {
              f=false;
              break;
          }
      }
      if(f) break;
  }
  ll t=i+1;
  string temp=s.substr(0,i+1);
  string news=temp;
  for(i=0;i<rem.size();i++)
  {
      string x;
      for(ll j=0;j<temp.size();j++)
      {
         if(temp[j]==rem[i]) continue;
         x.pb(temp[j]);
      }
      temp=x;
      news+=temp;
  }
  if(news!=s) cout<<-1<<endl;
  else cout<<s.substr(0,t)<<' '<<rem<<endl;
  

}
int main() {
FAST;
ll t;
t=1;cin>>t;
while(t--)
solve();
}