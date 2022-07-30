#include <bits/stdc++.h>
using namespace std;
/*  function to returns minimum removals needed
 to make a mountain array */
int minMountainRemovals(vector<int> &a)
{
    /*  Declaring two dp vectors to store the maximum result for any indexing
        from left and right respectively */
    int n = a.size();
    vector<int> dpleft(a.size(), 1);
    vector<int> dpright(a.size(), 1);
    // vector<int> dpleft,dpright;
    /* declaring temporary vector lis
    it will help us to fill dpleft and dpright in nlongn complexity */
    vector<int> lis;
    // filing dpleft using lis in nlogn
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);
        // if element is to be inserted in lis
        if (it != lis.end())
        {
            int idx = it - lis.begin();
            lis[idx] = a[i];
            dpleft[i] = idx + 1;
        }
        // if element in not present in lis insert at the end
        else
        {
            lis.push_back(a[i]);
            dpleft[i] = lis.size();
        }
    }
    // clearing lis vector to use to calculate right lis
    lis.clear();
    // reversing the original vector to calculate lis from back
    reverse(a.begin(), a.end());
    // filling dpright
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);
        if (it != lis.end())
        {
            int idx = it - lis.begin();
            lis[idx] = a[i];
            dpright[i] = idx + 1;
        }
        // if element in not present in lis insert at end
        else
        {
            lis.push_back(a[i]);
            dpright[i] = lis.size();
        }
    }
    int longest = 0;
    // for every index check for longest mountain array,
    for (int i = 1; i < a.size() - 1; i++)
    {
        if (dpleft[i] > 1 && dpright[i] > 1)
        {
            int ans = dpleft[i] + dpright[i] - 1;
            longest = max(longest, ans);
        }
    }
    // returning removals
    return a.size() - longest;
}
int main()
{
    int n;
    cin >> n;
    // taking input for array size
    vector<int> a(n, 0);
    // Taking array input as vector
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // calling minMountainRemovals function to return minimum number of       removals
    int removals = minMountainRemovals(a);
    cout << removals << endl;
    return 0;
}
