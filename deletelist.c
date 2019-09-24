#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
typedef struct node *NODE;
NODE getnode();
NODE insertfront(int item, NODE head);
NODE insertpos(NODE head, int item, int pos);
void insertend(int item, NODE head);
NODE deletefront(NODE head);
void deleteend(NODE head);
void deleteval(NODE head, int item);
void display(NODE head);
int main()
{
NODE head;
head = NULL;
int item,pos,ch,ch1,e;
do
{
printf("Enter\n1 for insertion at front\n2 for insertion at a given position\n3 for insertion at end\n4 to delete the element at front\n5 to delete a given value from the list\n6 to delete the element at the end\n7 to display the contents of the list\n");
scanf("%d",&ch);
switch(ch)
{
case 1:{ printf("Enter the item to be inserted at the front\n");
	 scanf("%d",&item);
	 head = insertfront(item,head);
	 break; }
case 2:{ printf("Enter the position of insertion\n");
	 scanf("%d",&pos);
	 printf("Enter the item to be inserted at position %d\n",pos);
	 scanf("%d",&item);
	 head = insertpos(head,item,pos);
	 break; }
case 3:{ printf("Enter the item to be inserted at the end\n");
	 scanf("%d",&item);
	 insertend(item,head);
	 break; }
case 4:{ head=deletefront(head);
	 break; }
case 5:{ printf("Enter the item to be deleted from the linked list\n");
	 scanf("%d",&item);
	 deleteval(head,item);
	 break; }
case 6:{ deleteend(head);
	 break; }
case 7:{ printf("\nContents of the linked list are\n");
	 display(head);
	 printf("\n");
	 break; }
default: printf("\nInvalid Input\n");
}
printf("\nEnter any value to continue and 1 to exit\n");
scanf("%d",&ch1);
}while(ch1!=1);
return 0;
}
NODE getnode()
{
NODE p;
p = (NODE)malloc(sizeof(struct node));
if(p!=NULL)
{
return p;
}
else 
{
printf("\nMemory could not be allocated\n");
exit(0);
}
}
void display(NODE head)
{
NODE p;
if(head==NULL)
{
printf("\nList is empty\n");
exit(0);
}
p = head;
while(p!=NULL)
{
printf("%d ",p->data);
p=p->next;
}
}
NODE insertfront(int item, NODE head)
{
NODE p;
p=getnode();
p->data = item;
p->next = head;
head = p;
return head;
}
NODE insertpos(NODE head, int item, int pos)
{
NODE curr,prev=NULL,newn;
int count = 1;
newn = getnode();
newn->data = item;
newn->next = NULL;
if(head==NULL)
{
if(pos==1)
{
return newn;
}
else
{
printf("\nInvalid Position\n");
return head;
}
}
if(pos==1)
{
newn->next=head;
head=newn;
return head;
}
else 
{
curr = head;
while(curr!=NULL && count!=pos)
{
prev = curr;
curr = curr->next;
count++;
}
if(count==pos)
{
prev->next = newn;
newn->next = curr;
return head;
}
else
{
printf("\nInvalid Position\n");
return head;
}
}
}
void insertend(int item, NODE head)
{
NODE p,q;
q=getnode();
q->data = item;
p=head;
while(p->next!=NULL)
{
p=p->next;
}
p->next=q;
q->next=NULL;
}
NODE deletefront(NODE head)
{
NODE p=head;
if(head==NULL)
{
printf("\nList is empty\n");
return head;
}
printf("\nThe element deleted at the front of the list = %d",p->data);
head=p->next;
free(p);
return head;
}
void deleteend(NODE head)
{
NODE p=head,q;
if(head==NULL)
{
printf("\nList is empty");
return;
}
while(p->next!=NULL)
{
q=p;
p=p->next;
}
printf("\nThe element deleted from the end = %d\n",p->data);
q->next=NULL;
free(p);
}
void deleteval(NODE head, int item)
{
NODE p=head,q;
int pos=1;
if(p!=NULL && p->data==item)
{
printf("\nThe element %d is deleted from the position %d\n",p->data,pos);
head=p->next;
free(p);
return;
}
while(p!=NULL && p->data!=item)
{
q=p;
p=p->next;
pos++;
}
if(p==NULL)
{
printf("\nThe element %d is not present in the list\n",item);
return;
}
printf("\nThe element %d is deleted from position %d\n",p->data,pos);
q->next=p->next;
free(p);
}


