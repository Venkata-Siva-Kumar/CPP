//Merge Sort
#include<iostream>
using namespace std;
int count=0;

void print(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void Merge(int a[],int p,int q,int r)
{
    int left = q-p+1;
    int right = r-q;
    int Ar[left],Br[right];

    for(int i=0;i<left;i++)
        Ar[i] = a[p+i];
    for(int j=0;j<right;j++)
        Br[j] = a[q+1+j];
    
    int i=0,j=0,k=p;

    while(i<left && j<right)
    {
        count++;
        if(Ar[i]<=Br[j])
            a[k++] = Ar[i++];
        else
            a[k++] = Br[j++];
    }

    while(i<left)
    {
        count++;
        a[k++] = Ar[i++];
    }
    while(j<right)
    {
        count++;
        a[k++] = Br[j++];
    }
}
void Mergesort(int a[],int p,int r)
{
    if(p<r)
    {
        int q = (p+r)/2;
        Mergesort(a,p,q);
        Mergesort(a,q+1,r);
        Merge(a,p,q,r);
    }
}
int main()
{
    int n;
    cout<<"Enter the Array Size : ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"a["<<i<<"] : ";
        cin>>a[i];
    }

    cout<<"Before Sorting : ";
    print(a,n);

    Mergesort(a,0,n-1);

    cout<<"After Sorting : ";
    print(a,n);

    cout<<"Count : "<<count<<endl;
}
