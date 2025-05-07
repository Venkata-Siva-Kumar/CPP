//Radix Sort
#include<iostream>
#include<math.h>
using namespace std;
int count = 0;

void print(int a[],int n)
{
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void radix_sort(int a[],int g[],int n,int k)
{
    int c[k+1],b[n];
    for(int i=0;i<=k;i++)
    {
        count++;
        c[i] = 0;
    }

    for(int j=1;j<=n;j++)
    {
        count++;
        c[g[j]] += 1;
    }

    for(int i=1;i<=k;i++)
    {
        count++;
        c[i] += c[i-1];
    }

    for(int j=n;j>=1;j--)
    {
        count++;
        b[c[g[j]]] = a[j];
        c[g[j]] -= 1;
    }

    for(int i=1;i<=n;i++)
    {
        a[i] = b[i];
    }

    
}
int main()
{
    int n;
    cout<<"Enter the array size : ";
    cin>>n;
    int a[n],g[n];

    cout<<"Input : ";
    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    cout<<"Before Sorting : ";
    print(a,n);

    int max = a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]>max)
            max = a[i];
    }
    int d=0;
    while(max>0)
    {
        max = max/10;
        d++;
    }

    for(int i=0;i<d;i++)
    {
        for(int j=1;j<=n;j++)
        {
            g[j] = ( a[j] / (int)pow(10,i) )%10;
        }
        radix_sort(a,g,n,9);
        cout<<"Sorting "<<d+1<<" : ";
        print(a,n);
    }

    cout<<"Count : "<<count<<endl;
}
