#include <bits/stdc++.h>
using namespace std;

// Box class used to define height, weight, depth of the box
class Box
{
public:
  int h, w, d;
};

// To get minimum of two numbers
int min(int x, int y)
{
  return (x < y) ? x : y;
}

// To get maximum of two numbers
int max(int x, int y)
{
  return (x > y) ? x : y;
}

// Comparator function
int compare(const void *a, const void *b)
{
  return ((*(Box *)b).d * (*(Box *)b).w) - ((*(Box *)a).d * (*(Box *)a).w);
}

// To get result
int getResult(Box arr[], int n)
{
  // 'Temp' array to store the dimensions of all three rotations
  Box temp[3 * n];
  int index = 0;
  for (int i = 0; i < n; i++)
  {
    // Copy the original box
    temp[index].h = arr[i].h;
    temp[index].d = max(arr[i].d, arr[i].w);
    temp[index].w = min(arr[i].d, arr[i].w);
    index++;

    // First rotation of box
    temp[index].h = arr[i].w;
    temp[index].d = max(arr[i].h, arr[i].d);
    temp[index].w = min(arr[i].h, arr[i].d);
    index++;

    // Second rotation of box
    temp[index].h = arr[i].d;
    temp[index].d = max(arr[i].h, arr[i].w);
    temp[index].w = min(arr[i].h, arr[i].w);
    index++;
  }

  // change the size to thrice the size of the box
  n = 3 * n;

  // Sort the array
  qsort(temp, n, sizeof(temp[0]), compare);

  // Array to store all the results at each stage/ level
  int msh[n];
  for (int i = 0; i < n; i++)
  {
    msh[i] = temp[i].h;
  }

  // Optimized MSH
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (temp[i].w < temp[j].w && temp[i].d < temp[j].d && msh[i] < msh[j] + temp[i].h)
      {
        msh[i] = msh[j] + temp[i].h;
      }
    }
  }
  // maximum value of MSH
  int max = -1;
  for (int i = 0; i < n; i++)
  {
    if (max < msh[i])
    {
      max = msh[i];
    }
  }
  return max;
}

/* Driver program to test above function */
int main()
{
  Box arr[] = {{4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32}};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "The maximum possible height of stack is ";
  cout << getResult(arr, n) << endl;

  return 0;
}
