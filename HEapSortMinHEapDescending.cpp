
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
    int smallest=i;

    int l=LEFT(i);
    int r=RIGHT(i);
    if((l<=heapsize)&&(a[smallest]>a[l]))
       {
           smallest=l;
       }
       if((r<=heapsize)&&(a[smallest]>a[r]))
       {
           smallest=r;
       }
       if(i!=smallest)
        {
            swap(a[i],a[smallest]);
             MAX_HEAPIFY(a,smallest);
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
