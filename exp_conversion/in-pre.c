#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 50
char st[MAXSIZE];
int top=0;
char pop();
void push(char);
int prec(char);
char* strev(char *);
int main()
{
char post[' '],in[' '],elem;
int k=0,i,j;
printf("\nEnter the infix expression to be converted: ");
fflush(stdin);
scanf("%s",in);
push(')');
strcpy(in,strev(in));
//printf("%s",in);
for(i=0;in[i]!='\0';i++)
{
if(isalnum(in[i]))
post[k++]=in[i];
else
{
if(post[k-1]!=',')
post[k++]=',';
if(in[i]==')')
push(')');
else if(in[i]=='(')
{
while(st[top]!=')')
{
elem=pop();
post[k++]=elem;
}
elem=pop();
}
else
{
while(prec(st[top])>prec(in[i]))
{
elem=pop();
post[k++]=elem;
}
push(in[i]);
}
}
}
while(top>1)
{
elem=pop();
post[k++]=',';
post[k++]=elem;
}
post[k]='\0';
printf("\nThe required postfix expression is: %s",strev(post));
return 0;
}
void push(char i)
{
st[++top]=i;
}
char pop()
{
return st[top--];
}
int prec(char elem)
{
switch(elem)
{
case '(':
return 0;
break;
case ')':
return 1;
break;
case '+':
case '-':
return 2;
break;
case '*':
case '/':
return 3;
break;
case '^':
case '$':
return 4;
break;
}
}
char* strev(char *str)
{
char *rts;
rts=(char*)malloc(sizeof(char)*strlen(str));
int i,k=0;
for(i=strlen(str)-1;i>=0;i--)
rts[k++]=str[i];
rts[k]='\0';
return rts;
}
