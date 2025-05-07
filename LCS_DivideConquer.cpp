//LCS DIVIDE AND CONQUER

#include<iostream>
#include<ctime>
using namespace std;
int count = 0;

string generate_random(int length)
{
    string str = "";
    for(int i=0;i<length;i++)
    {
        str += 'A'+(rand()%26);
    }
    return str;
}

string LCS_DC(string x,string y,int i,int j)
{
    count++;
    string t1,t2;
    if(i==0 || j==0)
        return "";
    
    if(x[i-1]==y[j-1])
        return LCS_DC(x,y,i-1,j-1)+x[i-1];
    else
    {
        t1 = LCS_DC(x,y,i-1,j);
        t2 = LCS_DC(x,y,i,j-1);
        if(t1.length()>=t2.length())
            return t1;
        else
            return t2;
    }
}
int main()
{
    srand(time(0));
    int m,n;
    cout<<"Enter the length of 1st String : ";
    cin>>m;
    cout<<"Enter the length of 2nd String : ";
    cin>>n;

    string x = generate_random(m);
    string y = generate_random(n);
    cout<<"\nString X : "<<x<<"\nString Y : "<<y<<endl;
    string lcs = LCS_DC(x,y,m,n);
    cout<<"LCS : "<<lcs<<endl;
    cout<<"LCS Length : "<<lcs.length()<<endl;
    cout<<"Count : "<<count<<endl;
}
