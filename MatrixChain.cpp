/*MATRIX CHAIN*/
#include<iostream>
#include<stdlib.h>
using namespace std;
#define inf 100000
int m[20][20],s[20][20];
static int count=0;

int MatrixChainOrder(int p[],int n)
{
    int j,q;
    for(int i=1;i<=n;i++)
        m[i][i] = 0;

    for(int l=2;l<=n;l++)
    {
        for(int i=1;i<=(n-l+1);i++)
        {
            j = i+l-1;
            m[i][j] = inf;
            for(int k=i;k<=j-1;k++)
            {
                count++;
                q = m[i][k] + m[k+1][j] + (p[i-1]*p[j]*p[k]);
                if(q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void PrintOptimalParens(int i,int j)
{
    if(i==j)
        cout<<"A"<<i;
    else
    {
        cout<<"(";
        PrintOptimalParens(i,s[i][j]);
        PrintOptimalParens(s[i][j]+1,j);
        cout<<")";
    }
}

int main()
{
    int p[20];
    int n,x=1,y=10;
    
    cout<<"Enter the No of Matrices: "; 
    cin>>n;
    for(int i=0; i<=n; i++)
    {
        cout<<"P"<<i<<" ";
        p[i]= x + (rand()%y);
        cout<<p[i]<<" ";
        cout<<endl;
    }
    
    MatrixChainOrder(p,n);
    
    cout<<endl<<"m matrix: "<<endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<m[i][j]<<"\t";
        cout<<endl;
    }
    
    cout<<endl<<"s matrix: "<<endl;
    
    for(int i=1; i<=n-1; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<s[i][j]<<"\t";
        cout<<endl;
    }   
    
    cout<<endl;
    PrintOptimalParens(1,n);
    cout<<"\nNo.of times basic Operation is executed  : "<<count<<endl;
}
