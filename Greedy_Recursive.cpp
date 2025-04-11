/* GREEDY RECURSIVE */
#include<iostream>
using namespace std;
//int s[100],f[100];
int count =0;

void Recursive_Activity_selector(int s[],int f[],int k,int n)
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
        Recursive_Activity_selector(s,f,m,n);
    }
    else 
        return ;
}

int main() 
{
    // int start[] = {1, 3, 0, 5, 3,5,6,7,8,2,12};
    // int finish[] = {4,5,6,7,9,9,10,11,12,14,16};

    int n;
    cout<<"Enter the no.of activities : ";
    cin>>n;
    int s[n],f[n];
    f[0] = 0;
    for(int i=1;i<=n;i++)
    {
        cout<<"Enter starting and finishing time of activity "<<i<<" : ";
        cin>>s[i]>>f[i];
       // cout<<i<<"---> "<<s[i]<<"---> "<<f[i]<<endl;
    }

    cout << "Selected activities are: ";
    Recursive_Activity_selector(s, f, 0,n);
    cout<<"\nNo.of times basic operation is executed : "<<count<<endl;
}
