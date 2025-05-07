//Knapsack
#include<iostream>
#include<math.h>
using namespace std;
int mp = 0,count = 0;
int sob[100],x[100];

void Knapsack(int n,int m,int v[],int w[],int ci,int cw,int cv)
{
    if(ci == n || cw == m)
    {
        if(cv>mp)
        {
            mp = cv;
            for(int i=0;i<n;i++)
            {
                sob[i] = x[i];
            }
            return ;
        }
    }
    int ub = int(cv + (m-cw)*(float)(v[ci])/(float)(w[ci]));
    if(ub<=mp)
        return;
    if(cw+w[ci]<=m)
    {
        count++;
        x[ci] = 1;
        Knapsack(n,m,v,w,ci+1,cw+w[ci],cv+v[ci]);
    }
    x[ci] = 0;
    Knapsack(n,m,v,w,ci+1,cw,cv);
    count++;
    return;
}
int main()
{
    int n;
    cout<<"Enter total no of items : ";
    cin>>n;

    int v[n],w[n],M;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Weight and Value of Item "<<i+1<<" : ";
        cin>>w[i]>>v[i];
    }

    cout<<"Enter the Maximum Weight : ";
    cin>>M;

    Knapsack(n,M,v,w,0,0,0);
    cout<<"******* Items Selected *******"<<endl;
    for(int i=0;i<n;i++)
    {
        if(sob[i])
            cout<<i+1<<"\t"<<w[i]<<"\t"<<v[i]<<endl;
    }
    cout<<"Maximum Price : "<<mp<<endl;
    cout<<"Count : "<<count<<endl;
    cout<<"Total No.of Nodes in State space tree : "<<pow(2,n)-1<<endl;
}
