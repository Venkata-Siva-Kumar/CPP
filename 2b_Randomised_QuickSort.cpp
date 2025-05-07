//Randomised Quick Sort
#include<iostream>
#include<ctime>
using namespace std;
int count =0;

void print(int a[],int n)
{
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
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
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}
int rand_partition(int a[],int p,int r)
{
    int i = p + rand()%(r-p+1);
    swap(a[i],a[r]);
    return partition(a,p,r);
}
void rand_quicksort(int a[],int p,int r)
{
    if(p<r)
    {
        int q = rand_partition(a,p,r);
        rand_quicksort(a,p,q-1);
        rand_quicksort(a,q+1,r);
    }
}
int main()
{
    srand(time(0));
    int n;
    cout<<"Enter the array Size : ";
    cin>>n;
    int a[n];

    cout<<"Input : ";
    for(int i=1;i<=n;i++)
        cin>>a[i];

    cout<<"Before Sorting : ";
    print(a,n);

    rand_quicksort(a,1,n);

    cout<<"After Sorting : ";
    print(a,n);

    cout<<"Count : "<<count<<endl;
}
