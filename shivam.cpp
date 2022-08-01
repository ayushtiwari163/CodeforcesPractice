#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll floorSqrt(ll x)
{
    if (x == 0 || x == 1)
        return x;

    ll start = 1, end = x / 2, ans;
    while (start <= end)
    {
        ll mid = (start + end) / 2;

        int sqr = mid * mid;
        if (sqr == x)
            return mid;
        if (sqr <= x)
        {
            start = mid + 1;
            ans = mid;
        }
        else
            end = mid - 1;
    }
    return ans;
}
ll numOfSubarrays(vector<ll> &arr)
{
    ll odd = 0, even = 0, answer = 0;
    for (auto number : arr)
    {
        if (number % 2 == 0)
            even++;
        else
        {
            swap(odd, even);
            odd++;
        }
        answer = answer + odd;
    }
    return answer;
}
ll divisiors(vector<ll> &a, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        ll x = floorSqrt(a[i]);
        if (x * x == a[i])
            a[i] = 1;
        else
            a[i] = 0;
    }
    return numOfSubarrays(a);
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    cout << divisiors(a, n) << endl;
}