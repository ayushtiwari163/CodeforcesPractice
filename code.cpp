
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve()
{
    ll x,n;
    cin>>x>>n;
    
   
    for(ll i=0;i<n;i++) 
    {
       ll p;
       cin>>p;
       x+=p;
    }
    cout<<x<<endl;

}
int main() {

ll t;
t=1;
while(t--)
solve();
}