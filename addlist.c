#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
typedef struct node *NODE;
NODE insert(NODE head, int item);
NODE getnode();
NODE sort(NODE head);
NODE reverse(NODE head);
void display(NODE head);
NODE concatenate(NODE head1, NODE head2);
int main()
{
int item,ch,ch1,n,i,n1,ch2;
NODE head1 = NULL;
NODE head2 = NULL;
do
{
printf("\nEnter\n1 to insert in first list\n2 to insert in second list\n3 for sorting\n4 to reverse\n5 to concatenate two lists\n6 to display\n");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter number of elements to be inserted into the first list\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
	{
	scanf("%d",&item);
	head1 = insert(head1,item);
	}
	break;
case 2: printf("Enter number of elements to be inserted into the second list\n");
	scanf("%d",&n1);
	printf("Enter the elements\n");
	for(i=0;i<n1;i++)
	{
	scanf("%d",&item);
	head2 = insert(head2,item);
	}
	break;
case 3: printf("Enter\n1 to sort first list\n2 to sort second list\n");
	scanf("%d",&ch2);
	switch(ch2)
	{
	case 1: head1 = sort(head1);
		printf("\nList has been sorted\n");
		break;
	case 2: head2 = sort(head2);
		printf("\nList has been sorted\n");
		break;
	default: printf("\nInvalid choice\n");
	}
	break;
case 4: printf("Enter\n1 to reverse first/concatenated list\n2 to reverse second list\n");
	scanf("%d",&ch2);
	switch(ch2)
	{
	case 1: head1 = reverse(head1);
		printf("\nList has been reversed\n");
		break;
	case 2: head2 = reverse(head2);
		printf("\nList has been reversed\n");
		break;
	default: printf("\nInvalid choice\n");
	}
	break;
case 5: printf("The list after concatenation of two lists is\n");
	head1 = concatenate(head1,head2);
	display(head1);
	break;
case 6: printf("Enter\n1 to display first/concatenated list\n2 to display second list\n");
	scanf("%d",&ch2);
	switch(ch2)
	{
	case 1: display(head1);
		break;
	case 2: display(head2);
		break;
	default: printf("\nInvalid choice\n");
	}
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
p = (NODE)malloc(sizeof(struct node));
if(p!=NULL)
return p;
else
{
printf("\nMemory could not be allocated\n");
exit(0);
}
}
NODE insert(NODE head, int item)
{
NODE p,q;
q = getnode();
q->data = item;
if(head==NULL)
{
q->next = NULL;
head = q;
return head;
}
else
{
p = head;
while(p->next!=NULL)
{
p = p->next;
}
p->next = q;
q->next = NULL;
return head;
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
printf("\nContents of the list are\n");
while(p!=NULL)
{
printf("%d ",p->data);
p = p->next;
}
}
}
NODE sort(NODE head)
{
NODE p = head, q = NULL;
int temp;
if(head==NULL)
{
printf("\nList is empty\n");
return head;
}
else
{
while(p->next!=NULL)
{
q = p->next;
while(q!=NULL)
{
if(p->data>q->data)
{
temp = p->data;
p->data = q->data;
q->data = temp;
}
q = q->next;
}
p = p->next;
}
}
return head;
}
NODE reverse(NODE head)
{
NODE curr = head, prev = NULL, nextn = NULL;
if(head == NULL)
{
printf("\nList is empty\n");
return head;
}
else if(head->next==NULL)
{
return head;
}
else
{
while(curr!=NULL)
{
nextn = curr->next;
curr->next = prev;
prev = curr;
curr = nextn;
}
}
head = prev;
return head;
}
NODE concatenate(NODE head1, NODE head2)
{
NODE p;
if(head1==NULL)
return head2;
if(head2==NULL)
return head1;
p = head1;
while(p->next!=NULL)
{
p = p->next;
}
p->next = head2;
return head1;
}

/*Enter
1 to insert in first list
2 to insert in second list
3 for sorting
4 to reverse
5 to concatenate two lists
6 to display
1
Enter number of elements to be inserted into the first list
3
Enter the elements
2 4 1

Enter 1 to exit and any other value to continue
2

Enter
1 to insert in first list
2 to insert in second list
3 for sorting
4 to reverse
5 to concatenate two lists
6 to display
3
Enter
1 to sort first list
2 to sort second list
1

List has been sorted

Enter 1 to exit and any other value to continue
2

Enter
1 to insert in first list
2 to insert in second list
3 for sorting
4 to reverse
5 to concatenate two lists
6 to display
6
Enter
1 to display first/concatenated list
2 to display second list
1

Contents of the list are
1 2 4 
Enter 1 to exit and any other value to continue
2

Enter
1 to insert in first list
2 to insert in second list
3 for sorting
4 to reverse
5 to concatenate two lists
6 to display
2
Enter number of elements to be inserted into the second list
3
Enter the elements
5 2 3

Enter 1 to exit and any other value to continue
2

Enter
1 to insert in first list
2 to insert in second list
3 for sorting
4 to reverse
5 to concatenate two lists
6 to display
4
Enter
1 to reverse first/concatenated list
2 to reverse second list
2

List has been reversed

Enter 1 to exit and any other value to continue
2

Enter
1 to insert in first list
2 to insert in second list
3 for sorting
4 to reverse
5 to concatenate two lists
6 to display
5
The list after concatenation of two lists is

Contents of the list are
1 2 4 3 2 5 
Enter 1 to exit and any other value to continue
1*/


