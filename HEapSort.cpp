#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<cmath>
static int heapsize;
using namespace std;
int LEFT(int i)
{
    return 2*i+1;
}
int RIGHT(int i)
{

    return 2*i+2;
}
int MAX_HEAPIFY(int a[],int i )
{
    int largest=i;

    int l=LEFT(i);
    int r=RIGHT(i);
    if((l<=heapsize)&&(a[largest]<a[l]))
       {
           largest=l;
       }
       if((r<=heapsize)&&(a[largest]<a[r]))
       {
           largest=r;
       }
       if(i!=largest)
        {
            swap(a[i],a[largest]);
             MAX_HEAPIFY(a,largest);
        }

}

void BUILDMAXHEAP(int a[])
{ int x=heapsize/2;
    for(int i=x;i>=0;i--)
    {
        MAX_HEAPIFY(a,i);
    }
}
int HEAPSORT(int a[])
{  BUILDMAXHEAP(a);
    int sizea=heapsize;

    for(int i=0;i<sizea;i++)
    {
        swap(a[0],a[heapsize]);
        heapsize--;
        MAX_HEAPIFY(a,0);
    }

}
int main()
{ int n=5;
int a[n];
heapsize=n-1;
printf("Enter array elements:");
for(int i=0;i<n;i++)
{
   scanf("%d",&a[i]);

}
printf("The array after sorting is:");
HEAPSORT(a);
for(int i=0;i<n;i++)
{
    printf(" %d",a[i]);

}

}
