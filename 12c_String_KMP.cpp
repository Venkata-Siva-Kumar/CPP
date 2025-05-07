//KMP
#include<iostream>
#include<string.h>
using namespace std;
char T[100],P[100];
int pi[100];
int count=0,pre_count = 0;

void prefix(int m)
{
    pi[1] = 0;
    int k = 0;

    for(int q=2;q<=m;q++)
    {
        pre_count++;
        while((k>0) && P[k+1]!=P[q])
        {
            k = pi[k];
            pre_count++;
        }

        if(P[k+1] == P[q])
            k++;
        pi[q] = k;
    }

    cout<<"\nPrefix Value : ";
    for(int i=1;i<=m;i++)
        cout<<pi[i]<<" ";
    cout<<endl;
}
void KMP(char T[],char P[],int n,int m)
{
    prefix(m);
    int q =0;

    for(int i=1;i<=n;i++)
    {
        count++;
        while((q>0) && P[q+1]!=T[i])
        {
            count++;
            q = pi[q];
        }
        if(P[q+1]==T[i])
            q++;
        if(q==m)
        {
            cout<<"Pattern Occurs with shift "<<i-m<<endl;
            q = pi[q];
        }
    }
}
int main()
{
    cout<<"Text : ";
    cin>>T;
    cout<<"Pattern : ";
    cin>>P;

    int n = strlen(T);
    int m = strlen(P);

    for(int i=n;i>=1;i--)
        T[i] = T[i-1];

    for(int i=m;i>=1;i--)
        P[i] = P[i-1];

    P[0] =0,T[0] = 0;
    KMP(T,P,n,m);
    cout<<"Prefix Count : "<<pre_count<<endl;
    cout<<"Count : "<<count<<endl;
}
