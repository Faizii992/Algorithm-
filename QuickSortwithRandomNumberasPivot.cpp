#include<stdio.h>
#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<time.h>
using namespace std;
int partition(int a[],int lo,int hi)
{  int i=lo-1;
int pivot=a[hi];
int temp;
for(int j=lo;j<=hi-1;j++)
{
    if(a[j]<=pivot)
{

    i++;
  swap(a[i],a[j]);
}
}
swap(a[i+1],a[hi]);
return i+1;




}

int partitionRandom(int a[],int lo,int hi)
{int temp2;
int P;
srand(time(NULL));
P=lo+rand()%(hi-lo);


    swap(a[hi],a[P]);
return partition(a,lo,hi);

}

void QuickSort(int a[],int lo,int hi)
{
    if(hi>lo)
    {
        int p=partitionRandom(a,lo,hi);
        QuickSort(a,lo,p-1);
        QuickSort(a,p+1,hi);


    }


}
int main()
{

    int asize;
    cout<<"Enter size of array!"<<endl;
   scanf("%d",&asize);
   int a[asize];
   cout<<"Enter array elements!"<<endl;
   for(int i=0;i<asize;i++)
   {
       a[i]=rand()%50;
   }
   cout<<"The array elements are:"<<endl;
   for(int i=0;i<asize;i++)
   {
     cout<<a[i]<<endl;

   }
puts("");

   QuickSort(a,0,asize-1);
for(int i=0;i<asize;i++)
   {
       cout<<a[i]<<endl;

   }


}
