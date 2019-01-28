
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<cstring>

using namespace std;

struct Info
{
  int id;
  string name;


};
int partition(struct Info a[],int lo,int hi)
{        struct Info temp;
    int pivot=a[hi].id;
    int i=lo-1;
    for(int j=lo;j<=hi-1;j++)
    { if(a[j].id<=pivot)
    {
        i++;
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;




    }
    }
    temp=a[hi];
    a[hi]=a[i+1];
    a[i+1]=temp;


    return i+1;


    }


void QuickSort(struct Info a[],int lo,int hi)
{ if(lo<hi)
{
    int p=partition(a,lo,hi);
    QuickSort(a,lo,p-1);
    QuickSort(a,p+1,hi);

}


}


int main()
{
int asize=4;
struct Info a[asize];

    int lo,hi;



    printf("Enter array elements: ");

    for(int i=0;i<asize;i++)
    {

      a[i].id=rand()%10;
    }
    for(int i=0;i<asize;i++)
    {
        cin>>a[i].name;
    }
    puts(" ");
cout<<"Before sorting:"<<endl;
for(int i=0;i<asize;i++)
    {

        printf("%d ",a[i].id);
        cout<<a[i].name<<endl;
    }
    QuickSort(a,0,asize-1);
    puts("");
cout<<"After sorting:"<<endl;
for(int i=0;i<asize;i++)
{

    cout<<a[i].id<<" "<<a[i].name<<endl;
}


}
