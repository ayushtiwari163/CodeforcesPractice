// これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました
//ジャイシュリーラム
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#include <cmath>
#include <regex>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ba back
#define ppb pop_back
#define pqb priority_queue<long long int>
#define eb emplace_back
#define eps 1e-6
#define vll vector<long long int>
#define pqs priority_queue<int, vll, greater<long long int>>
#define sz(x) (int((x.size())))
#define all(x) (x).begin(), (x).end()
#define FAST                           \
    ios_base ::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;
typedef long long int ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
ll ivalue(string s)
{
    ll x = 0;
    stringstream obj(s);
    obj >> x;
    return x;
}
const ll M = 1e9 + 7;
const ll N = 1e5 + 5;
const ll inf = 2e18;
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
ll mod_div(ll a, ll b)
{ // only if M is prime
    ll ans = mod(a);
    ll b1 = power(b, M - 2);
    ans = mod(mod_mul(ans, b1));
    return ans;
}
ll mod_inv(ll n) { return power(n, M - 2); }
ll fact_mod(ll n)
{
    vll fact(n + 1);
    fact[0] = 1;
    for (ll i = 1; i < n + 1; i++)
    {
        fact[i] = mod_mul(fact[i - 1], i);
    }
    return fact[n];
}
ll nCr_mod(ll n, ll r)
{
    if (r == 0 || n == 0)
        return 1;
    ll fac[n + 1];
    fac[0] = 1;
    for (ll i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % M;
    return (fac[n] * mod_inv(fac[r]) % M * mod_inv(fac[n - r]) % M) % M;
}
ll upper_fraction(ll a, ll b)
{
    if (a % b == 0)
        return a / b;
    else
        return (a / b) + 1;
}
bool isInt(double d)
{
    double dummy;
    return modf(d, &dummy) == 0.0;
}

void solve()
{
    ll l, r;
    cin >> l >> r;
    vll a(r - l + 1);
    ll i, j;
    ll n = r - l + 1;
    for (i = 0; i < n; i++)
        cin >> a[i];
    vll cnt(20, 0);
    for (i = 0; i < n; i++)
    {

        ll x = a[i];
        ll j = 0;
        while (x > 0)
        {
            cnt[j] += (x % 2);
            x = x / 2;
            j++;
        }
    }
    vll cnt1(20, 0);
    for (i = l; i <= r; i++)
    {
        ll x = i;
        ll j = 0;
        while (x > 0)
        {
            cnt1[j] += (x % 2);
            x = x / 2;
            j++;
        }
    }

    reverse(all(cnt));
    reverse(all(cnt1));
    vll ans(20, 0);
    for (i = 0; i < 20; i++)
    {
        if (cnt[i] == n && cnt1[i] == 0)
            ans[i] = 1;
        if (cnt[i] == 0 && cnt1[i] == n)
            ans[i] = 1;
        if ((n - cnt[i] == cnt1[i]) || (n - cnt1[i] == cnt[i]))
            ans[i] = 1;
    }
    ll num = 0;
    reverse(all(ans));
    for (i = 0; i < 20; i++)
    {
        if (ans[i] == 1)
            num += (1 << i);
        // cout << (1 << i) << ' ';
    }
    cout << num << endl;
}
int main()
{
    FAST;
    ll t;
    t = 1;
    cin >> t;
    while (t--)
        solve();
}