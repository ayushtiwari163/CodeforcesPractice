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
// Function to print sum of 2 numbers
// without propagating carry
ll printSum(ll a, ll b)
{
    ll res = 0;

    ll temp1 = 0, temp2 = 0;

    // Reverse a
    while (a)
    {
        temp1 = temp1 * 10 + (a % 10);
        a /= 10;
    }
    a = temp1;

    // Reverse b
    while (b)
    {
        temp2 = temp2 * 10 + (b % 10);
        b /= 10;
    }
    b = temp2;

    // Generate sum
    // Since length of both a and b are same,
    // take any one of them.
    while (a)
    {
        // Extract digits from a and b and add
        int sum = (a % 10 + b % 10);

        // If sum is single digit
        if (sum / 10 == 0)
            res = res * 10 + sum;
        else
        {
            // If sum is not single digit
            // reverse sum
            temp1 = 0;
            while (sum)
            {
                temp1 = temp1 * 10 + (sum % 10);
                sum /= 10;
            }
            sum = temp1;

            // Extract digits from sum and append
            // to result
            while (sum)
            {
                res = res * 10 + (sum % 10);
                sum /= 10;
            }
        }

        a /= 10;
        b /= 10;
    }

    return res;
}
void solve()
{

    string a, s;
    string res;
    cin >> a >> s;

    ll n = a.size();
    ll m = s.size();

    ll i;
    if (a == s)
    {
        cout << 0 << endl;
        return;
    }
    // if (m < n)
    // {
    //     cout << -1 << endl;
    //     return;
    // }

    ll j;
    i = n - 1;
    j = m - 1;
    while (i >= 0 && j >= 0)
    {
        ll x = a[i] - '0';
        ll y = s[j] - '0';
        // cout << x << ' ' << y << endl;

        if (x > y)
        {
            // cout << i << ' ' << j << endl;
            if (j > 0 && s[j - 1] == '1')
            {
                ll val = 10 - a[i] + s[j];
                res.pb(val + '0');
            }
            else
            {
                cout << -1 << endl;
                return;
            }
            j = j - 2;
            i--;
        }
        else
        {
            ll p = y - x;
            //  cout << p << ' ';
            res.pb(p + '0');
            i--;
            j--;
        }
    }
    // cout << i << ' ';
    if (i >= 0)
    {

        cout << -1 << endl;
        return;
    }
    for (j; j >= 0; j--)
    {
        res.pb(s[j]);
    }
    i = 0;
    reverse(all(res));

    while (res[i] == '0')
        i++;
    for (i; i < res.size(); i++)
        cout << res[i];
    cout << endl;
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