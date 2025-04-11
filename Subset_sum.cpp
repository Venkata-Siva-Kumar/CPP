/*SUB SET SUM*/
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int n,d,a[100],x[100];
static int count=0;

void subsetsum(int s,int k,int ts)
{
    x[k]=1;
    if(s+a[k] == d)
    {
        for(int i=1;i<=k;i++)
        {
            if(x[i])
                cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
    else if(s+a[k]+a[k+1] <=d)
    {
        count++;
        subsetsum(s+a[k],k+1,ts-a[k]);
    }
    
    if((s+ts-a[k]>=d) && (s+a[k+1]<=d))
    {
        x[k] =0;
        subsetsum(s,k+1,ts-a[k]);
        count++;
    }
    
}

int main()
{
    int total_sum=0;
    cout<<"Enter the no.of elements : ";
    cin>>n;
    
    cout<<"Enter the elements in ascending order: ";
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        total_sum += a[i];
    }
    
    cout<<"Enter subset sum to find : ";
    cin>>d;
    
    cout<<"Total sum = "<<total_sum<<endl;
    cout<<"***** Possible Solutions are *****\n";
    
    if(total_sum<d)
        cout<<"No Solutions\n";
    else
        subsetsum(0,1,total_sum);
    
    int Total = pow(2,n)-1;
    cout<<"Total No.of Nodes in State Space tree : "<< Total<<endl;
    cout<<"No.of Nodes Generated : "<<count<<endl;
    return 0;
}
