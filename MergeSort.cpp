#include<stdio.h>
#include<iostream>
#include<cmath>
#include<stdlib.h>

using namespace std;
void merge(int a[],int hi,int mid,int lo)
{
    int n1=mid-lo+1;
    int n2=hi-mid;
    int L[n1];
    int R[n2];
int i,j;
for( i=0;i<n1;i++)
{
    L[i]=a[i+lo];

}
for( j=0;j<n2;j++)
{
    R[j]=a[j+mid+1];

}
 i=j=0;
int k=lo;
    while((i<n1)&&(j<n2))
    {
        if(L[i]<R[j])
        {a[k]=L[i];
        i++;
        k++;

        }
        else if(R[j]<L[i])
        {
            a[k]=R[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
       a[k]=R[j];
            j++;
            k++;
    }

}
void mergesort(int a[],int hi,int lo)
{
    if(hi>lo)
    { int mid=lo+(hi-lo)/2;
        mergesort(a,mid,lo);
        mergesort(a,hi,mid+1);
        merge(a,hi,mid,lo);

    }

}
int main()
{ int asize;
    printf("Enter array size:");
    scanf("%d",&asize);
    int a[asize];

    for(int i=0;i<asize;i++)
    {
         a[i]=rand()%20;
    }
    cout<<"Array elements unsorted:"<<endl;

    for(int i=0;i<asize;i++)
    {
        printf(" %d",a[i]);
    }
    mergesort(a,asize-1,0);
cout<<"After sorting:"<<endl;
    for(int i=0;i<asize;i++)
    {
        printf(" %d",a[i]);
    }



}
