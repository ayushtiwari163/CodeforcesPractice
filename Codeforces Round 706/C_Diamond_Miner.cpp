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
double squareRoot(ll number, ll precision) 
{ 
	ll start = 0, end = number; 
	ll mid; 

	// variable to store the answer 
	double ans; 

	// for computing llegral part 
	// of square root of number 
	while (start <= end) { 
		mid = (start + end) / 2; 
		if (mid * mid == number) { 
			ans = mid; 
			break; 
		} 

		// incrementing start if llegral 
		// part lies on right side of the mid 
		if (mid * mid < number) { 
			start = mid + 1; 
			ans = mid; 
		} 

		// decrementing end if llegral part 
		// lies on the left side of the mid 
		else { 
			end = mid - 1; 
		} 
	} 

	// For computing the fractional part 
	// of square root upto given precision 
	double increment = 0.1; 
	for (int i = 0; i < precision; i++) { 
		while (ans * ans <= number) { 
			ans += increment; 
		} 

		// loop terminates when ans * ans > number 
		ans = ans - increment; 
		increment = increment / 10; 
	} 
	return ans; 
} 
double root(ll x, ll y){
    return sqrt((x*x)+(y*y));
}
 void solve()
 {
     ll n;
     cin>>n;
     ll i;
     vector<ll> x,y;
     cout<<fixed<<setprecision(15);
     for(i=0;i<2*n;i++)
     {
         ll a,b;
         cin>>a>>b;
         if(a==0)
         y.pb(abs(b));
         else 
         x.pb(abs(a));
     }
     sort(all(x));
     sort(all(y));
    
    double ans=0;
    for(i=0;i<n;i++){
        // cout<<a[i]<<" "<<b[i]<<endl;
        ans=ans+root(x[i],y[i]);
    }
   cout<<ans<<endl;
 }
int main(){
  ll t=1; cin>>t;
  while(t--)
  solve();
}
// Are you check all base case such as n=1,n=0 etc??
// check all out of bound of array or unitilalise value
// Donot stuck with same logic think out of box
// if do not strike let this problem go or see editorial
// This question doesnot decide your future so donot disappoint

