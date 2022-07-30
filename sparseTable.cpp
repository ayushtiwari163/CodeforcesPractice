#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
class SparseTable
{
private:
    vector<vector<int>> dp;
    ll n;

public:
    SparseTable(vector<ll> a)
    {
        n = a.size();
        dp.resize(a.size());
        for (ll i = 0; i < a.size(); i++)
        {
            dp[i].resize(32, 0);
            dp[i][0] = a[i];
        }
    }
    ll getFirstSetBitPos(ll n)
    {
        ll x = (ll)(log2(n));

        return x;
    }
    void constructTable()
    {
        ll i, j;
        for (i = 1; i < 31; i++)
        {
            ll length = (1 << i);
            // cout << length << ' ';

            for (j = 0; j <= n - length; j++)
            {
                dp[j][i] = __gcd(dp[j][i - 1], dp[j + length / 2][i - 1]);
                // cout << dp[j][i] << ' ';
            }
            cout << endl;
        }
    }
    ll query(ll l, ll r)
    {
        ll length = r - l + 1;
        ll x = getFirstSetBitPos(length);
        // cout << x << ' ';
        ll val = (1 << x);
        // cout << val << endl;
        return __gcd(dp[l][x], dp[r - val + 1][x]);
        // return x;
    }
};
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    SparseTable obj(a);
    obj.constructTable();
    cout << obj.query(0, 2);
}