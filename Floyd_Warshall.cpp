//FLOYD WARSHALL 
#include<iostream>
using namespace std;
#define NIL 0
#define max 10
#define INF 1000
int n,w[max][max],d[max][max],pi[max][max];

void print(int d[][max])
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<d[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void Floyd_Warshall(int w[][max])
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            d[i][j] = w[i][j];
            if(i==j || d[i][j] == INF)
                    pi[i][j] = NIL;
            else
                pi[i][j] = i;
        }
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(d[i][j] > d[i][k]+d[k][j])
                {
                    d[i][j] = d[i][k]+d[k][j];
                    pi[i][j] = pi[k][j];
                }
            }
        }

        //cout<<"\n\n D"<<k<<" Matrix : "<<endl;
        //print(d);
    }
}

void print_AllPairsShortestPath(int i,int j)
{
    if(i==j)
        cout<<i<<"-->";
    else if(pi[i][j] == NIL)
        cout<<"No path exits from "<<i<<" to "<<j<<endl;
    else
    {
        print_AllPairsShortestPath(i,pi[i][j]);
        cout<<j<<"-->";
    }
}
int main()
{
    cout<<"Enter the no. of Vertices : ";
    cin>>n;

    cout<<"***** Enter the Weighted Matrix *****"<<endl;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>w[i][j];
        }
    }

    Floyd_Warshall(w);
    cout << "\n\nW matrix: " << endl;
    print(w);
   
    cout << endl;    
    cout << "D matrix: " << endl;
    print(d);
   
    cout << endl;    
    cout << "Pi matrix: " << endl;
    print(pi);
    int from,to;
    cout<<"Shortest path from - To : ";
    cin>>from>>to;
    print_AllPairsShortestPath(from,to);

    cout<<"\nCost from "<<from<<" to "<<to<<" is : ";
    cout<<d[from][to]<<endl;
}

/* 
    -------------W-Matrix---------------
    [0,     3,      8,      1000,   -4]
    [1000,  0,      1000,   1,       7]
    [1000,  4,      0,      1000,  1000]
    [2,     1000,   -5,     0,      1000]
    [1000,  1000,   1000,   6,      0]
*/
