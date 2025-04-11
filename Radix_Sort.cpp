#include<iostream>
#include<ctime>
#include<math.h>
using namespace std;
int count=0;

void print(int a[] ,int n)
{
    for(int i=1;i<=n;i++)
        cout<<a[i]<<"  ";
    cout<<endl;
}
void countsort(int a[],int g[],int k,int n)
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
        a[i]=b[i];
}

int main()
{
    int n;
    cout<<"size : ";
    cin>>n;
    int a[n],g[n],d=0,max;

    srand(time(0));
    for(int i=1;i<=n;i++)
        a[i] = 100+rand()%900;

    cout<<"\n***** Input elements *****\n";
    print(a,n);
    cout<<endl<<"***** Sorting *****\n";

    max = a[1];
    for(int i=2;i<=n;i++)
    {
        if(max<a[i])
            max = a[i];
    }

    while(max>0)
    {
        d++;
        max/=10;
    };

    for(int i=0;i<d;i++)
    {
        for(int j=1;j<=n;j++)
        {
            g[j] = (a[j]/(int)pow(10,i))%10;
        }

        countsort(a,g,9,n);
        cout<<"After Surting "<<i+1<<" : ";
        print(a,n);

    }
    cout<<"\n***** Finally Sorted Elements *****\n ";
    print(a,n);

    cout<<"Count : "<<count<<endl;
}
