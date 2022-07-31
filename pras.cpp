#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll i;
    for (i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;

    for (i = 0; i < n; i++)
    {
        if (i % 2)
            ans -= a[i];
        else
            ans += a[i];
    }
    ll sum = 0;
    vector<ll> dp(n);
    dp[0] = a[0];
    sum = a[0];
    for (i = 1; i < n; i++)
    {
        if (i % 2)
            sum -= a[i];
        else
            sum += a[i];
        dp[i] = sum;
    }
    ll len = 0;
    sum = 0;
    for (i = n - 1; i >= 0; i--)
    {
        len++;
        if (i % 2)
            sum = sum + a[i];
        else
            sum = sum - a[i];
        if (len % 2 == 0)
        {
            ll x;
            if (i == 0)
                x = 0;
            else
                x = dp[i - 1];
            ans = max(ans, x + sum);
        }
    }
    cout << ans << endl;
}