//Maximum sub array Divide and Conquer
#include<iostream>
using namespace std;
int count = 0;

struct node
{
    int low,high,sum;
};

void print(int a[],int n)
{
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

struct node find_cross(int a[],int low,int mid,int high)
{
    int ls = -1000,rs = -1000,ml,mr,sum=0;
    for(int i=mid;i>=low;i--)
    {
        count++;
        sum += a[i];
        if(sum>ls)
        {
            ls = sum;
            ml = i;
        }
    }
    sum = 0;
    for(int j= mid+1;j<=high;j++)
    {
        count++;
        sum += a[j];
        if(sum>rs)
        {
            rs = sum;
            mr = j;
        }
    }

    return{ml,mr,ls+rs};
}
struct node fmsa(int a[],int l,int h)
{
    struct node left,cross,right;
    if(l==h)
        return {l,h,a[l]};

    int mid = (l+h)/2;
    left = fmsa(a,l,mid);
    right = fmsa(a,mid+1,h);
    cross = find_cross(a,l,mid,h);

    if(left.sum>right.sum && left.sum>cross.sum)
        return left;
    else if(right.sum>left.sum && right.sum>cross.sum)
        return right;
    else
        return cross;
    
}
void print(int a[],int l,int h)
{
    struct node  t = fmsa(a,l,h);
    cout<<"Sub array : [ ";
    for(int i=t.low;i<=t.high;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<" ]"<<endl;
    cout<<"Left Index : "<<t.low<<endl;
    cout<<"Right Index : "<<t.high<<endl;
    cout<<"Sub array sum : "<<t.sum<<endl;
    cout<<"No.of times basic operation executed : "<<count<<endl;
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

    print(a,1,n);
}
