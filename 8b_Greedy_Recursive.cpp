//GREEDY RECURSIVE
#include<iostream>
using namespace std;
int count = 0;

void Recursive_Activity_Selector(int s[],int f[],int k,int n)
{
    int m = k+1;
    count++;
    while(m<=n && s[m]<f[k])
    {
        m++;
        count++;
    }

    if(m<=n)
    {
        cout<<"a"<<m<<" ";
        Recursive_Activity_Selector(s,f,m,n);
    }
    else
        return;
}
int main()
{
    int n;
    cout<<"Enter the no.of activities : ";
    cin>>n;
    int s[n],f[n];
    f[0] = 0;
    for(int i=1;i<=n;i++)
    {
        cout<<"Enter the Starting and finishing time of Activity - "<<i<<" : ";
        cin>>s[i]>>f[i];
    }
    cout<<"Activities Selected : ";
    Recursive_Activity_Selector(s,f,0,n);
    cout<<"\nNo.of times basic Operation is executed : "<<count<<endl;
}
