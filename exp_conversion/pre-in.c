#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char stack[50][100];
int top=-1;
int oparator(char ch)
{
if(ch=='+'||ch=='-'||ch=='^'||ch=='$'||ch=='*'||ch=='/')
return 1;
else
return 0;
}
void push(char *str)
{
strcpy(stack[++top],str);
}
char* pop()
{
return stack[top--];
}
int main()
{
char in[100],post[100],str[2],s[100],t[100];
int i;
printf("\nEnter your prefix expression: ");
scanf("%s",post);
for(i=0;post[i]!='\0';i++)
{
if(!oparator(post[i]))
{
str[0]=post[i];
str[1]='\0';
push(str);
}
else
{
t[0]='(';
t[1]='\0';
str[0]=post[i];
str[1]='\0';
strcpy(s,pop());
strcat(t,pop());
strcat(t,str);
strcat(t,s);
strcat(t,")");
push(t);
}
}
strcpy(in,pop());
printf("\nCorresponding infix notation is: %s",in);
return 0;
}
