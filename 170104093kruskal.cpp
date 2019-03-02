#include<bits/stdc++.h>

using namespace std;
int node,edge;
int par[100];
pair  < int ,pair < int ,int > > adj[100];
int findpar(int i)
{
    if(par[i]==i)
    {
        return i;
    }
    else
        findpar(par[i]);
}
int cost=0;
void unionn(int x,int y)
{
    int x1=findpar(x);
    int y1=findpar(y);
    par[x1]=par[y1];
}

void kruskal()
{
    for(int i=0;i<edge;i++)
    {


    int x=adj[i].second.first;
    int y=adj[i].second.second;
    int z=adj[i].first;

    if(findpar(x)!=findpar(y))
    {
        cout<<x<<"---"<<y<<endl;
        cost+=z;
        unionn(x,y);

    }
    }


}
void creategraph()
{
    int a,b,c;

    for(int i=0;i<edge;i++)
    {
        cin>>a>>b>>c;
        adj[i]=make_pair(c,make_pair(a,b));

    }
}
int main()
{
    cout<<"Enter vertex and edge no : "<<endl;
    cin>>node>>edge;

    cout<<"Enter two vertices and cost :"<<endl;
    creategraph();

    for(int i=0;i<node;i++)
    {
        par[i]=i;
    }
    sort(adj,adj+edge);
    kruskal();
    cout<<"cost is "<<cost;

}
