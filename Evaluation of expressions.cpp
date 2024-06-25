#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#define M 30
#define symbol 10
#define str 20
typedef struct prepost
{
 int top;
 int s[M];
}Fix;
void init(Fix*);
void push(Fix*,int);
int pop(Fix*);
void eval(Fix*,char,int,int);
int gettype(char);
void main()
{
 char str1[M];
 int item1,item2,item,l,i,pr;
 Fix stk;
 fflush(stdin);
 int k;
 clrscr();
 do{
 cout<<“\n\t\tEvaluation of Expression.”;
 cout<<“\n\t1:PreFix\t2:PostFix3:Exit \n\t”;
 cin>>k;
 switch(k)
 {
 case 1:
 {
 init(&stk);
 cout<<“ ENTER THE PREFIX EXPRESSION “;
 gets(str1);
 l=strlen(str1);
 for(i=l;i>=0;i—)
 {
 if(str1[i]==’ ‘ || str1[i]==’\0')
 continue;
 switch(gettype(str1[i]))
 {
 case symbol : item=str1[i]-’0';
 push(&stk,item);
 break;
 case str : item1=pop(&stk);
 item2=pop(&stk);
 eval(&stk,str1[i],item1,item2);
 }
 }
cout<<“\n\tResult of prefix evaluation is:”;
 cout<<stk.s[0];
 getch();
 }
 break;
case 2:
 {
 init(&stk);
 cout<<“ ENTER THE Postfix EXPRESSION “;
 gets(str1);
 l=strlen(str1);
 for(i=0;i<=l;i++)
 {
 if(str1[i]==’ ‘ || str1[i]==’\0')
 continue;
 switch(gettype(str1[i]))
 {
 case symbol : item=str1[i]-’0';
 push(&stk,item);
 break;
 case str : item2=pop(&stk);
 item1=pop(&stk);
 eval(&stk,str1[i],item1,item2);
 }
 }
cout<<“\n\tResult of postfix evaluation is:”;
 cout<<stk.s[0];
 getch();
 }
 break;
 case 3: k=3;
 default:cout<<“\n End”;
 }
 }while (k!=3);
}

void init(Fix *stk )
{
 stk->top=-1;
}
void push(Fix *st,int num)
{
 st->top++;
 st->s[st->top]=num;
}
int pop(Fix *st)
{
 int item;
 item=st->s[st->top];
 st->top—;
 return item;
}
void eval(Fix *st,char opr,int item1,int item2)
{
 int res;
 switch(opr)
 {
case ‘+’: res=item1+item2;
break;
case ‘-’: res=item1-item2;
break;
case ‘*’: res=item1*item2;
break;
case ‘/’: res=item1/item2;
break;
case ‘%’: res=item1%item2;
break;
case ‘^’: res=pow(item1,item2);
break;
 }
 push(st,res);
}
int gettype(char c)
{
switch(c)
{
case ‘+’:
case ‘-’:
case ‘*’:
case ‘/’:
case ‘^’:
case ‘%’: return str;
default : return symbol;
 }
}
