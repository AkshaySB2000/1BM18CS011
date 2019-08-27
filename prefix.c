#include<stdio.h>
#include<string.h>
#include<ctype.h>
void push(char item,char s[100],int *t);
char pop(char s[100],int *t);
int precedence(char symbol);
void InfixtoPostfix(char infix_exp[100],char postfix_exp[100]);
int main()
{
char infix[100],postfix[100],temp;
printf("Enter Infix expression: \n");
scanf("%s",infix);
int i=0,j;
j=strlen(infix)-1;
while(i<j)
{
temp=infix[i];
infix[i]=infix[j];
infix[j]=temp;
i++;
j--;
}
infix[strlen(infix)]='\0';
InfixtoPostfix(infix,postfix);
i=0;
j=strlen(postfix)-1;
while(i<j)
{
temp=postfix[i];
postfix[i]=postfix[j];
postfix[j]=temp;
i++;
j--;
}
postfix[strlen(postfix)]='\0';
printf("Postfix expression is\n");
puts(postfix);
return 0;
}
void push(char item,char s[100],int *t)
{
if(*t==99)
{
  printf("Stack overflow\n");
  return ;
}
else
{
  *t=*t+1;
  s[*t]=item;
}
}
char pop(char s[100],int *t)
{
char item;
if(*t==-1)
{
  printf("Stack underflow\n");
  return 'x';
}
else
{
  item=s[*t];
  *t=*t-1;
  return item;
}
}
int precedence(char symbol)
{
if(symbol=='^')
  {
   return 3;
  }
else if(symbol=='*' || symbol=='/')
  {
   return 2;
  }
else if(symbol=='+' || symbol=='-')
  {
   return 1;
  }
else
  {
   return 0;
  }
}
void InfixtoPostfix(char infix_exp[100],char postfix_exp[100])
{
char item,x,stack[100];
int top=-1;
int i=0,j=0;
push(')',stack,&top);
strcat(infix_exp,"(");
item=infix_exp[i];
while(item!='\0')
{ 
if(item==')')
  {
   push(item,stack,&top);
  }
  else if(isalpha(item) || isdigit(item))
  {
   postfix_exp[j]=item;
   j++;
  }
  else if(item=='(')
  {
   x=pop(stack,&top);
   while(x!=')')
    {
     postfix_exp[j]=x;
     j++;
     x=pop(stack,&top);
    }
  }  
  else
  {
  if(precedence(stack[top])<precedence(item))
   {
   push(item,stack,&top);
   }
   else
   {
   while(precedence(stack[top])>precedence(item))
    {
     postfix_exp[j]=item;
     j++;
     pop(stack,&top);
    }
    push(item,stack,&top);
  }
}
i++;
item=infix_exp[i];
}
}    
