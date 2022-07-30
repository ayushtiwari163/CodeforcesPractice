#include <bits/stdc++.h>
using namespace std;
// function to find heaters range
int range_heaters(int houses[], int heaters[], int n, int m)
{
    int distance[n] = {INT_MAX};
    for (int i = 0; i < n; i++)
    {
        int right_heater = INT_MAX;
        int left_heater = INT_MAX;
        for (int j = 0; j < m; j++)
        {
            // for left heaters
            if (heaters[j] <= houses[i])
                left_heater = min(left_heater, houses[i] - heaters[j]);
            // for right heaters
            if (heaters[j] > houses[i])
                right_heater = min(right_heater, heaters[j] - houses[i]);
        }
        distance[i] = min(right_heater, left_heater);
    }
    int ans = *max_element(distance, distance + n);
    return ans;
}
// driver code
int main()
{
    int n, m; // size of houses and heaters array
    cin >> n >> m;
    int houses[n], heaters[n];
    for (int i = 0; i < n; i++)
        cin >> houses[i];
    for (int i = 0; i < m; i++)
        cin >> heaters[i];
    int ans = range_heaters(houses, heaters, n, m);
    cout << "Heaters Range: " << ans << endl;
}