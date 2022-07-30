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

vll next_greater(vll &a, ll n)
{
    vll ans(n, n);
    stack<ll> s;
    ll i;
    for (i = 0; i < n; i++)
    {
        while (!s.empty() && a[i] > a[s.top()])
        {
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return ans;
}
vll prev_greater(vll &a, ll n)
{
    vll ans(n, -1);
    stack<ll> s;
    ll i;
    for (i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && a[i] > a[s.top()])
        {
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return ans;
}
vll seg;
void build(ll ind, ll low, ll high, vll &a)
{
    if (low == high)
    {
        seg[ind] = a[low];
        return;
    }
    ll mid = (low + high) / 2;
    build(2 * ind + 1, low, mid, a);
    build(2 * ind + 2, mid + 1, high, a);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}
ll get_max(ll ind, ll low, ll high, ll l, ll r)
{
    if (low >= l && high <= r)
        return seg[ind];
    if (high < l || low > r)
        return -inf;
    ll mid = (low + high) / 2;
    ll left = get_max(2 * ind + 1, low, mid, l, r);
    ll right = get_max(2 * ind + 2, mid + 1, high, l, r);
    return max(left, right);
}
void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    ll i;
    for (i = 0; i < n; i++)
        cin >> a[i];
    //    build(0,0,n-1,a);
    vll prefix(n);
    prefix[0] = a[0];
    for (i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + a[i];
    vll suffix(n);
    suffix[n - 1] = a[n - 1];
    for (i = n - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] + a[i];
    seg.resize(4 * n, 0);
    build(0, 0, n - 1, prefix);
    vll next = next_greater(a, n);
    for (i = 0; i < n; i++)
    {
        ll l = i;
        ll r = next[i] - 1;
        ll mx = get_max(0, 0, n - 1, l, r);
        ll cost = mx - (i == 0 ? 0 : prefix[i - 1]);
        // cout << cost << ' ';
        if (cost > a[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    seg.resize(4 * n, 0);
    build(0, 0, n - 1, suffix);
    next = prev_greater(a, n);
    // for (i = n - 1; i >= 0; i--)
    //     cout << a[i] << ' ' << next[i] << endl;
    for (i = n - 1; i >= 0; i--)
    {
        ll r = i;
        ll l = next[i] + 1;
        ll mx = get_max(0, 0, n - 1, l, r);
        ll cost = mx - (i == n - 1 ? 0 : suffix[i + 1]);
        // cout << mx << ' ';
        if (cost > a[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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