/* GREEDY ITERATIVE */
#include<iostream>
using namespace std;
int count=0;

void GreedyActivitySelector(int s[], int f[], int n) 
{
    cout << "Selected activities are: ";
    int k = 1;
    cout<<"a1"<<" ";
    count = 1;
    for (int m = 2; m <= n; m++) 
    {
        count++;
        if (s[m] >= f[k]) 
        {
            cout <<"a"<<m<< " "; // Select this activity
            k = m;
        }
    }
}

int main() 
{
    // int start[] = {1, 3, 0, 5, 3,5,6,7,8,2,12};
    // int finish[] = {4,5,6,7,9,9,10,11,12,14,16};

    int n;
    cout<<"Enter the no.of activities : ";
    cin>>n;
    int s[n],f[n];

    for(int i=1;i<=n;i++)
    {
        cout<<"Enter starting and finishing time of activity "<<i<<" : ";
        cin>>s[i]>>f[i];
        //cout<<i<<"---> "<<s[i]<<"---> "<<f[i]<<endl;
    }


    GreedyActivitySelector(s, f, n);
    cout<<"\nNo.of times basic operation is executed : "<<count<<endl;
}
