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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll i;
    ll p = k;
    vll ans(n);
    string temp = s;
    if (k % 2)
    {
        for (i = 0; i < n; i++)
        {
            if (k > 0)
            {
                if (s[i] == '0')
                {
                    ans[i] = 0;
                    s[i] = '1';
                }
                else
                {
                    ans[i] = 1;
                    k--;
                }
            }
            else
            {
                for (ll j = i; j < n; j++)
                {
                    if (s[j] == '0')
                        s[j] = '1';
                    else
                        s[j] = '0';
                }
                cout << s << endl;
                for (auto nb : ans)
                    cout << nb << ' ';
                cout << endl;
                return;
            }
        }
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            if (k > 0)
            {
                if (s[i] == '1')
                {
                    ans[i] = 0;
                    // s[i] = '1';
                }
                else
                {
                    ans[i] = 1;
                    s[i] = '1';
                    k--;
                }
            }
            else
            {
                cout << s << endl;
                for (auto nb : ans)
                    cout << nb << ' ';
                cout << endl;
                return;
            }
        }
    }
    if (k == 0)
    {
        cout << s << endl;
        for (auto nb : ans)
            cout << nb << ' ';
        cout << endl;
        return;
    }
    ans[n - 1] += k;
    s[n - 1] = temp[n - 1];
    p = p - ans[n - 1];
    // cout << p << endl;
    if (p % 2)
    {
        if (s[n - 1] == '0')
            s[n - 1] = '1';
        else
            s[n - 1] = '0';
    }

    cout << s << endl;
    for (auto nb : ans)
        cout << nb << ' ';
    cout << endl;
    return;
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