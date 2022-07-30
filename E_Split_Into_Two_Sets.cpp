#include <bits/stdc++.h>
using namespace std;
int answer(vector<int> &arr, int n, int x)
{
    map<int, int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;
    vector<int> temp;
    for (auto nb : m)
    {
        temp.push_back(nb.second);
    }
    sort(temp.begin(), temp.end());
    reverse(temp.begin(), temp.end());
    int ans = 0;
    for (int i = 0; i < temp.size() && x >= 0; i++)
    {
        ans = ans + temp[i];
        x--;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int x;
    cin >> x;
    cout << answer(arr, n, x);
}