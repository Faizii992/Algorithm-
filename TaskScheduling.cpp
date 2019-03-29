#include<bits/stdc++.h>
using namespace std;

struct Info
{
    float stime;
    float ftime;
    float sum;
    float div;

};
vector < Info > que;

int n;
int main()
{
struct Info a[100];
cin>>n;

cout<<"Enter the start and finish times: "<<endl;
for(int i=0;i<n;i++)
{
    cin>>a[i].stime>>a[i].ftime;
}

for(int i=0;i<n;i++)
{
for(int j=i+1;j<n;j++)
{
        if(a[i].stime>a[j].stime)
        {
            swap(a[i],a[j]);
        }
        else
        {
            continue;
        }
}
}
for(int i=0;i<n;i++)
{
    cout<<"  Task No :"<<i+1<<" Start: "<<a[i].stime<<"  Finish: "<<a[i].ftime<<endl;
}
Info r;
int i=-1;
cout<<"The schedule is "<<endl;
cout<<"-------------------------------"<<endl;
puts("");
   for(int j=0;j<n;j++)
    {
        if(a[j].stime>=a[i].ftime)
        {
            //cout<<" Task No: "<<j<<" start : "<<a[j].stime<<" Finish Time  "<<a[j].ftime<<endl;
            i=j;
            que.push_back(a[i]);

        }
    }
for(int i=0;i<que.size();i++)
{
    cout<<"Task No: "<<i+1<<" Start time: "<<que[i].stime<<" Finish time :"<<que[i].ftime<<endl;
}
}
