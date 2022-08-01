// C++ programs to find two non-overlapping
// pairs having equal sum in an Array

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef pair<int, int> Pair;

// Function to find two non-overlapping
// with same sum in an array
void findPairs(int arr[], int n)
{
	// first create an empty map
	// key -> which is sum of a pair of
	// elements in the array
	// value -> vector storing index of
	// every pair having that sum
	unordered_map<int, vector<Pair> > map;

	// consider every pair (arr[i], arr[j])
	// and where (j > i)
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {

			// calculate sum of current pair
			int sum = arr[i] + arr[j];

			// if sum is already present in the map
			if (map.find(sum) != map.end()) {

				// check every pair having equal sum
			 pair<long long ,long long> pp=map[sum];
                unordered_set <long long> s={i,j,pp.first,pp.second};
                if(s.L!=4) continue;
                cout<<"Yes"<<nl;
                cout<<pp.first+1<<" "<<pp.second+1<<" "<<i+1<<" "<<j+1<<endl;
                return 0;
				}
			}

			// Insert current pair into the map
			map[sum].push_back({ i, j });
		}
	}

	// If no such pair found
	cout << "NO";
}

// Driver Code
int main()
{
    int n;
    cin>>n;
	int a[n];
    int i;
    for(i=0;i<n;i++)
    cin>>a[i];
	//int size = sizeof(arr) / sizeof(arr[0]);

	findPairs(a, n);

	return 0;
}
