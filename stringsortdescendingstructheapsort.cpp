
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
int MIN_HEAPIFY(struct Info a[],int i )
{
    int smallest=i;

    int l=LEFT(i);
    int r=RIGHT(i);
    if((l<=heapsize)&&(strcmp(a[smallest].name,a[l].name)>0))
       {
           smallest=l;
       }
       if((r<=heapsize)&&(strcmp(a[smallest].name,a[r].name)>0))
       {
           smallest=r;
       }
       if(i!=smallest)
        {
            swap(a[i],a[smallest]);
             MIN_HEAPIFY(a,smallest);
        }

}

void BUILDMINHEAP(struct Info a[])
{ int x=heapsize/2;
    for(int i=x;i>=0;i--)
    {
        MIN_HEAPIFY(a,i);
    }
}
int HEAPSORT(struct Info a[])
{  BUILDMINHEAP(a);
    int sizea=heapsize;

    for(int i=0;i<sizea;i++)
    {
        swap(a[0],a[heapsize]);
        heapsize--;
        MIN_HEAPIFY(a,0);
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
