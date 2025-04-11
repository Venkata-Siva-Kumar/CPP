/* FLOYD WARSHALL */
#include<iostream>
#define NIL 0
#define max 10
#define INF  1000

using namespace std;
int n,w[max][max],d[max][max],p[max][max];

void printMatrix(int a[][max])
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<"\t";
        cout<<endl;
    }
}

void Floyd_Warshall(int w[][max])
{
    //Initialize Algorithm
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            d[i][j] = w[i][j];
            if(i==j || w[i][j] == INF)
                p[i][j] = NIL;
            else
                p[i][j] = i;
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(d[i][j] >d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[k][j];
                }
                else
                {
                    d[i][j] = d[i][j];
                    p[i][j] = p[i][j];
                }
            }
        }
        cout << endl << endl;
        cout << "D" << k << " Matrix: " << endl;
        printMatrix(d);
    }
}
void printAllPairsShortestPath(int i, int j)
{
    if(i == j)
        cout << i << " -> ";
    else if(p[i][j] == NIL)
        cout << "No path from " << i << " to " << j << " exists" << endl;
    else 
    {
        printAllPairsShortestPath(i, p[i][j]);
        cout << j << " -> ";
    }
}

int main()
{
    cout<<"Enter the no.of Vertices : ";
    cin>>n;

    cout<<"***** Enter the Weighted Matrix *****"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cin>>w[i][j];
    }

    Floyd_Warshall(w);

    cout << "\n\nW matrix: " << endl;
    printMatrix(w);
   
    cout << endl;    
    cout << "D matrix: " << endl;
    printMatrix(d);
   
    cout << endl;    
    cout << "P matrix: " << endl;
    printMatrix(p);
   
    int from,to;
    cout << "Enter the Shortest Path from - to : ";
    cin>>from >>to;
    printAllPairsShortestPath(from,to);

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
