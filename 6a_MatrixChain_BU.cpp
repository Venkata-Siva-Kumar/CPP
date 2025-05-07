//Matrix Chain Bottom up
#include<iostream>
#include<ctime>
#define inf 100000
using namespace std;
int m[100][100],s[100][100];
int count = 0;

void Matrix_Chain_Order(int p[],int n)
{
    for(int i=1;i<=n;i++)
        m[i][i] = 0;
    
    for(int l=2;l<=n;l++)
    {
        for(int i=1;i<=(n-l+1);i++)
        {
            int j = i+l-1;
            m[i][j] = inf;
            for(int k=i;k<=j-1;k++)
            {
                count++;
                int q = m[i][k] + m[k+1][j] + ( p[i-1]*p[k]*p[j]);
                if(q<m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }    

        }
    }

}

void Print_Optimal_Parens(int i,int j)
{
    if(i==j)
        cout<<"A"<<i;
    else
    {
        cout<<"(";
        Print_Optimal_Parens(i,s[i][j]);
        Print_Optimal_Parens(s[i][j]+1 , j);
        cout<<")";
    }
}

int main()
{
    //srand(time(0));
    int n,x = 1,y = 10;
    cout<<"Enter the No.of Matrices : ";
    cin>>n;
    
    int p[n+1];
    for(int i=0;i<=n;i++)
    {
        p[i] = x + rand()%y;
        cout<<"P"<<i<<" : "<<p[i]<<endl;
    }

    Matrix_Chain_Order(p,n);

    cout<<"***** Matrix-M *****"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<"***** Matrix-S *****"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<s[i][j]<<"\t";
        }
        cout<<endl;
    }

    Print_Optimal_Parens(1,n);
    cout<<"\nOptimal Solution : "<<m[1][n]<<endl;
    cout<<"Count : "<<count<<endl;
}
