#include<iostream>
#include<ctime>
#define max 100
using namespace std;
int x = -10;
int y = 10;
int a[max],n;

struct node
{
    int low,high,sum;
};

struct node cross(int a[],int l,int m,int h)
{
    struct node temp;
    int ls = -1000,rs=-1000,ml,mr,i,j,sum=0;

    for(i=m;i>=l;i--)
    {
        sum += a[i];
        if(sum>ls)
        {
            ls = sum;
            ml = i;
        }
    }
    sum =0;
    for(j=m+1;j<=h;j++)
    {
        sum += a[j];
        if(sum>rs)
        {
            rs = sum;
            mr = j;
        }
    }

    temp.low = ml;
    temp.high = mr;
    temp.sum = ls+rs;
    return temp;
}

struct node fmsa(int a[],int l,int h)
{
    struct node temp,leftnode,rightnode,crossnode;
    if(l==h)
    {
        temp.low = l;
        temp.high = h;
        temp.sum = a[l];
        return temp;
    }

    int mid = (l+h)/2;
    leftnode = fmsa(a,l,mid);
    rightnode = fmsa(a,mid+1,h);
    crossnode = cross(a,l,mid,h);

    if((leftnode.sum>rightnode.sum) && (leftnode.sum >crossnode.sum))
        return leftnode;
    if((rightnode.sum>leftnode.sum) && (rightnode.sum >crossnode.sum))
        return rightnode;
    return crossnode;
}

void print()
{
    struct node t;
    t = fmsa(a,0,n-1);
    cout<<"\n\nIndex of Low : "<<t.low<<"\nIndex of High "<<t.high<<"\nSUM: "<<t.sum<<endl;
	cout<<"\nMAX SUB ARRAY : [  ";
    for(int i=t.low;i<=t.high;i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<"]"<<endl;
}

int main()
{
    cout<<"Enter the array size : ";
    cin>>n;
    srand(time(0));
    for(int i=0;i<n;i++)
        //cin>>a[i];
        a[i] =x+rand()%(y-x+1);

    cout<<"\n***** Input Array *****\n";
    for(int i=0;i<n;i++)
       cout<<a[i]<<" ";
    
    print();
}
