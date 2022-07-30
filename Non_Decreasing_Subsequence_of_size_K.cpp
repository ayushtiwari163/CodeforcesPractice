// C++ code for Distance from Next Greater element
#include <bits/stdc++.h>
using namespace std;

vector<int> distance_from_next_greater(vector<int> a)
{
    int n = a.size();
    // for storing the answer
    vector<int> ans(n);
   
  // stack pair to store the value of element and index of the element
    stack<pair<int, int>> st;
   
    // for last element the answer is always zero
    ans[n - 1] = 0;

    // pushing the last element in the stack
    st.push({a[n - 1], n - 1});

    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < st.top().first)
        {
            // storing answer for a[i]
            ans[i] = st.top().second - i;
            // pushing the value a[i] and
            // the index i in the stack
            st.push({a[i], i});
        }
        else
        {
            while (st.empty()==false && a[i] >= st.top().first)
            {
                // popping elements till a[i] is
                // greater than the top element of
                // the stack
                st.pop();
            }
            if (!st.empty())
            {
                // if the stack is not empty repeating
                // the above process
                ans[i] = st.top().second - i;
                st.push({a[i], i});
            }
            else
            {
                // else the answer for a[i] is zero
                st.push({a[i], i});
                ans[i] = 0;
            }
        }
    }

    return ans;
}

// Driver code
int main()
{
    vector<int> arr = {9, 1, 9, 10, 2, 3};

    vector<int> ans = distance_from_next_greater(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
