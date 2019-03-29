#include<bits/stdc++.h>
#define V 10
using namespace std;
vector <int> parent;

int INF=9999;
int dist[V][V];
int a=0;
int node,edge;
vector <  int >  adj[V];
int cost=0;
int main()
{ int a,b,c;

    cout<<"Enter node and edge number :"<<endl;
    cin>>node>>edge;
for(int i=0;i<node;i++)
{
    for(int j=0;j<node;j++)
    {
        if(i==j)
        {
             dist[i][j]=0;
        }
        else
        { dist[i][j]=INF;

        }
    }
}
    cout<<"Enter two connected vertices and cost : "<<endl;
    for(int i=0;i<edge;i++)
    {   cin>>a>>b>>c;
    adj[a].push_back(b);
       dist[a][b]=c;

    }
    for(int k=0;k<node;k++)
    {
        for(int i=0;i<node;i++)
        {
            for(int j=0;j<node;j++)
            {

                if(i!=j&&(dist[i][j]>(dist[i][k]+dist[k][j])))
                {
                    dist[i][j]=dist[i][k]+dist[k][j];

                }

            }
        }
    }
cout<<"-------------------------"<<endl;
cout<<"ALL PAIRS SHORTEST PATH MATRIX: "<<endl;
for(int i=0;i<node;i++)
{
    for(int j=0;j<node;j++)
    {    if(dist[i][j]==INF)
    {
        cout<<"INF ";
    }
    else
    {
        cout<<dist[i][j]<<"   ";
    }
    }
    puts("");
}
cout<<"-------------------------"<<endl;
cout<<"Shortest paths that exist are: "<<endl;
puts("");

for(int i=0;i<node;i++)
{
    for(int j=0;j<node;j++)
    {
        if(dist[i][j]!=INF&&dist[i][j]!=0)
        {
            cout<<i<<"-----"<<j<<" Cost : "<<dist[i][j]<<endl;
        }
    }
}
    }
