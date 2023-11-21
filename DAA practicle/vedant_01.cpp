
#include<bits/stdc++.h>
using namespace std;

int knaps(vector<int> profit, vector<int>weight,int c){
    int n;
    n = profit.size();
    int dp[n+1][c+1];
    for(int i=0; i<n+1 ; i++){
        dp[i][0] = 0;
    }
    for(int i=0; i<c+1 ; i++){
        dp[0][i] = 0;
    }
    for (int i = 1; i < n+1; i++)
    {
        for(int j  = 1 ; j < c+1 ; j++){
            if(j>=weight[i-1]){
                dp[i][j] = max(profit[i-1] + dp[i-1][j-weight[i-1]], dp[i-1][j]);
                }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<endl;
    for(int i = 0; i<=n;i++){
        for(int j =0; j <= c; j++){
            cout << dp[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout <<endl;
    int p1 = n; 
    int p2 = c;
    vector<int> select;
    while(p2 > 0){
        if(dp[p1][p2] == dp[p1-1][p2]){
            p1--;
        }
        else{
            p1--;
            select.push_back(p1);
            p2 = p2 - weight[p1];
        }
    }
    cout<<"Items selected : "<<endl;
    for(int i=0;i<select.size();i++){
        cout<<select[i]<<", ";
    }
    cout<<endl;
    cout << "Max Profit Using 0/1: ";
    return dp[n][c];
}
int main(){
    vector<int>p;
    vector<int>w;
    p.push_back(0);
    w.push_back(0);
    int n,c;
    cout << "Enter number of items\n ";
    cin >> n;
    cout << "Enter size of bag\n";
    cin >> c;
    for (int i = 0; i < n; i++)
    {
        int we, pi;
        cout << "Enter weight of item:\n";
        cin >> we;
        cout << "Enter profit of item: \n";
        cin >> pi;
        p.push_back(pi);
        w.push_back(we);
    }
    cout << knaps(p,w,c)<<endl;
    return 0;
}