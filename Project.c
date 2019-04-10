#include<conio.h>
#include<stdio.h>
int main()
{
 int n; 
 int r;      
 int i,j,k,cnt,cntt,pro;
 int avail[10],p[10],sequence[10],count=0;
 int need[10][10],alloc[10][10],max[10][10];

 printf("\nEnter number of process :");
 scanf("%d",&n);
 printf("\n Enter  resources available : ");
 scanf("%d",&r);
 printf("\nEnter insatnces for resources :\n");
 for(i=0;i<r;i++)
 {  printf("R%d ",i+1);
  scanf("%d",&avail[i]);
  }
 printf("\n Enter allocation matrix  \n");
 for(i=0;i<n;i++)
 {
 printf("p%d",i+1);          p[i]=0;
 for(j=0;j<r;j++)
 {
  scanf("%d",&alloc[i][j]);
 }
}
  printf("\n Enter MAX matrix  \n");

 for(i=0;i<n;i++)
 {
 printf("p%d",i+1);
 for(j=0;j<r;j++)
 {
  scanf("%d",&max[i][j]);
 }
 }

 for(i=0;i<n;i++)
 {
 printf("\np%d\t",i+1) ;
 for(j=0;j<r;j++)
 {
  need[i][j]=max[i][j]-alloc[i][j];
  printf("\t%d",need[i][j]);
  }
 }
 k=0;     cntt=0;
do
{
printf("\n\n Pro\t\tAllocationocation\t\tMaximumimum\n");
for(i=0;i<n;i++)
{
printf("P[%d]\t\t",i+1);
for(j=0;j<r;j++)
{
printf("%d\t\t",alloc[i][j]);
printf("%d\n",max[i][j]);
}
}
pro=-1;
for(i=0;i<n;i++)
{
if(p[i]==0)
{
pro=i;
for(j=0;j<r;j++)
{
if(avail[j]<need[i][j])
{
pro=-1;
break;
}
}
}
if(pro!=-1)
break;
}
if(pro!=-1)
{
printf("P[%d] runs successfully",pro+1);
sequence[i]=pro+1;
count++;
for(j=0;j<r;j++)
{
avail[j]=avail[j]+alloc[pro][j];
alloc[pro][j]=0;
max[pro][j]=0;
p[j]=1;
}
}
}
while(count!=n&&pro!=-1);
if(count==n)
{
printf("\n The system is in a safe state");
}
else
printf("\n The system is in deadlock");

}


