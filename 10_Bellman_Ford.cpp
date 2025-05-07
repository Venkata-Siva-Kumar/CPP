//BELLMAN FORD
#include<iostream>
#define max 100
#define INF 10000
using namespace std;

struct edge
{
    int u,v;
    //int wt;
}e[max];

int main()
{
    int d[max],pi[max],w[max][max];
    int nv,ne,s;
    int f,t,weight;
    int u,v;
    cout<<"Enter the No.of Vertices : ";
    cin>>nv;

    cout<<"Enter the No.of Edges : ";
    cin>>ne;

    cout<<"Enter the Source Vertex : ";
    cin>>s;

    for(int i=1;i<=nv;i++)
    {
        d[i] = INF;
        pi[i] = -1;
    }
    d[s] = 0;

    cout<<"***** Enter the Values From-To-Weight *****"<<endl;
    for(int i=1;i<=ne;i++)
    {
        cout<<"Edge-"<<i<<" : ";
        cin>>f>>t>>weight;

        w[f][t] = weight;
        e[i].u = f;
        e[i].v = t;
       // e[i].wt = weight;
    }

    for(int i=1;i<nv;i++)
    {
        for(int j=1;j<=ne;j++)
        {
            u = e[j].u;
            v = e[j].v;
            if(d[v]>d[u]+w[u][v])
            {
                d[v]  = d[u]+w[u][v];
                pi[v] = u;
            }
        }
    }

    int cycle = 0;
    for(int i=1;i<=ne;i++)
    {
        u = e[i].u;
        v = e[i].v;
        if(d[v]>d[u]+w[u][v])
        {
            cycle = 1;
            break;
        }
    }

    if(!cycle)
    {
        cout<<"Vertex\td[]\tpi[]"<<endl;
        for(int i=1;i<=nv;i++)
        {
            cout<<i<<"\t"<<d[i]<<"\t"<<pi[i]<<endl;
        }
    }
    else
        cout<<"Negative cycles detected !!"<<endl;
}
