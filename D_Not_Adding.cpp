#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> zero_sum(vector<int> &nums,int n)
{
    int i,j,k; // for indexing
    vector<vector<int>> ans;
    for(int i=0;i<n;i++);
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                ans.push_back({nums[i],nums[j],nums[k]});
            }
        }
    }
}
int main()
{
    int n; // length of array
    cin>>n;
    vector<int> nums(n);// vector of length n
    // take vector element input from user
    for(int i=0;i<n;i++) cin>>nums[i];
    // call function zero_sum;
    vector<vector<int>> ans=zero_sum(nums,n);

}