#include<bits/stdc++.h>
using namespace std;
int v,e;

struct edge{
    int src;
    int des;
    int wt;
};

void bellman(vector<edge>Edge)
{
    int parent[v];
    vector<int>dist(v,INT_MAX);
    dist[0]=0;
    parent[0]=-1;
    for(int i=0; i<v-1; i++)
    {
        for(int j=0; j<e; j++)
        {
            int src=Edge[j].src;
            int des=Edge[j].des;
            int wt=Edge[j].wt;

            if(dist[src]!=INT_MAX && dist[src]+wt<dist[des])
            {
                dist[des]=dist[src]+wt;
                parent[des]=src;
            }
        }
    }
    
    for(int j=0; j<e; j++)
        {
            int src=Edge[j].src;
            int des=Edge[j].des;
            int wt=Edge[j].wt;

            if(dist[src]!=INT_MAX && dist[src]+wt<dist[des])
            {
               cout<<"Negative edge cycle\n";
               return;
            }
        }
    for(int j=1; j<v; j++)
    {
        vector<int>v;
        int a=j;
        while(parent[a]!=0)
        {
            v.push_back(a);
            a=parent[a];
        }
        v.push_back(a);
        cout<<0<<" "<<j<<" safe 0"<<" ";
        for(int k=v.size()-1; k>=0; k--)
        {
            cout<<v[k]<<" ";
        }
        cout<<endl;
    }

}

int main()
{
    cout<<"Enter the number of vertices\n";
    cin>>v;

    cout<<"Enter the number of edges\n";
    cin>>e;

    vector<edge>Edge(e);
    int src,des,wt;
    cout<<"Enter source, destination, weight\n";
    for(int i=0;i<e; i++)
    {
        cin>>src;
        cin>>des;
        cin>>wt;
        Edge[i].src=src;
        Edge[i].des=des;
        Edge[i].wt=wt;

    }
    bellman(Edge);
}