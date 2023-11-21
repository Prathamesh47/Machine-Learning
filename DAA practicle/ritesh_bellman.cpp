#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int src;
    int dst;
    int wt;
};
int V, E;

void sort(vector<edge>Edge)
{
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V-1; j++)
        {
            if(Edge[j].src>Edge[j+1].src)
            {
                swap(Edge[j],Edge[j+1]);
            }
        }
    }
}

void bellmanford(vector<edge> Edge)
{
    int parent[V];
    // int costparent[V];
    vector<int> value(V, INT_MAX);
    value[0] = 0;
    parent[0] = -1;
    // costparent[0] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int src = Edge[j].src;
            int dst = Edge[j].dst;
            int wt = Edge[j].wt;
            if (value[src] != INT_MAX && value[src] + wt < value[dst])
            {
                value[dst] = value[src] + wt;
                parent[dst] = src;
                // costparent[dst] = value[dst];
            }
        }
    }

    for (int j = 0; j < E; j++)
    {
        int src = Edge[j].src;
        int dst = Edge[j].dst;
        int wt = Edge[j].wt;
        if (value[src] != INT_MAX && value[src] + wt < value[dst])
        {
            cout << "Negative edge cycle found !!!!!!" << endl;
            return;
        }
    }
    // for(int i=1;i<V;++i)
    //  cout<<"U->V: "<<parent[i]<<"->"<<i<<"  Cost to reach "<<parent[i]<<"from source 0 = "<<value[i]<<"\n";
    for (int i = 1; i < V; i++)
    {
        vector<int> v;
        int a = i;
        while (parent[a] != 0)
        {
            v.push_back(a);
            a = parent[a];
        }
        v.push_back(a);
        cout << " from 0 to " << i << " flow is 0 ";
        for (int j = v.size() - 1; j >= 0; j--)
        {
            cout << v[j] << " ";
        }
        cout << endl;
    }
}
// from 0 to 1 flow is 0 1
//  from 0 to 2 flow is 0 1 2
//  from 0 to 3 flow is 0 1 2 3
//  from 0 to 4 flow is 0 1 2 4
//  from 0 to 5 flow is 0 1 2 4 5

int main()
{
    cout << "Enter No.of vertices : " << endl;
    cin >> V;
    cout << "Enter No.of edges : " << endl;
    cin >> E;
    vector<edge> Edge(E);
    int src, dst, wt;
    for (int i = 0; i < E; i++)
    {
        cout << "Enter src,dst,wt : " << endl;
        cin >> src >> dst >> wt;
        Edge[i].src = src;
        Edge[i].dst = dst;
        Edge[i].wt = wt;
    }
    // sort(Edge.begin(), Edge.end(), [](const edge &a, const edge &b)
    //      { return a.src < b.src; });
    sort(Edge);

    bellmanford(Edge);

    return 0;
}