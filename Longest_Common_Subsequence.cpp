/* LCS */
#include<iostream>
#include<ctime>
using namespace std;
int b[100][100],c[100][100];
static int count =0;

string generateRandomSequence(int length) 
{
    string seq = "";
    for (int i = 0; i < length; i++) 
    {
        seq += 'A' + (rand() % 26);  // Random uppercase letter (A-Z)
    }
    return seq;
}

int LCS_LENGTH_BU(string x,string y,int m,int n)
{
    for(int i=1;i<=m;i++)
        c[i][0]=0;
    for(int j=0;j<=n;j++)
        c[0][j]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            count++;
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='d'; // diagonal
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='u'; // up
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='l'; // left
            }
        }
    }
    return c[m][n];
}

void printlcs(string x,int i,int j)
{
    if(i==0||j==0)
        return;
    if(b[i][j]=='d')
    {
        printlcs(x,i-1,j-1);
        cout<<x[i-1]<<" ";
    }
    else if(b[i][j]=='u')
        printlcs(x,i-1,j);
    else
        printlcs(x,i,j-1);
}

int main()
{
    srand(time(0)); 
    int m,n;
    cout << "Enter length of first sequence: ";
    cin >> m;
    cout << "Enter length of second sequence: ";
    cin >> n;

    string x = generateRandomSequence(m);
    string y = generateRandomSequence(n);

    cout << "First sequence: " << x << endl;
    cout << "Second sequence: " << y << endl;
    
    LCS_LENGTH_BU(x,y,m,n);
    cout<<"\nLCS Length : "<<c[m][n] << endl;

    cout<<"LCS : ";
    printlcs(x,m,n);
    cout<<"\nNo.of times basic Operation is executed : "<<count<<endl;
    return 0;
}
