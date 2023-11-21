#include<bits\stdc++.h>
using namespace std;

int knap(vector<int>&w, vector<int>&p, int c)
{
    int n=p.size();
    int dp[n+1][c+1];

    for(int i=0; i<n+1; i++)
    {
        dp[i][0]=0;
    }
    for(int i=0; i<c+1; i++)
    {
        dp[0][i]=0;
    }

    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<c+1; j++)
        {
            if(j>=w[i-1]){
                dp[i][j]=max(p[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    for(int i=0;i<n+1; i++)
    {
        for(int j=0; j<c+1; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    int p1=n;
    int p2=c;
    vector<int>select;
    while(p2>0)
    {
        if(dp[p1][p2]==dp[p1-1][p2])
        {
            p1--;
        }
        else{
            p1--;
            select.push_back(p1);
            p2=p2-w[p2];
        }
    }
    cout<<"Items selected\n";
    for(int i=0;i<select.size(); i++)
    {
        cout<<select[i]<<" ";
    }
    cout<<"\nMax profit using 0/1: ";
    return dp[n][c];
}

int main()
{
    vector<int>p;
    vector<int>w;
    p.push_back(0);
    w.push_back(0);

    int n;
    cout<<"Enter the number of items in the bag: ";
    cin>>n;

    int c;
    cout<<"Enter the capacity of bag: ";
    cin>>c;

    for(int i=0; i<n; i++)
    {
        int pr,wt;
        cout<<"Enter the profit of item "<<i+1<<": ";
        cin>>pr;
        cout<<"Enter the weight of item "<<i+1<<": ";
        cin>>wt;

        p.push_back(pr);
        w.push_back(wt);
    }
    cout<<knap(w,p,c)<<endl;
}