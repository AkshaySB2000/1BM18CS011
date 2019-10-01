#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
typedef struct node *NODE;
NODE getnode();
NODE enqueue(NODE head, int item);
NODE dequeue(NODE head);
void display(NODE head);
int main()
{
NODE head = NULL;
int item,ch,ch1,count=0,size;
printf("Enter the number of elements\n");
scanf("%d",&size);
do
{
printf("Enter\n1 for insertion operation\n2 for deletion operation\n3 to display queue\n");
scanf("%d",&ch);
switch(ch)
{
case 1: { printf("Enter item to be inserted\n");
	  scanf("%d",&item);
	  count++;
	  if(count>size)
	  {
	  printf("\nQueue is full\n");
	  exit(0);
	  }
	  head = enqueue(head,item);
	  break; }
case 2: { head = dequeue(head);
	  break; }
case 3: { printf("\nContents of the queue are\n");
	  display(head);
	  break; }
default: printf("\nInvalid Choice\n");
}
printf("\nEnter 1 to exit and any other value to exit\n");
scanf("%d",&ch1);
}while(ch1!=1);
return 0;
}
NODE getnode()
{
NODE p;
p=(NODE)malloc(sizeof(struct node));
if(p!=NULL)
{
return p;
}
else 
{
printf("Memory could not be allocated");
exit(0);
}
}
NODE enqueue(NODE head, int item)
{
NODE p,q;
q=getnode();
q->data = item;
p=head;
if(head==NULL)
{
q->next=NULL;
head = q;
return head;
}
while(p->next!=NULL)
{
p=p->next;
}
p->next=q;
q->next=NULL;
return head;
}
NODE dequeue(NODE head)
{
NODE p = head;
if(head==NULL)
{
printf("\nQueue is empty\n");
return head;
}
printf("\nThe deleted element = %d",p->data);
head = p->next;
free(p);
return head;
}
void display(NODE head)
{
NODE p;
if(head==NULL)
{
printf("\nQueue is empty\n");
exit(0);
}
p = head;
while(p!=NULL)
{
printf("%d\n",p->data);
p = p->next;
}
}  

