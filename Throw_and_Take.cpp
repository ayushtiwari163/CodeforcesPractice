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
    //  cin >> n;
    vll a(n), val(n);
    ll i;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        cin >> val[i];
    vector<ll> odd;
    for (i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
            odd.pb(val[i]);
    }
    if (odd.size() == 0)
    {
        cout << 0 << endl;
        return;
    }
    n = odd.size();
    ll index = 0;
    ll turn = 0;
    ll alice = 0;
    ll bob = 0;
    // ll ans = 0;
    vector<ll> dp(n);
    dp[n - 1] = odd[n - 1];
    ll m = dp[n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        dp[i] = odd[i] - m;
        m = max(m, dp[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    // while (index < n)
    // {
    //     if (turn == 0)
    //     {
    //         // cout << alice << ' ' << bob << endl;
    //         ans = max(ans, alice - bob);
    //         ll next = dp[index];
    //         if (next == n)
    //         {
    //             if (a[index] % 2)
    //                 alice += val[index];
    //             break;
    //         }

    //         if (a[index] % 2 == 1 && val[index] > val[next])
    //         {
    //             alice += val[index];
    //             a[index]--;
    //         }
    //         else
    //         {
    //             alice += val[next];
    //             a[next]--;
    //             index = next;
    //         }
    //         turn = 1 - turn;
    //     }
    //     else
    //     {
    //         ll next = dp[index];
    //         if (next == n)
    //         {
    //             if (a[index] % 2)
    //                 bob += val[index];
    //             break;
    //         }

    //         if (a[index] % 2 == 1 && val[index] > val[next])
    //         {
    //             bob += val[index];
    //             a[index]--;
    //         }
    //         else
    //         {
    //             bob += val[next];
    //             a[next]--;
    //             index = next;
    //         }
    //         turn = 1 - turn;
    //     }
    //     // cout << alice << ' ' << bob << endl;
    // }
    // ans = max(ans, alice - bob);
    // cout << ans << endl;
    // cout << dp[0][0] << endl;
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