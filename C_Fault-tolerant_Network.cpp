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
    ll n;
    cin >> n;
    vll a(n), b(n);
    ll i;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        cin >> b[i];
    ll ans1 = abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]);
    ll ans2 = abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]);
    ll ans = min(ans1, ans2);
    // c1-0,c2-0,c1-n,c2-n
    ll node1 = inf;

    for (i = 0; i < n; i++)
    {
        node1 = min(node1, abs(a[0] - b[i]));
    }

    ll node2 = inf;
    ll ind = -1;
    for (i = 0; i < n; i++)
    {

        node2 = min(node2, abs(a[i] - b[0]));
    }

    ll node3 = inf;
    for (i = 0; i < n; i++)
    {
        node3 = min(node3, abs(a[n - 1] - b[i]));
    }
    ll node4 = inf;
    for (i = 0; i < n; i++)
    {
        node4 = min(node4, abs(b[n - 1] - a[i]));
    }
    if (node1 == (ll)abs(a[0] - b[0]) && node1 == (ll)abs(a[0] - b[n - 1]))
    {
        if (node4 > node2)
            node4 = 0;
        else
            node2 = 0;
    }
    else if (node1 == (ll)abs(a[0] - b[0]))
        node2 = 0;
    else if (node1 == (ll)abs(a[0] - b[n - 1]))
        node4 = 0;
    if (node3 == (ll)abs(a[n - 1] - b[0]) && node3 == (ll)abs(a[n - 1] - b[n - 1]))
    {
        if (node4 > node2)
            node4 = 0;
        else
            node2 = 0;
    }
    else if (node3 == (ll)abs(a[n - 1] - b[0]))
        node2 = 0;
    else if (node3 == (ll)abs(a[n - 1] - b[n - 1]))
        node4 = 0;
    ans = min(ans, node1 + node2 + node3 + node4);
    cout << ans << endl;
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