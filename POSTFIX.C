#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
void push(int,int s[100],int *);
int pop(int s[100],int *);
int result(int,int,char);
int main()
{
char poexp[100],item;
int s[100],top=-1,i=0,o2,o1,r,k;
printf("\nEnter the postfix expression\n");
gets(poexp);
item=poexp[i];
while(item!='\0')
{
if(isalnum(item))
{
k=item-48;
push(k,s,&top);
}
else
{
o2=pop(s,&top);
o1=pop(s,&top);
r=result(o1,o2,item);
push(r,s,&top);
}
i++;
item=poexp[i];
}
printf("The result of postfix expression = %d",r);
getch();
return 0;
}
void push(int c,int s[100],int *top)
{
if(*top==99)
{
printf("\nStack overflow");
return;
}
*top=*top+1;
s[*top]=c;
}
int pop(int s[100],int *top)
{
int d;
if(*top==-1)
{
printf("\nStack underflow");
return -3;
}
d=s[*top];
*top=*top-1;
return d;
}
int result(int a,int b, char e)
{
int c;
switch(e)
{
case '+':{c=a+b;
	  return c;}
case '-':{c=a-b;
	  return c;}
case '*':{c=a*b;
	  return c;}
case '/':{c=a/b;
	  return c;}
case '^':{c=pow(a,b);
	  return c;}
default:{printf("\nInvalid input");
	 return 0;}
}
}

