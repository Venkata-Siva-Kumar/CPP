//Heap Sort
#include<iostream>
using namespace std;
int count =0,heapsize= 0;

int left(int i)
{
    return (2*i);
}
int right(int i)
{
    return (2*i+1);
}

void print(int a[],int n)
{
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void MaxHeapify(int a[],int i)
{
    int l = left(i);
    int r = right(i);
    int largest = 0;
    if(l<=heapsize && a[l] > a[i])
        largest = l;
    else
        largest = i;
    if(r<=heapsize && a[r] >= a[largest])
        largest = r;
    if(largest != i)
    {
        count++;
        swap(a[i],a[largest]);
        MaxHeapify(a,largest);
    }
    
}
void build(int a[],int n)
{
    heapsize = n;
    for(int i=n/2;i>=1;i--)
        MaxHeapify(a,i);
}
void Heapsort(int a[],int n)
{
    build(a,n);
    for(int i=n;i>1;i--)
    {
        int temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        count++;
        heapsize -= 1;
        MaxHeapify(a,1);
    }
}

int main()
{
    int n;
    cout<<"Enter the array Size : ";
    cin>>n;
    int a[n];

    for(int i=1;i<=n;i++)
    {
        cout<<"a["<<i<<"] : ";
        cin>>a[i];
    }

    cout<<"Before Sorting : ";
    print(a,n);

    Heapsort(a,n);

    cout<<"After Sorting : ";
    print(a,n);

    cout<<"Count : "<<count<<endl;
}
