#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
typedef struct node *NODE;
NODE getnode();
NODE push(NODE head, int item);
NODE pop(NODE head);
void display(NODE head);
int main()
{
NODE head = NULL;
int item,ch,ch1,count=0,size;
printf("Enter the number of elements\n");
scanf("%d",&size);
do
{
printf("Enter\n1 for push operation\n2 for pop operation\n3 to display stack\n");
scanf("%d",&ch);
switch(ch)
{
case 1: { printf("Enter item to be pushed\n");
	  scanf("%d",&item);
	  count++;
	  if(count>size)
	  {
	  printf("\nStack overflow\n");
	  exit(0);
	  }
	  head = push(head,item);
	  break; }
case 2: { head = pop(head);
	  count--;
	  break; }
case 3: { printf("\nContents of the stack are\n");
	  display(head);
	  break; }
default: printf("\nInvalid Choice\n");
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
{
return p;
}
else 
{
printf("Memory could not be allocated");
exit(0);
}
}
NODE push(NODE head, int item)
{
NODE p;
p=getnode();
p->data = item;
if(head==NULL)
{
p->next = NULL;
head = p;
return head;
}
else
{
p->next = head;
head = p;
return head;
}
}
NODE pop(NODE head)
{
NODE p = head;
if(head==NULL)
{
printf("\nStack underflow\n");
return head;
}
printf("\nThe popped element = %d",p->data);
head = p->next;
free(p);
return head;
}
void display(NODE head)
{
NODE p;
if(head==NULL)
{
printf("\nStack is empty\n");
exit(0);
}
p = head;
while(p!=NULL)
{
printf("%d\n",p->data);
p = p->next;
}
}  

