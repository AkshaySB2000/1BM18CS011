#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *lchild;
struct node *rchild;
};
typedef struct node *NODE;
NODE getnode(int item);
NODE insert(NODE root, int item);
NODE delet(NODE root, int key);
void inorder(NODE root);
void preorder(NODE root);
void postorder(NODE root);
void printGivenLevel(struct node* root, int level);
void levelorder(NODE root);
int height(NODE root);
int main()
{
int ch,item,n,i,ch1;
NODE root = NULL;
printf("Enter number of nodes to be inserted\n");
scanf("%d",&n);
printf("Enter the elements\n");
for(i=0;i<n;i++)
{
scanf("%d",&item);
root = insert(root,item);
} 
do
{
printf("\nEnter\n1 for inorder traversal\n2 for preorder traversal\n3 for postorder traversal\n");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\nElements in inorder traversal\n");
	inorder(root); 
	break;
case 2: printf("\nElements in preorder traversal\n");
	preorder(root); 
	break;
case 3: printf("\nElements in postorder traversal\n");
	postorder(root); 
	break;
default: printf("\nInvalid choice\n");
}
printf("\nEnter 1 to exit and any other value to continue\n");
scanf("%d",&ch1);
}while(ch1!=1);
printf("\nNodes in level order\n");
levelorder(root);
return 0;
}
NODE getnode(int item)
{
NODE p;
p = (NODE)malloc(sizeof(struct node));
p->data = item;
p->lchild = NULL;
p->rchild = NULL;
return p;
}
NODE insert(NODE root, int item)
{
if(root==NULL)
return getnode(item);
if(item<root->data)
root->lchild = insert(root->lchild,item);
else if(item>=root->data)
root->rchild = insert(root->rchild,item);
return root;
}
void inorder(NODE root)
{
if(root==NULL)
return;
inorder(root->lchild);
printf("%d ",root->data);
inorder(root->rchild);
}
void preorder(NODE root)
{
if(root==NULL)
return;
printf("%d ",root->data);
preorder(root->lchild);
preorder(root->rchild);
}
void postorder(NODE root)
{
if(root==NULL)
return;
postorder(root->lchild);
postorder(root->rchild);
printf("%d ",root->data);
}
void levelorder(NODE root) 
{ 
int h = height(root); 
int i; 
for (i=1; i<=h; i++) 
{ 
printGivenLevel(root, i); 
printf("\n"); 
} 
} 
void printGivenLevel(NODE root, int level) 
{ 
if (root == NULL) 
return; 
if (level == 1) 
printf("%d ", root->data); 
else if (level > 1) 
{ 
printGivenLevel(root->lchild, level-1); 
printGivenLevel(root->rchild, level-1); 
} 
} 
int height(NODE root)  
{ 
int ldepth,rdepth;
if (root==NULL)  
return 0; 
else 
{ 
ldepth = height(root->lchild); 
rdepth = height(root->rchild); 
if(ldepth > rdepth)  
return (ldepth+1); 
else 
return (rdepth+1); 
} 
}  
  





