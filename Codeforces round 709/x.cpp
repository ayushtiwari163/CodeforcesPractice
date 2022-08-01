#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define endl "\n"
#define vll vector<ll>
#define pll pair<ll,ll>
#define pqb priority_queue<ll>
#define pqs priority_queue<ll,vll,greater<ll> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x)             (int)((x).size())
#define FAST ios_base :: sync_with_stdio (false); cin.tie (NULL)
#define fo(i,s,n) for(ll i=s;i<n;i++)
#define rfo(i,n,s) for(ll i=n;i>=s;i--)
using namespace std;
typedef long long int ll;
template <class T> T mceil(T a, T b){if(a % b == 0) return a/b; else return a/b + 1;}
const ll M = 1e9 + 7;
const ll N = 2e5 + 5;
const ll inf = 9e18;

vll vis;
vector<vll> adj;
void solve() {
    ll n; cin>>n;
    vll v(n);
    fo(i,0,n)cin>>v[i];
    vll dif(n-1);
    set<ll> pos,neg;
    fo(i,0,n-1){
        dif[i]=v[i]-v[i+1];
        if(dif[i]>=0)pos.insert(dif[i]);
        else neg.insert(dif[i]);
    }
    if(sz(pos)>1 || sz(neg)>1){cout<<-1<<endl; return ;}
    if((sz(pos)+sz(neg))==1){cout<<0<<endl; return;}
  ll mx=*max_element(all(v));
  mx+=1;
    ll m=(*pos.begin())-(*neg.begin());
    if(m<mx){cout<<-1<<endl; return ;}
    fo(i,0,sz(dif)){
        if(dif[i]>=0){dif[i]-=m;}
    }
    set<ll> ans;
    fo(i,0,sz(dif)){
      ans.insert(dif[i]);

    }
    if(sz(ans)==1){
        cout<<m<<" "<<abs(dif[0])<<endl; return ;
    }
    else {
        cout<<-1<<endl; return ;
    }

}
int main(){
    FAST;
ll t;
cin>>t;
fo(i,1,t+1){
//cout<<"Case #"<<i<<": ";
solve();

}

}