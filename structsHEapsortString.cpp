
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<cstring>
static int heapsize;
using namespace std;
struct Info
{
    int id;
    int num;
    char name[100];

};
int LEFT(int i)
{
    return 2*i+1;
}
int RIGHT(int i)
{

    return 2*i+2;
}
int MAX_HEAPIFY(struct Info a[],int i )
{
    int largest=i;

    int l=LEFT(i);
    int r=RIGHT(i);
    if((l<=heapsize)&&(strcmp(a[largest].name,a[l].name)<0))
       {
           largest=l;
       }
       if((r<=heapsize)&&(strcmp(a[largest].name,a[r].name)<0))
       {
           largest=r;
       }
       if(i!=largest)
        {
            swap(a[i],a[largest]);
             MAX_HEAPIFY(a,largest);
        }

}

void BUILDMAXHEAP(struct Info a[])
{ int x=heapsize/2;
    for(int i=x;i>=0;i--)
    {
        MAX_HEAPIFY(a,i);
    }
}
int HEAPSORT(struct Info a[])
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
struct Info a[n];
int nameconvert[n];
heapsize=n-1;
printf("Enter array elements id n name:");
for(int i=0;i<n;i++)
{

cin>>a[i].id>>a[i].name;
}

printf("The array after sorting is:");
HEAPSORT(a);
for(int i=0;i<n;i++)
{

    puts("");
    cout<<a[i].name<<" "<<a[i].id<<endl;




}

}
