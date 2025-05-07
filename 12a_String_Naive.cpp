//NAIVE
#include<iostream>
using namespace std;
int count = 0;
void Naive(string T,string P)
{
    int n = T.length();
    int m = P.length();
    for(int s=0;s<=n-m;s++)
    {
        count++;
        int flag = 0;
        for(int j=0;j<m;j++)
        {
            count++;
            if(P[j] != T[s+j])
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
            cout<<"Pattern Occurs with shift "<<s<<endl;
    }
}
int main()
{
    string T,P;
    cout<<"Text : ";
    cin>>T;
    cout<<"Pattern : ";
    cin>>P;

    Naive(T,P);
    cout<<"Count : "<<count<<endl;

}
