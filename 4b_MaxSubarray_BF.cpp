//Brute Force MaxSubArray
#include<iostream>
using namespace std;
int count = 0;
int cs = -10000,ml =0 ,mr = 0,sum =0;
void subarray(int a[],int n)
{
    for(int i=1;i<=n;i++)
    {
        sum = 0;
        for(int j=i;j<=n;j++)
        {
            count++;
            sum += a[j];
            if(sum>cs)
            {
                cs = sum;
                ml = i;
                mr = j;
            }
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the array size : ";
    cin>>n;
    int a[n];

    cout<<"Input : ";
    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    subarray(a,n);

    cout<<"Left Index : "<<ml<<endl;
    cout<<"Right Index : "<<mr<<endl;
    cout<<"Sub array sum : "<<cs<<endl;
    cout<<"Sub array elements : [ ";
    for(int i=ml;i<=mr;i++)
        cout<<a[i]<<" ";
    cout<<"]"<<endl;
    cout<<"Count : "<<count <<endl;
}
