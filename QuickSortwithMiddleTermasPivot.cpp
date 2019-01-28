
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<stdlib.h>

using namespace std;


int partition(int a[],int lo,int hi)
{  int pivot=a[hi];
    int i=lo-1;
    int temp2;
    for(int j=lo;j<=hi-1;j++)
    { if(a[j]<=pivot)
    {
        i++;
       swap(a[i],a[j]);




    }
    }
  swap(a[i+1],a[hi]);

    return i+1;


    }

 int partition_Mid(int a[],int lo,int hi)
 {
     int mid=(hi+lo)/2;

     swap(a[hi],a[mid]);
     return partition(a,lo,hi);


 }
void QuickSort(int a[],int lo,int hi)
{ if(lo<hi)
{
    int p=partition_Mid(a,lo,hi);
    QuickSort(a,lo,p-1);
    QuickSort(a,p+1,hi);

}


}


int main()
{
int asize;
 printf("Enter size of the array:");
    scanf("%d",&asize);
int a[asize];
    int lo,hi;



    printf("Enter array elements: ");

    for(int i=0;i<asize;i++)
    {

      a[i]=rand()%10;
    }
    puts(" ");
cout<<"Before sorting:"<<endl;
for(int i=0;i<asize;i++)
    {

        printf("%d ",a[i]);
    }
    QuickSort(a,0,asize-1);
    puts("");
cout<<"After sorting:"<<endl;
for(int i=0;i<asize;i++)
{

    cout<<a[i]<<endl;
}


}
