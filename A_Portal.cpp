// これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました
//ジャイシュリーラム
#include <bits/stdc++.h>
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
ll ivalue(string s)
{
    ll x = 0;
    stringstream obj(s);
    obj >> x;
    return x;
}
const ll M = 1e9 + 7;
const ll N = 1e5 + 5;
const int inf = INT_MAX;
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

vector<vector<int>> dp(401, vector<int>(401));
ll cost_1(int x1, int y1, int x2, int y2)
{
    int dec1 = 0;
    if (x1 != 0)
        dec1 = dp[x1 - 1][y2];
    int dec2 = 0;
    if (y1 != 0)
        dec2 = dp[x2][y1 - 1];
    int add = 0;
    if (x1 != 0 && y1 != 0)
        add = dp[x1 - 1][y1 - 1];
    // cout << dec1 << ' ' << dec2 << ' ' << add << ' ' << dp[x2][y2] << ' ';
    int zeros = dp[x2][y2] - dec1 - dec2 + add;
    return zeros;
}
int cost_0(int x1, int y1, int x2, int y2)
{
    int dec1 = 0;
    if (x1 != 0)
        dec1 = dp[x1 - 1][y2];
    int dec2 = 0;
    if (y1 != 0)
        dec2 = dp[x2][y1 - 1];
    int add = 0;
    if (x1 != 0 && y1 != 0)
        add = dp[x1 - 1][y1 - 1];
    int zeros = dp[x2][y2] - dec1 - dec2 + add;
    int cells = (x2 - (x1 - 1)) * (y2 - (y1 - 1));
    // cout << cells << ' ';
    return cells - zeros;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    int i, j;
    vector<string> s(n);
    for (i = 0; i < n; i++)
        cin >> s[i];
    // for (i = 0; i < n; i++)
    // {
    //     for (j = 0; j < n; j++)
    //         dp[i][j] = 0;
    // }
    if (s[0][0] == '0')
        dp[0][0] = 1;
    // for (i = 1; i < m; i++)
    // {
    //     if (s[0][i] == '0')
    //         dp[0][i] = dp[0][i - 1] + 1;
    //     else
    //         dp[0][i] = dp[0][i - 1];
    // }
    // for (i = 1; i < n; i++)
    // {
    //     if (s[i][0] == '0')
    //         dp[i][0] = dp[i - 1][0] + 1;
    //     else
    //         dp[i][0] = dp[i - 1][0];
    // }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                continue;
            if (i == 0)
            {
                if (s[0][j] == '0')
                    dp[0][j] = dp[0][j - 1] + 1;
                else
                    dp[0][j] = dp[0][j - 1];
            }
            else if (j == 0)
            {
                if (s[i][0] == '0')
                    dp[i][0] = dp[i - 1][0] + 1;
                else
                    dp[i][0] = dp[i - 1][0];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
                if (s[i][j] == '0')
                    dp[i][j]++;
            }
        }
    }
    int ans = inf;

    //  cout << cost_0(1, 1, 3, 2) << ' ';
    for (int row1 = 0; row1 < n; row1++)
    {
        for (int row2 = row1 + 4; row2 < n; row2++)
        {
            // vector<int> temp(m + 1, inf);
            int prev = inf;
            for (int col2 = 3; col2 < m; col2++)
            {
                // exctly 4;
                int col1 = col2 - 3;
                int cost1 = cost_1(row1, col1 + 1, row1, col2 - 1) + cost_1(row1 + 1, col2, row2 - 1, col2) + cost_1(row2, col1 + 1, row2, col2 - 1) + cost_1(row1 + 1, col1, row2 - 1, col1);
                int val1 = cost_0(row1 + 1, col1 + 1, row2 - 1, col2 - 1) + cost1;
                if (col2 == 3)
                {
                    prev = val1;
                    // temp[col2] = val1;
                    // ans = min(ans, temp[col2]);
                    ans = min(ans, prev);
                    // cout << cost_0(row1 + 1, col1 + 1, row2 - 1, col2 - 1) << endl;
                    continue;
                }
                // greater then 4
                int cost2 = cost_1(row1 + 1, col2, row2 - 1, col2) + cost_0(row1 + 1, col2 - 1, row2 - 1, col2 - 1) - cost_1(row1 + 1, col2 - 1, row2 - 1, col2 - 1);
                int p = cost_1(row1, col2 - 1, row1, col2 - 1) + cost_1(row2, col2 - 1, row2, col2 - 1);
                int val2 = prev + cost2 + p;
                prev = min(val1, val2);
                ans = min(ans, prev);
            }
        }
        // cout << ans << endl;
    }
    cout << ans << endl;
}
int main()
{
    FAST;
    int t;
    t = 1;
    cin >> t;
    while (t--)
        solve();
}