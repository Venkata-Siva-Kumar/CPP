#include<iostream>
#include<ctime>
using namespace std;
int count = 0;

void print(int a[] , int n)
{
    for(int i=1;i<=n;i++)
        cout<<a[i]<<"  ";
}

int partition(int a[],int p,int r)
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

void quickSort(int a[],int p,int r)
{
    if(p<r)
    {
        int q=partition(a,p,r);
        quickSort(a,p,q-1);
        quickSort(a,q+1,r);
    }
}
int main()
{
    int n;
    cout<<"Enter the size : ";
    cin>>n;
    int a[n];

    srand(time(0));
    for(int i=1;i<=n;i++)
        a[i] = rand()%100;

    cout<<"***** Input elements *****\n";
    print(a,n);
    cout<<endl;

    quickSort(a,1,n);

    cout<<"***** After Sorting *****\n";
    print(a,n);

    cout<<"\nCount : "<<count<<endl;
}
