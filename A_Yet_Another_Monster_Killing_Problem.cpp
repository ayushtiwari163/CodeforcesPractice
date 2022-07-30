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
class Segment_Tree
{
      vector<ll> seg;
      vector<ll> array;
      public:
      Segment_Tree(ll size, vector<ll> arr)
      {
            ll x =  4;
            ll n= x*size+1;
            seg.resize(n+1,0);
            array = arr;
      }
      ll construct_tree(ll start,ll l, ll r)
      {
          if(l==r)
          {
              seg[start]=array[l];
              return array[l];
          }
          ll mid = (l+r)/2;
          seg[start] = max(construct_tree(2*start+1,l,mid),construct_tree(2*start+2,mid+1,r));
          return seg[start]; 
      }
      ll get_max(ll index,ll start,ll end, ll l, ll r)
      {
          if(l<=start && r>=end)
          return seg[index];
          if(end<l || start>r)
          return 0;
          ll mid = (start+end)/2;
          return max(get_max(2*index+1,start,mid,l,r) , get_max(2*index+2,mid+1,end,l,r));

      }
     
        

}; 
 bool comp(pair<ll,ll> &x,pair<ll,ll> &y)
 {
     if(x.fi==y.fi)
     return x.se>y.se;
     return x.fi>y.fi;
 } 

 
void solve()
{
   ll n;
   cin>>n;
   vll a(n);
   ll i;
   ll mx =0;
   for(i=0;i<n;i++){
   cin>>a[i];
   mx=max(mx,a[i]);
   }
   ll m;
   cin>>m;
   vector<pair<ll,ll>> vec(m);
   for(i=0;i<m;i++)
       cin>>vec[i].fi>>vec[i].se;
   sort(all(vec),comp);
   
   if(vec[0].fi<mx)
   {
       cout<<-1<<endl;
       return;
   }
  vll temp1(m),temp2(m);
  i=0;
  reverse(all(vec));
  for(auto nb : vec)
  {
      temp1[i]=nb.fi;
      temp2[i++]=nb.se;
  }
  Segment_Tree seg(n,a);
  seg.construct_tree(0,0,n-1);
  ll start =0;
  Segment_Tree seg2(m,temp2);
  seg2.construct_tree(0,0,m-1);
  ll ans =0;
  while(true)
  {
    if(start>n) break;
    // binary search;
    ll left = start;
    ll right = n-1;
    ll x=start;
    while(left<=right)
    {
        
        ll mid =  (left+right)/2;
        mx  = seg.get_max(0,0,n-1,start,mid);
        ll index =  lower_bound(all(temp1),mx)-temp1.begin();
        bool f=true;
       // cout<<"ind-> "<<index<<" val-> "<<mx<<' ';
        if(index==m)
        f=false;
        else{
            
           ll mx1 = seg2.get_max(0,0,m-1,index,m-1);
           if(mx1<mid-start+1)
           f=false;
        }
        
        if(f)
        {
          x=mid;
          left = mid+1; 
        }
        else 
        {
           right=mid-1;
        }
        
    }
    //cout<<x<<endl;
    start=x+1;
    ans++;

  }
  
  cout<<ans-1<<endl;

}
int main() {
FAST;
ll t;
t=1;cin>>t;
while(t--)
solve();
}