#include<stdio.h>
#define size 50
void qinsert(int q[], int bt[], int *, int, int);
int qdelete(int q[], int *, int *);
void qdisplay(int q[], int bt[], int, int, int);
int main()
{
int q[size],bt[size],f=0,r=-1,n,i,t[size];
printf("Enter the number of processes to be executed\n");
scanf("%d",&n);
printf("\n");
for(i=0;i<n;i++)
{
printf("Enter burst time for process P%d\n",i);
scanf("%d",&t[i]);
qinsert(q,bt,&r,i,t[i]);
}
printf("\n");
qdisplay(q,bt,f,r,n);
for(i=0;i<n;i++)
{
qdelete(q,&f,&r);
}
getch();
return 0;
}
void qinsert(int q[size], int bt[size], int *r, int item, int item1)
{
if(*r==size-1)
{
printf("Queue is full\n");
return;
}
*r=*r+1;
q[*r]=item;
bt[*r]=item1;
}
int qdelete(int q[size], int *f, int * r)
{
int item;
if(*f>*r)
{
printf("Queue is empty\n");
return -9999;
}
item=q[*f];
*f=*f+1;
return item;
}
void qdisplay(int q[size], int bt[size], int f, int r, int n)
{
int i,wt[size];
if(f>r)
{
printf("Queue is empty");
return;
}
if(n==1)
{
printf("Execution of process P0 starts at 0 s and ends at %d s\n",bt[0]);
}
else
{
wt[0]=bt[0];
printf("Execution of process P0 Starts at 0 s and ends at %d s\n",bt[0]);
for(i=f+1;i<=r;i++)
{
wt[i]=bt[i]+wt[i-1];
printf("Execution of process P%d Starts at %d s and ends at %d s\n",q[i],wt[i-1],wt[i]);
}
}
}


