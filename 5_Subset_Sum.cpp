//Subset Sum
#include<iostream>
#include<math.h>
using namespace std;
int count = 0;
int d=0;
int x[100],a[100];

void subset(int s,int k,int ts)
{
    x[k] = 1;
    if(s+a[k]==d)
    {
        for(int i=1;i<=k;i++)
        {
            if(x[i])
                cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
    else if(s+a[k]+a[k+1] <= d)
    {
        count++;
        subset(s+a[k],k+1,ts-a[k]);
    }
    if((s+ts-a[k]>=d) && (s+a[k+1]<=d))
    {
        x[k] = 0;
        count++;
        subset(s,k+1,ts-a[k]);
    }

}
int main()
{
    int n,total=0;
    cout<<"Enter the array Size : ";
    cin>>n;
    cout<<"Ascending order Input : ";
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        total += a[i];
    }

    cout<<"Enter the Subset Sum : ";
    cin>>d;

    cout<<"Total Sum : "<<total<<endl;

    if(total<d)
        cout<<"No Solutions!!"<<endl;
    else
        subset(0,1,total);

    cout<<"No.of Nodes generated : "<<count<<endl;
    cout<<"Total No.of nodes in the state space tree : "<<pow(2,n)-1<<endl;
}
