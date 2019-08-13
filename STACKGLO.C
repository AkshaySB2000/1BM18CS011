#include<stdio.h>
#include<conio.h>
int s[100],top=-1;
void push(int ele);
int pop();
void display();
int main()
{
int e;
clrscr();
push(1);
push(2);
push(3);
display();
e=pop();
printf("\n\nThe popped element is %d\n",e);
display();
getch();
return 0;
}
void push(int ele)
{
if(top==99)
{
printf("\nStack overflow");
return;
}
s[++top]=ele;
}
int pop()
{
int e;
if(top==-1)
{
printf("\nStack underflow");
return -9999;
}
e=s[top--];
return e;
}
void display()
{
int i;
if(top==-1)
{
printf("\nStack is empty");
return;
}
printf("\nThe Stack is\n");
for(i=top;i>=0;i--)
{
printf("\n%d",s[i]);
}
}
