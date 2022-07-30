#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ba back
#define ppb pop_back
#define eb emplace_back
#define sz(x) (int((x.size())))
#define all(x) (x).begin(), (x).end()
//#define for(i,x,n) for(i=x;i<n;i++)
#define bye exit(0)
#define FAST                           \
    ios_base ::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;
typedef long long int ll;
void ask(ll x, ll y)
{
    cout << "? " << x << ' ' << y << endl;
}
int main()
{
    ll left = 0, right = 1000;
    ll point = 0;
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        ask(mid, 0);
        string x;
        cin >> x;
        if (x == "YES")
        {
            point = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    left = 0;
    right = 1000;
    ll c = 0;
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        ll y = 0;
        ll l = 0;
        ll r = 1000;
        while (l <= r)
        {
            ll m = (l + r) / 2;
            ask(m, mid);
            string x;
            cin >> x;
            if (x == "YES")
            {
                y = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        if (y != point)
        {
            c = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    left = 0;
    right = 1000;
    ll h = 0;
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        ask(0, mid);
        string x;
        cin >> x;
        if (x == "YES")
        {
            h = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    left = 0;
    right = 1000;
    ll pp = 0;
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        ask(mid, c);
        string s;
        cin >> s;
        if (s == "YES")
        {
            left = mid + 1;
            pp = mid;
        }
        else
            right = mid - 1;
    }
    ll ans = 2 * point * c;
    ans += (h - c) * pp;
    cout << "! " << pp << endl;
}