#include<bits/stdc++.h>
using namespace std;

double x[100];
void Fractional_Knapsack(int n,double m, double w[],double p[])
{
    for(int i=1;i<=n;i++)
    {
        x[i]=0.0;
    }

    sort(p.begin(),p.end());
    int U=m;

    for(int i=1;i<=n;i++)
    {
       if (w[i]>U)
            break;
       else
       {
           x[i]=1.0;
           U=U-w[i];
       }


    if(i<=n)
    {
        x[i]=U/w[i];
    }
    }

}

int main()
{
    int item;
    double capacity;
    double weight[10],profit[10];
    cout<<"Enter the number of items: "<<endl;
    cin>>item;

    cout<<"Enter the weight of each item: "<<endl;
    for(int i=1;i<=item;i++)
    {
        cin>>weight[i];
    }


    cout<<"Enter the capacity: "<<endl;
    cin>>capacity;

    Fractional_knapsack(item,capacity,weight);

    return 0;

}
