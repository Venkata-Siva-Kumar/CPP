//Longest Commom Subsequence Top down
#include<iostream>
#include<ctime>
using namespace std;
int c[100][100];
char b[100][100];
int count =0 ;
void initialise(int m,int n)
{
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                c[i][j] = 0;
            else
                c[i][j] = -1;
        }
    }
}
string generate_random(int length)
{
    string str = "";
    for(int i=0;i<length;i++)
        str += 'A'+(rand()%26);
    return str;
}

int LCS_Length_TD(string x,string y,int i,int j)
{
    if(c[i][j]>=0)
        return c[i][j];
    count++;
    if(i==0 || j==0)
    {
        c[i][j] = 0;
        return c[i][j];
    }

    else if(x[i-1] == y[j-1])
    {
        c[i][j] = LCS_Length_TD(x,y,i-1,j-1)+1;
        b[i][j] = 'd';
    }
    else
    {
        int t1 = LCS_Length_TD(x,y,i-1,j);
        int t2 = LCS_Length_TD(x,y,i,j-1);
        if(t1>=t2)
        {
            c[i][j] = t1;
            b[i][j] = 'u';
        }
        else
        {
            c[i][j] = t2;
            b[i][j] = 'l';
        }        
    }
    return c[i][j];
}

void printLCS(string x,int i,int j)
{
    if(i==0 || j==0)
        return;
    if(b[i][j] == 'd')
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
    cout<<"Enter the length of 1st String : ";
    cin>>m;

    cout<<"Enter the length of 2nd String : ";
    cin>>n;
    initialise(m,n);

    string x = generate_random(m);
    string y = generate_random(n);

    cout<<"\nString X : "<<x<<"\nString Y : "<<y<<endl;

    cout<<"\nLCS Length : "<<LCS_Length_TD(x,y,m,n);
    cout<<"\nLCS : ";
    printLCS(x,m,n);
    cout<<"\nNo.of times basic operation is executed : "<<count<<endl;
}
