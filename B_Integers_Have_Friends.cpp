#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1000000000000000000

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int d[n];
        for (int i = 0; i < n - 1; i++)
        {
            d[i] = abs(a[i] - a[i + 1]);
        }
        d[n - 1] = 1;
        int dp[n][21];
        for (int i = 0; i < n; i++)
            dp[i][0] = d[i];
        for (int j = 1; j < 21; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (i + (1 << (j - 1)) >= n)
                    dp[i][j] = dp[i][j - 1];
                else
                    dp[i][j] = gcd(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int p = i, g = 0;
            for (int j = 20; j >= 0; j--)
            {
                if (p == n)
                    break;
                if (gcd(g, dp[p][j]) != 1)
                {
                    g = gcd(g, dp[p][j]);
                    p = min(p + (1 << j), n);
                }
            }
            ans = max(ans, p - i);
        }
        cout << ans + 1 << '\n';
    }
    return 0;
}
