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

void bellmon(vector<pair<ll, pair<ll, ll>>> &edges, vll &vis, ll src, ll n, ll m)
{
    vll dis(n + 1, inf);
    dis[src] = 0;
    vll par(n + 1, -1);
    bool flag = true;
    vis[src] = 1;
    // par[src] = src;
    for (ll i = 1; i <= n - 1; i++)
    {
        if (!flag)
            break;
        flag = false;
        for (ll j = 0; j < m; j++)
        {
            ll u = edges[j].first;
            ll v = edges[j].second.first;
            ll w = edges[j].second.second;
            if (dis[u] != inf && dis[u] + w < dis[v])
            {
                flag = true;
                par[v] = u;
                dis[v] = dis[u] + w;
                vis[v] = 1;
            }
        }
    }

    ll c = -1;
    for (ll j = 0; j < m; j++)
    {
        ll u = edges[j].first;
        ll v = edges[j].second.first;
        ll w = edges[j].second.second;
        if (dis[u] != inf && dis[u] + w < dis[v])
        {
            c = v;
            break;
        }
    }
    // cout << c << endl;
    for (ll i = 1; i <= n; i++)
    {
        if (par[i] == -1)
            par[i] = 5;
    }
    if (c != -1)
    {
        cout << "YES" << endl;
        for (ll i = 0; i < n; i++)
            c = par[c];
        // cout << c << ' ';
        vll ans;
        for (ll i = c;; i = par[i])
        {
            ans.pb(i);
            if (i == c && ans.size() > 1)
                break;
        }
        reverse(all(ans));
        for (auto nb : ans)
            cout << nb << ' ';
        exit(0);
    }
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, pair<ll, ll>>> edges(m);
    ll i, j;
    for (i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edges[i].fi = u;
        edges[i].se.fi = v;
        edges[i].se.se = w;
    }

    vll vis(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            bellmon(edges, vis, i, n, m);
        }
    }
    cout << "NO" << endl;
}
int main()
{
    FAST;
    ll t;
    t = 1;
    while (t--)
        solve();
}