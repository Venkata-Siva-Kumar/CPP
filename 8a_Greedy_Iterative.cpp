//GREEDY ITERATIVE 
#include<iostream>
using namespace std;
int count = 0;
void Greedy_Iterative(int s[],int f[],int n)
{
    cout<<"Activities Selected : ";
    int k = 1;
    cout<<"a"<<k<<" ";
    count++;
    for(int m=2;m<=n;m++)
    {
        count++;
        if(s[m]>=f[k])
        {
            cout<<"a"<<m<<" ";
			k = m;
        }
    }
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
    
    Greedy_Iterative(s,f,n);
    cout<<"\nNo.of times basic operation is executed : "<<count<<endl;
}
