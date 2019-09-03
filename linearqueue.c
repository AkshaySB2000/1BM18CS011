#include<stdio.h>
#define size 50
void qinsert(int q[], int *, int);
int qdelete(int q[], int *, int *);
void qdisplay(int q[], int, int);
int main()
{
int item,ch,ch1,q[size],e,f=0,r=-1;
do
{
printf("\nEnter your choice\n");
printf("1 for insertion\n2 for deletion\n3 for display\n");
scanf("%d",&ch);
switch(ch)
{
case 1: { printf("\nEnter the item to be inserted\n");
          scanf("%d",&item);
          qinsert(q,&r,item);
          break;}
case 2: { e=qdelete(q,&f,&r);
	  printf("\nThe element deleted from the queue = %d\n",e);
          break;}
case 3: { qdisplay(q,f,r);
          break;}
default: printf("\nInvalid input\n");
}
printf("Enter 1 to continue queue operations and any other value to exit\n");
scanf("%d",&ch1);
}while(ch1==1);
return 0;
}
void qinsert(int q[size], int *r, int item)
{
if(*r==size-1)
{
printf("\nQueue is full");
return;
}
*r=*r+1;
q[*r]=item;
}
int qdelete(int q[size], int *f, int *r)
{
int item;
if(*f>*r)
{
printf("\nQueue is empty");
return -9999;
}
item=q[*f];
*f=*f+1;
return item;
}
void qdisplay(int q[size], int f, int r)
{
int i; 
if(f>r)
{
printf("\nQueue is empty");
return;
}
printf("\nContents of the queue are\n");
for(i=f;i<=r;i++)
{
printf("%d ",q[i]);
}
printf("\n");
}

 

