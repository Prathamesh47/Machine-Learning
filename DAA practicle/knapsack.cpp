#include<bits/stdc++.h>
using namespace std;

struct prod{
    float wt,pr,pw;
};

int partition(prod arr[],int start,int end)
{
    float pivot=arr[end].pw;
    int i=start-1;

    for(int j=start; j<=end-1; j++)
    {
        if(arr[j].pw>=pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[end]);
    return i+1;
}

void quick(prod arr[],int start,int end)
{
    if(start<end)
    {
        int pivot=partition(arr,start,end);
        quick(arr,start,pivot-1);
        quick(arr,pivot+1,end);
    }
}

void item(prod arr[],int n,int bag)
{
    float xiwi=0,xipi=0;
    float x[n]={0};

    int bagsize=bag;

    for(int i=0; i<n; i++)
    {
        if(bagsize>0){
            if(bagsize>=arr[i].wt)
            {
                x[i]=1;
                bagsize-=arr[i].wt;
            }
            else{
                x[i]=bagsize/arr[i].wt;
                break;
                bag=0;
            }
        }
        
    }

    for(int i=0;i<n; i++)
    {
        xiwi+=arr[i].wt*x[i];
        cout<<"Weight of selected item is "<<arr[i].wt*x[i]<<endl;
        xipi+=arr[i].pr*x[i];
        cout<<"Profit of selected item is "<<arr[i].pr*x[i]<<endl;
    }

    cout<<"Total weight of selected items is: "<<xiwi<<endl;
    cout<<"Remaining weight of selected item is: "<<bag-xiwi<<endl;
    cout<<"Total Profit of selected items is: "<<xipi<<endl;
    
}

int main()
{
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;
    cout<<"\n";

    int bag;
    cout<<"Enter the bag size: ";
    cin>>bag;
    cout<<"\n";

    prod arr[n];

    cout<<"Enter the profit of each item.\n";
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr[i].pr=x;
    }
    cout<<"Enter the weight of each item.\n";
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr[i].wt=x;
    }
    for(int i=0; i<n; i++)
    {
        arr[i].pw=arr[i].pr/arr[i].wt;
    }

    quick(arr,0,n-1);
    cout<<"After sorting the profit/weight array: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i].pw<<" ";
    }
    cout<<"\n";
    cout<<"After sorting the profit array: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i].pr<<" ";
    }
    cout<<"\n";
    cout<<"After sorting the weight array: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i].wt<<" ";
    }
    cout<<"\n";
    item(arr,n,bag);
    return 0;
}