#include<bits/stdc++.h>
using namespace std;


void printQueen(vector<vector<char>>&v)
{
    int n=v.size();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------------------\n";
}

bool isSafe(int col,int row,vector<vector<char>>&v)
{
    for(int i=0; i<row; i++)
    {
        if(v[i][col]=='Q')
        {
            return false;
        }
    }
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--,j-- )
    {
        if(v[i][j]=='Q')
        {
            return false;
        }
    }
    for(int i=row-1, j=col+1; i>=0 && j<v.size(); i--,j++ )
    {
        if(v[i][j]=='Q')
        {
            return false;
        }
    }
    return true;
}

void queen(int row,vector<vector<char>>&v)
{
    int n=v.size();
    if(row==n)
    {
        cout<<"solution \n";
        printQueen(v);
        return;
    }
    for(int i=0; i<v.size(); i++)
    {
        if(isSafe(i,row,v))
        {
            v[row][i]='Q';
            printQueen(v);
            queen(row+1,v);
            cout<<"Backtrack\n";
            printQueen(v);
            v[row][i]='.';
        }
    }
}   

int main()
{
    int n;
    cout<<"Enter the dimension of chess board"<<endl;
    cin>>n;

    vector<vector<char>>v(n,vector<char>(n,'.'));
    if(n<4)
    {
        cout<<"Enter valid number \n";
    }
    queen(0,v);
    
    return 0;
}