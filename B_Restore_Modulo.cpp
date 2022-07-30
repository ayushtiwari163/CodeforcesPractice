
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
vll dp1(1000, 0), dp2(1000, 0);
vll x, y;
ll m1, m2;
void solve2(vll a, vll prefix)
{
    ll i;
    ll sum1;
    ll sum2;
    for (i = 1; i <= (ll)a.size(); i++)
    {
        sum1 = a[i - 1] * m1;
        sum2 = a[i - 1] * m2;
        sum1 += dp1[i - 1];
        sum2 += dp2[i - 1];
        if (sum1 <= sum2)
        {
            dp1[i] = sum1, dp2[i] = dp2[i - 1];
            x.push_back(a[i - 1]);
        }
        else
        {
            dp2[i] = sum2;
            dp1[i] = dp1[i - 1];
            y.push_back(a[i - 1]);
        }
    }
}
void solve()
{
    ll n, a, b;
    string s, t;
    cin >> m1 >> m2 >> n;
    vll arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<int>());
    ll i;
    vll prefix(n + 1);
    for (i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + arr[i];
    solve2(arr, prefix);
    for (auto nb : x)
        cout << nb << ' ';
    cout << endl;
    for (auto nb : y)
        cout << nb << ' ';
}
int main()
{
    FAST;
    ll t;
    t = 1;
    while (t--)
        solve();
}