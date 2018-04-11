#include<stdio.h>
int max,min;
int a[100];

void maxmin(int i,int j)
{
 if(i==j)
 {
   max=min=a[i];
 }

 else
 {
   if(i==j-1)
   {
     if(a[i]<a[j])
     {
       max=a[j];
       min=a[i];
     }
     else
     {
       max=a[i];
       min=a[j];
     }
   }

   else
   {
     int mid,max1,min1;
     mid=(i+j)/2;
     maxmin(i,mid);
     max1=max;
     min1=min;
     maxmin(mid+1,j);
     if(max<max1)
     max=max1;
     if(min>min1)
     min=min1;
   }
 }
}

int main()
{
 int i,num;
 printf("\nEnter the no. of elements : ");
 scanf("%d",&num);
 printf("\nEnter the elements : \n");
 for(i=1;i<=num;i++)
 scanf("%d",&a[i]);
 max=a[0];
 min=a[0];
 maxmin(1,num);
 printf("\nMaximum Element :%d",max);
 printf("\nMinimum Element :%d\n",min);
 return 0;
}
