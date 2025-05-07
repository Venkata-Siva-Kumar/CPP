//LCS BOTTOM UP
#include<iostream>
#include<ctime>
using namespace std;
int c[100][100];
char b[100][100];
int count = 0;
string generate_random(int length)
{
    string str = "";
    for(int i=0;i<length;i++)
        str += 'A' +(rand()%26);
    return str;
}

void LCS_Length(string x,string y,int m,int n)
{
    for(int i=1;i<=m;i++)
        c[i][0] = 0;
    for(int j=0;j<=n;j++)
        c[0][j] = 0;
    
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            count++;
            if(x[i-1] == y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 'd';
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 'u';
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 'l';
            }
        }
    }
}

void printLCS(string x,int i,int j)
{
    if(i==0 || j==0)
        return;

    else if(b[i][j] == 'd')
    {
        printLCS(x,i-1,j-1);
        cout<<x[i-1]<<" ";
    }
    else if(b[i][j] == 'u')
        printLCS(x,i-1,j);
    else
        printLCS(x,i,j-1);
}
int main()
{
    srand(time(0));
    int m,n;
    cout<<"Enter the length of first Sting : ";
    cin>>m;
    cout<<"Enter the length of Second Sting : ";
    cin>>n;

    string x = generate_random(m);
    string y = generate_random(n);

    cout<<"\nString X : "<<x<<"\nString Y : "<<y<<endl; 
    LCS_Length(x,y,m,n);

    cout<<"LCS : ";
    printLCS(x,m,n);

    cout<<"\nLCS Length : "<<c[m][n]<<endl;
    cout<<"Count : "<<count<<endl;


    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<c[i][j]<<"\t";
        }
        cout<<endl;
    }
}
