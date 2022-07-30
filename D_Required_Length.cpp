#include <bits/stdc++.h>
using namespace std;
// function to find all unique triplets
vector<vector<int>> findTriplets(int arr[], int n, int sum)
{
    sort(arr, arr + n);
    // A 2D vector to store the result.

         vector<vector<int>> result;
    for ( int i = 0; i < n - 2; i++)
    {
        int start = i + 1;
        int end = n - 1;

                    //calculating new target sum after subtracting the fixed one from the old target.
            int new_target = sum - arr[i];
        while (start < end)
        {

                        //checking if previous value is same as current value.
                if (start > i + 1 && arr[start] == arr[start - 1])
            {
                start++;
                continue;
            }
            if (end < n - 1 && arr[end] == arr[end + 1])
            {
                end--;
                continue;
            }

                            //if the sum is equal to the target then push it into the result.
                if (new_target == arr[start] + arr[end])
            {
                result.push_back({arr[i], arr[start], arr[end]});
                Start++;
                end--;
            }
            else if (new_target > arr[start] + arr[end])
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }
    return result;
}
int main()
{

         int arr[] = {15, 5, 10, 5, 10};

         int n = sizeof(arr) / sizeof(a[0]);

         int sum = 25;

          //2D vector to store the result.

      vector<vector<int>> result =  findTriplets(arr, n, sum);

         if (result.size() == 0)

      cout <<”No such triplet exists” << endl;

         for (int i = 0; i < result.size(); i++)
    {

                  cout << result[i][0] <<” ”<< result[i][1] <<” ”<< result[i][2] << endl;

             
    }

         return 0;
}