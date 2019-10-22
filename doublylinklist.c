#include<stdio.h>
#include<stdlib.h>
struct node 
{
int data;
struct node *next;
struct node *prev;
};
typedef struct node *NODE;
NODE getnode();
NODE insertleft(NODE head, NODE n, int item);
NODE deleteval(NODE head, int item);
void display(NODE head);
int main()
{
int item,ch,ch1,c=0,i,count=0;
NODE head = NULL,p;
do
{
printf("Enter\n1 to insert to the left of a node\n2 to delete a given value\n3 to display the contents of the list\n");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter the item to be inserted\n");
	scanf("%d",&item);
	if(count==0)
	{
	head = insertleft(head,head,item);
	count++;
	}	
	else
	{
	printf("Enter the node to the left of which item is to be inserted\n");
	scanf("%d",&i);
	if(i==1)
	{
	head = insertleft(head,head,item);
	count++;
	}
	else
	{
	p = head;
	while(p!=NULL)
	{
	c++;
	if(c==i)
	{
	head = insertleft(head,p,item);	
	count++;
	}
	p = p->next;
	}
	c=0;
	}
	}
	break;
case 2: printf("Enter the value to be deleted from the list\n");
	scanf("%d",&item);
	head = deleteval(head,item);
	break;
case 3: printf("\nThe contents of the list are\n");
	display(head);
	break;
default: printf("\nInvalid choice\n");
}
printf("\nEnter 1 to exit and any other value to continue\n");
scanf("%d",&ch1);
}while(ch1!=1);
return 0;
}
NODE getnode()
{
NODE p;
p=(NODE)malloc(sizeof(struct node));
if(p!=NULL)
return p;
else
{
printf("\nMemory could not be allocated\n");
exit(0);
}
}
NODE insertleft(NODE head, NODE n, int item)
{
NODE p = getnode();
p->data = item;
if(head==NULL)
{
p->next = NULL;
p->prev = NULL;	
head = p;
return head;
}
else if(head==n)
{
p->next = n;
n->prev = p;
p->prev = NULL;
head = p;
return head;
}
else
{
n->prev->next = p;
p->prev = n->prev;
p->next = n;
n->prev = p;
return head;
}
}
NODE deleteval(NODE head, int item)
{
NODE p;
int pos = 0;
if(head==NULL)
{
printf("\nList is empty\n");
return head;
}
else if(head->next==NULL)
{
if(head->data==item)
{
printf("\n%d is deleted from position %d\n",head->data,(pos+1));
free(head);
return NULL;
}
else
{
printf("\nElement not found\n");
return head;
}
}
else
{
p = head;
while(p!=NULL)
{
pos++;
if(p->data==item)
{
if(p->prev!=NULL)
p->prev->next = p->next;
else
head = p->next;
if(p->next!=NULL)
p->next->prev = p->prev;
printf("\n%d is deleted from position %d\n",p->data,pos);
free(p);
return head;
}
p = p->next;
}
if(p==NULL)
printf("%d not found in the list",item);
}
}
void display(NODE head)
{
NODE p = head;
if(head==NULL)
{
printf("\nList is empty\n");
return;
}
else
{
while(p!=NULL)
{
printf("%d ",p->data);
p = p->next;
}
}
}

