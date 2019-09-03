#include<stdio.h>
void qinsert(int q[], int *, int *, int, int);
int qdelete(int q[], int *, int *, int);
void qdisplay(int q[], int, int, int);
int main()
{
int item,ch,ch1,q[50],e,f=-1,r=-1,size;
printf("Enter size of the queue\n");
scanf("%d",&size);
do
{
printf("\nEnter your choice\n");
printf("1 for insertion\n2 for deletion\n3 for display\n");
scanf("%d",&ch);
switch(ch)
{
case 1: { printf("\nEnter the item to be inserted\n");
          scanf("%d",&item);
          qinsert(q,&r,&f,item,size);
          break;}
case 2: { e=qdelete(q,&f,&r,size);
	  printf("\nThe element deleted from the queue = %d\n",e);
          break;}
case 3: { qdisplay(q,f,r,size);
          break;}
default: printf("\nInvalid input\n");
}
printf("Enter 1 to continue queue operations and any other value to exit\n");
scanf("%d",&ch1);
}while(ch1==1);
return 0;
}
void qinsert(int q[], int *r, int *f, int item, int size)
{
if((*f==*r+1)||(*f==0 && *r==size-1))
{
printf("\nQueue is full\n");
return;
}
if(*r==-1)
*f=0;
*r=(*r+1)%size;
q[*r]=item;
}
int qdelete(int q[], int *f, int *r, int size)
{
int item;
if(*f==-1)
{
printf("\nQueue is empty\n");
return -9999;
}
else
{
item=q[*f];
if(*f==*r)
{
*f=-1;
*r=-1;
}
else
*f=(*f+1)%size;
}
return item;
}
void qdisplay(int q[], int f, int r, int size)
{
int i; 
if(f==-1)
{
printf("\nQueue is empty");
return;
}
printf("\nContents of the queue are\n");
for(i=f;i!=r;i=(i+1)%size)
{
printf("%d ",q[i]);
}
printf("%d",q[i]);
printf("\n");
}

