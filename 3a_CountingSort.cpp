//Counting Sort
#include<iostream>
using namespace std;
int count = 0;

void print(int a[],int n)
{
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void counting_sort(int a[],int k,int n)
{
    int c[k+1],b[n];
    for(int i=0;i<=k;i++)
    {
        count++;
        c[i]=0;
    }

    for(int j=1;j<=n;j++)
    {
        count++;
        c[a[j]] += 1; 
    }

    for(int i=1;i<=k;i++)
    {
        count++;
        c[i] += c[i-1];
    }

    for(int j=n;j>=1;j--)
    {
        count++;
        b[c[a[j]]] = a[j];
        c[a[j]] -= 1;
    }

    cout<<"After Sorting : ";
    print(b,n);
}
int main()
{
    int n;
    cout<<"Enter the array size : ";
    cin>>n;
    int a[n];

    cout<<"Input : ";
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<"Before Sorting : ";
    print(a,n);

    int max = a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]>max)
            max = a[i];
    }

    counting_sort(a,max,n);

    cout<<"Count : "<<count<<endl;

}
