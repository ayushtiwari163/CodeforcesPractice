#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll M = 998244353;
ll mod(ll x) { return (x % M); }
ll mod_minus(ll a, ll b)
{
    ll ans = (mod(a) - mod(b));
    if (ans < 0)
        ans = mod(ans + M);
    return ans;
}
ll mod_mul(ll a, ll b) { return mod(mod(a) * mod(b)); }
ll mod_add(ll a, ll b) { return mod(mod(a) + mod(b)); }
ll power(ll a, ll n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return a;
    ll R = power(a, n / 2) % M;
    if (n % 2 == 0)
    {
        return mod(mod_mul(R, R));
    }
    else
    {
        return mod(mod_mul(mod_mul(R, a), mod(R)));
    }
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll i;
    map<ll, ll> m;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    sort(a.begin(), a.end());
    ll ans = 0;

    for (i = 0; i < n; i++)
    {
        ans = mod_add(ans, mod_mul(a[i], a[i]));
        for (ll j = i + 1; j < n; j++)
        {

            ll cnt = j - i - 1;
            ll x = power(2, cnt);
            ans = mod_add(ans, mod_mul(x, mod_mul(a[i], a[j])));
        }
    }
    cout << ans << endl;
}