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
    
    
void solve(int test)
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> a(m);
    ll i,j;
    for(i=0;i<m;i++){
        cin>>a[i].fi;
        a[i].se=i;
    }
     ll ans=0;
     sort(all(a));
     vector<bool> vis(m,false);
     for(i=0;i<n;i++)
     {
        vector<pair<ll,ll>> b(m);
        set<ll> s;
        for(j=0;j<m;j++)
        {
           // cout<<a[j].fi<<' '<<a[j].se<<"    ";
            cin>>b[j].fi;
            b[j].se=-1;
            s.insert(j);

        }
       // cout<<endl;
        //sort(all(b));
        vector<bool> vis1(m+1,false);
        for(j=0;j<m;j++)
        {
         
            pair<ll,ll> p=b[j];
            //ll index=0;
            ll index=lower_bound(all(a),p)-a.begin();
            
             while(index<m && b[j].fi==a[index].fi && vis1[index]==true)
             index++;
            // cout<<index<<' ';
             if(index<m && b[j].fi==a[index].fi && vis1[index]==false){
                b[j].se=a[index].se;
                s.erase(b[j].se);
                vis1[index]=true;
             
             }
            
        }
        sort(all(b));
       // cout<<endl;
        for(j=0;j<m;j++)
        {
            if(b[j].se==-1)
            {

                ll val=*s.begin();
                if(vis[val]==false)
                vis[val]=true;
                else 
                ans++;
                b[j].se=val;
                s.erase(val);
            }
           

        }
        a=b;



     }

    
    
cout<<"Case #"<<test<<": ";
cout<<ans<<endl;
}
int main() {
FAST;
	    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("runway_input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
     #endif
ll t;
t=1;cin>>t;
for(int i=1;i<=t;i++)
solve(i);
}