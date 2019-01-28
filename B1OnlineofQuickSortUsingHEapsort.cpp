#include<stdio.h>
#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

static int heapsize;

struct Info
{
    float id;
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
int MAXHEAPIFY(struct Info a[],int i)
{
    int l=LEFT(i);
    int r=RIGHT(i);

    int largest=i;

    if((l<=heapsize)&&(a[l].id<a[largest].id))
    {
        largest=l;
    }
    if((r<=heapsize)&&(a[r].id<a[largest].id))
    {
        largest=r;
    }
    if(i!=largest)
    {
        swap(a[i],a[largest]);
        MAXHEAPIFY(a,largest);
    }

}
int BUILDMAXHEAP(struct Info a[])
{
    for(int i=heapsize/2;i>=0;i--)
    {
        MAXHEAPIFY(a,i);
    }
}

int HEAPSORT(struct Info a[])
{ int sizee=heapsize;
    BUILDMAXHEAP(a);

    for(int i=0;i<sizee;i++)
    {
        swap(a[0],a[heapsize]);
        heapsize--;
        MAXHEAPIFY(a,0);


    }

}
int main()
{
    int n=4;
    heapsize=n-1;
  struct Info a[n];
  printf("Enter array elements:");
  for(int i=0;i<n;i++)
  {  cin>>a[i].id;
  cin>>a[i].name;

  }

  HEAPSORT(a);
  printf("The elements after sorting is:");

  for(int i=0;i<n;i++)
  {
      for(int j=i+1;j<n;j++)
      {
          if(a[i].id==a[j].id)
          {
              if(strcmp(a[i].name,a[j].name)<0)
              {
                  swap(a[i],a[j]);
              }
          }
      }
  }

  for(int i=0;i<n;i++)
  {
      cout<<a[i].id<<" "<<a[i].name<<endl;
  }
}
