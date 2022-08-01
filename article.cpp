#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int check(vector<int> &seq)
{
    int n = seq.size();
    // if size is 0 then return 0
    if (n == 0)
        return 0;
    // if there is one element then return the first element
    if (n == 1)
        return seq[0];
    bool cond1 = true; // when elements are a1<a2>a3<a4..
    bool cond2 = true; // when elemnts are a1>a2<a3>a4...
    int temp = 0;
    int sum = seq[0];
    for (int i = 1; i < n; i++)
    {
        // check for alternate condition where it will false
        if (temp == 0 && seq[i - 1] >= seq[i])
            cond1 = false;
        if (temp == 1 && seq[i - 1] <= seq[i])
            cond1 = false;
        if (temp == 0 && seq[i - 1] <= seq[i])
            cond2 = false;
        if (temp == 1 && seq[i - 1] >= seq[i])
            cond2 = false;
        sum = sum + seq[i];
        temp = 1 - temp;
    }
    // if any of condition is true then return sum
    // otherwise 0
    if (cond1 || cond2)
        return sum;
    else
        return 0;
}
void recursive(vector<int> &a, int n, vector<int> &seq, int curr)
{
    // base case
    if (curr >= n)
    {
        int sum = check(seq);
        ans = max(sum, ans);
        return;
    }

    // transation
    // include the current element
    seq.push_back(a[curr]);
    recursive(a, n, seq, curr + 1);
    // not include the current element
    seq.pop_back();
    recursive(a, n, seq, curr + 1);
} // C++ code to find the maximum sum subsequence of an array that is increasing and decreasing alternately
#include <bits/stdc++.h>
using namespace std;

// Function for backtracking
int helper(int arr[], int maxSum[], int before[], int N, int root, int bef_root, int bbef_root)
{
    // Base case:
    if (bbef_root == -1)
    {
        int index = bef_root;
        return arr[index];
    }

    // Subsequence with alternate parts
    if ((arr[root] > arr[bef_root] && arr[bbef_root] > arr[bef_root]) || (arr[root] < arr[bef_root] && arr[bbef_root] < arr[bef_root]))
    {
        return arr[bef_root] + maxSum[bbef_root];
    }

    // Case when both are equal
    else
    {
        return helper(arr, maxSum, before, N, root, bef_root, before[bbef_root]);
    }
}

// Function to get result for the maximum sum subsequence
int getResult(int arr[], int N)
{
    // Contains maximum sum according to the input vector
    int maxSum[N];
    // vector to store the index of preceeding element
    int before[N];

    fill_n(&maxSum[0], N, 0);
    maxSum[0] = arr[0];
    before[0] = -1;

    // Traverse the array
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int currentMax = 0;
            if ((arr[i] > arr[j] && arr[before[j]] > arr[j]) || (arr[i] < arr[j] && arr[before[j]] < arr[j]) || before[j] == -1)
            {
                currentMax = (arr[i] == arr[j]) ? maxSum[j] : arr[i] + maxSum[j];
            }
            else if (arr[i] == arr[j])
            {
                // if both are equal then consider it only once
                currentMax = maxSum[j];
            }

            else
            {
                // Backtracking if three elements follow the order
                currentMax = arr[i] + helper(arr, maxSum, before, N, i, j, before[before[j]]);
            }
            if (currentMax >= maxSum[i])
            {
                maxSum[i] = currentMax;
                before[i] = j;
            }
        }
    }

    // Get max result
    return *max_element(maxSum, maxSum + N);
}

// Main function for finding the maximum sum subsequence that is increasing and decreasing alternatively
int main()
{
    int n;
    cin >> n;
    int input[n];
    for (int i = 0; i < n; i++)
        cin >> input[i];

    cout << getResult(input, n) << endl;
    return 0;
}
