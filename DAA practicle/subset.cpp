#include<bits\stdc++.h>
using namespace std;

void sub(int i,int n, int target,vector<int>&subset,int arr[])
{
    if(target==0)
    {
        cout<<"[ ";
        for(int i=0; i<subset.size(); i++)
        {
            cout<<subset[i]<<" ";
        }
        cout<<"]";
        return;
    }
    if(i==n)
    {
        return;
    }
    sub(i+1,n,target,subset,arr);
    if(arr[i]<=target)
    {
        subset.push_back(arr[i]);
        sub(i+1,n,target-arr[i],subset,arr);
        subset.pop_back();
    }
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"\n";

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int target;
    cout<<"Enter the target sum:";
    cin>>target;

    vector<int>subset;
    sub(0,n,target,subset,arr);
    return 0;
}