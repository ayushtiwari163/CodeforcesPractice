// これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました
//ジャイシュリーラム
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
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
    
ll printClosest(vll arr, ll n, ll x)
{
    ll res_l, res_r;  // To store indexes of result pair
  
    // Initialize left and right indexes and difference between
    // pair sum and x
    ll l = 0, r = n-1, diff = inf;
  
    // While there are elements between l and r
    while (r > l)
    {
       // Check if this pair is closer than the closest pair so far
       if (abs(arr[l] + arr[r] - x) < diff)
       {
           res_l = l;
           res_r = r;
           diff = abs(arr[l] + arr[r] - x);
       }
  
       // If this pair has more sum, move to smaller values.
       if (arr[l] + arr[r] > x)
           r--;
       else // Move to larger values
           l++;
    }
  return diff;
}  
ll minCost(vll A, ll n)
{
    // Initialize cost to 0
    ll cost = 0;
 
    // Sort the array
    sort(all(A));
 
    // Middle element
    ll K = A[n / 2];
 
    // Find Cost
    for (ll i = 0; i < n; ++i)
        cost += abs(A[i] - K);
 
    // If n, is even. Take minimum of the
    // Cost obtained by considering both
    // middle elements
    if (n % 2 == 0) {
        ll tempCost = 0;
 
        K = A[(n / 2) - 1];
 
        // Find cost again
        for (ll i = 0; i < n; ++i)
            tempCost += abs(A[i] - K);
 
        // Take minimum of two cost
        cost = min(cost, tempCost);
    }
 
    // Return total cost
    return cost;
}  
void solve()
{
   ll n;
   cin>>n;
   vll a(n);
   ll i;
   ll sum=0;
   for(i=0;i<n;i++)
   { 
       cin>>a[i];
       sum+=a[i];
   }



   sort(all(a));
   if(n<4)
   {
      if(n==2)
      cout<<a[1]-a[0]<<endl;
      else 
      {
          ll ans= min(a[1]-a[0],min(a[2]-a[0],a[2]-a[1]));
          cout<<ans<<endl;
      }
      return;
   } 
   ll mx=a[n-1];
   ll mi=a[0];
ll x=mx-mi;
ll y=a[n-2]-a[1];
ll ans= abs(x-y);
  vll temp;
  for(i=1;i<n-1;i++) temp.push_back(a[i]);
  ll ans1=printClosest(temp,n-2,mx+mi);
  ans=min(ans,ans1);
 temp.clear();
 for(i=0;i<n-1;i++) temp.pb(a[i]);
 ans=min(ans,minCost(temp,n-1));
 temp.clear();
 for(i=1;i<n;i++) temp.pb(a[i]);
 ans=min(ans,minCost(temp,n-1));

  cout<<ans<<endl;
}
int main() {
FAST;
ll t;
t=1;cin>>t;
while(t--)
solve();
}