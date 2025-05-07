//Matrix Chain DC
#include<iostream>
#include<ctime>
#define inf 1000
using namespace std;
int m[100][100],s[100][100],p[100];
int  n,count = 0;

int Rec_Matrix_DC(int i,int j)
{
    if(i==j)
        return 0;
    
    m[i][j] = 1000;
    for(int k=i;k<=j-1;k++)
    {
        count++;
        int q = Rec_Matrix_DC(i,k)+Rec_Matrix_DC(k+1,j)+( p[i-1]*p[k]*p[j]);
        if(q<m[i][j])
        {
            m[i][j] = q;
            s[i][j] = k;
        }
    }
    return m[i][j];
    
}
void printOptimal(int i,int j)
{
    if(i==j)
        cout<<"A"<<i;
    else
    {
        cout<<"(";
        printOptimal(i,s[i][j]);
        printOptimal(s[i][j]+1,j);
        cout<<")";
    }
}
int main()
{
    srand(time(0));
    int x=1,y=10;
    cout<<"Enter the no.of Matrices : ";
    cin>>n;

    for(int i=0;i<=n;i++)
    {
        p[i] = x+rand()%y;
        cout<<"P"<<i<<" : "<<p[i]<<endl;
    }

    for(int i=1;i<=n;i++)
        m[i][i] = 0;
    
    
    cout<<"Optimal Solution : "<<Rec_Matrix_DC(1,n);
    cout<<"\nCount : "<<count<<endl;
    printOptimal(1,n);
}
