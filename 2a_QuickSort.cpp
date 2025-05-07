//Quick Sort
#include<iostream>
using namespace std;
int count = 0;

void print(int a[],int n)
{
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int  partition(int a[],int p,int r)
{
    int x = a[r];
    int i = p-1;
    for(int j=p;j<r;j++)
    {
        count++;
        if(a[j]<x)
        {
            i++;
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    int temp = a[i+1];
    a[i+1] = a[r];
    a[r] = temp;
    return i+1;
}
void quick_sort(int a[],int p,int r)
{
    if(p<r)
    {
        int q = partition(a,p,r);
        quick_sort(a,p,q-1);
        quick_sort(a,q+1,r);
    }
}

int main()
{
    int n;
    cout<<"Enter the array size : ";
    cin>>n;
    int a[n];

    for(int i=1;i<=n;i++)
    {
        cout<<"a["<<i<<"] : ";
        cin>>a[i];
    }

    cout<<"Before Sorting : ";
    print(a,n);

    quick_sort(a,1,n);

    cout<<"After Sorting : ";
    print(a,n);

    cout<<"Count : "<<count<<endl;
}
