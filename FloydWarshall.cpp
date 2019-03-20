#include<bits/stdc++.h>
#define white 0
#define grey 1
#define V 10

using namespace std;
vector < int > color;
vector <int> parent;
//vector < int > dist[V];
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
       cout<<"-------- "<< dist[a][b]<<endl;
    }


    for(int k=0;k<node;k++)
    {
        for(int i=0;i<node;i++)
        {
            for(int j=0;j<node;j++)
            {
               // cout<<"BEFORE " <<dist[i][j]<<" "<<dist[i][k]<<" "<<dist[k][j]<<endl;
                if(/*dist[i][j]!=INT_MAX&&*/i!=j&&(dist[i][j]>(dist[i][k]+dist[k][j])))
                {
                      //cout<<"AFTER " <<dist[i][j]<<" "<<dist[i][k]<<" "<<dist[k][j]<<endl;
                    dist[i][j]=dist[i][k]+dist[k][j];
                    //zv cout<<"--"<<dist[i][j]<<endl;
                }

            }
        }
    }
cout<<"-------------------------"<<endl;
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
    }
