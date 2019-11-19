#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *prev;
struct node *next;
};
typedef struct node *NODE;
NODE getnode();
NODE insertpos(NODE head, int item, int pos);
NODE insertend(int item, NODE head);
NODE deleteval(NODE head, int item);
void display(NODE head);
int main()
{
NODE head;
head = NULL;
int item,ch,ch1,val;
do
{
printf("Enter\n1 for insertion to the doubly linked list\n2 for insertion to the left of a given node\n3 to delete a given value from the list\n4 to display the contents of the list\n");
scanf("%d",&ch);
switch(ch)
{
case 1:{ printf("Enter the item to be inserted\n");
	 scanf("%d",&item);
	 head = insertend(item,head);
	 break; }
case 2:{ printf("Enter the value of the node to the left of which element is to be inserted\n");
	 scanf("%d",&val);
	 printf("Enter the item to be inserted at position\n");
	 scanf("%d",&item);
	 head = insertpos(head,item,val);
	 break; }
case 3:{ printf("Enter the item to be deleted from the linked list\n");
	 scanf("%d",&item);
	 head = deleteval(head,item);
	 break; }
case 4:{ printf("\nContents of the linked list are\n");
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
NODE insertpos(NODE head, int item, int val)
{
NODE p,q,temp;
p=getnode();
p->data=item;
if(head==NULL)
{
printf("Value cant be inserted \n");
return head;
}
if(head->data==val)
{
p->next=head;
p->prev=NULL;
head=p;
return p;
}
q=head;
while(q->next!=NULL)
{
temp=q;
q=q->next;
if(q->data==val)
{
temp->next=p;
p->prev=temp;
p->next=q;
q->prev=p;
return head;
}
}
if(q->next==NULL)
{
printf("Given node value doesnt exist\n");
return head;
}
}
NODE insertend(int item, NODE head)
{
NODE p,q;
q=getnode();
q->data = item;
if(head==NULL)
{
q->next=NULL;
q->prev=NULL;
head=q;
}
else
{
p=head;
while(p->next!=NULL)
{
p=p->next;
}
p->next=q;
q->prev=p;
q->next=NULL;
}
return head;
}
NODE deleteval(NODE head,int item)
{
NODE p=head,q;
if(head==NULL)
{
printf("List is empty\n");
return head;
}
if(head->next==NULL)
{
if(head->data==item)
{
head=head->next;
free(p);
head->prev=NULL;
return head;
}
else
{
printf("Value doesnt exist\n");
return head;
}
}
q=head;
if(head->data==item)
{
head=head->next;
free(p);
head->prev=NULL;
return head;
}
while(q->next!=NULL)
{
p=q;
q=q->next;
if(q->data==item)
{
p->next=q->next;
q->next->prev=q->prev;
free(q);
return head;
}
}
if(q->next==NULL)
{
printf("Value doesnt exist\n");
return head;
}
}

/*Enter
1 for insertion to the doubly linked list
2 for insertion to the left of a given node
3 to delete a given value from the list
4 to display the contents of the list
1
Enter the item to be inserted
3

Enter any value to continue and 1 to exit
2
Enter
1 for insertion to the doubly linked list
2 for insertion to the left of a given node
3 to delete a given value from the list
4 to display the contents of the list
1
Enter the item to be inserted
5

Enter any value to continue and 1 to exit
2
Enter
1 for insertion to the doubly linked list
2 for insertion to the left of a given node
3 to delete a given value from the list
4 to display the contents of the list
1
Enter the item to be inserted
6

Enter any value to continue and 1 to exit
2
Enter
1 for insertion to the doubly linked list
2 for insertion to the left of a given node
3 to delete a given value from the list
4 to display the contents of the list
2
Enter the value of the node to the left of which element is to be inserted
5
Enter the item to be inserted at position 21981
4

Enter any value to continue and 1 to exit
2
Enter
1 for insertion to the doubly linked list
2 for insertion to the left of a given node
3 to delete a given value from the list
4 to display the contents of the list
4

Contents of the linked list are
3 4 5 6 

Enter any value to continue and 1 to exit
2
Enter
1 for insertion to the doubly linked list
2 for insertion to the left of a given node
3 to delete a given value from the list
4 to display the contents of the list
3
Enter the item to be deleted from the linked list
5

Enter any value to continue and 1 to exit
2
Enter
1 for insertion to the doubly linked list
2 for insertion to the left of a given node
3 to delete a given value from the list
4 to display the contents of the list
4

Contents of the linked list are
3 4 6 

Enter any value to continue and 1 to exit
1*/



