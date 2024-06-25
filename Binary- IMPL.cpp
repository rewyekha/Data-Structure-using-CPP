#include<iostream.h>
#include<alloc.h>
#include<stdlib.h>
#include<conio.h>
typedef struct tree *node;
node create(int ,node NODE);
void inorder(node NODE);
void preorder(node NODE);
void postorder(node NODE);
struct tree
{
int nodevalue;
struct tree *right,*left;
}*root;
void main()
{
node NODE= NULL;
int nodevalue,choice,i=0,num;
clrscr();
cout<<“\t\t\t**** BINARY TREE TRAVERSAL****\nEnter the number of Nodes to
form a Tree:”;
cin>>num;
cout<<“\n Enter the values for nodes\n”;
for(i=1;i<=num;i++)
{
cin>>nodevalue;
NODE=create(nodevalue,NODE);
}
cout<<“\n\t\t\t1.INORDER\n\t\t\t2.PREORDER\n\t\t\t3.POSTOTRDER\n\t\t\t4.EXIT\n”;
do
{
cout<<“\nEnter your choice:”;
cin>>choice;
switch (choice)
{
case 1:
cout<<“Inorder Traversal\n”;
inorder(NODE);
break;
case 2:
cout<<“Preoroder Traversal\n”;
preorder(NODE);
break;
case 3:
cout<<“Postorder Traversal\n”;
postorder(NODE);
break;
default:
cout<<“Exit”;
exit(0);
}
}
while(choice!=4);
getch();
}
node create(int X, node NODE)
{
 struct tree *new1;
new1=(tree*)malloc(sizeof(struct tree));
if(new1==NULL)
cout<<“No Nodes are here\n”;
else
{
if(NODE==NULL)
{
new1->nodevalue=X;
new1->left=NULL;
new1->right=NULL;
NODE=new1;
}
else
{
if(X<NODE->nodevalue)
NODE->left=create(X,NODE->left);
else
NODE->right=create(X,NODE->right);
}
}
return NODE;
}
void inorder(node NODE) {
if(NODE!=NULL) {
inorder(NODE->left);
cout<<“\t”<<NODE->nodevalue;
inorder(NODE->right);
}
}
void preorder(node NODE) {
if(NODE!=NULL) {
cout<<“\t”<<NODE->nodevalue;
preorder(NODE->left);
preorder(NODE->right);
}
}
void postorder(node NODE) {
if(NODE!=NULL) {
postorder(NODE->left);
postorder(NODE->right);
cout<<“\t”<<NODE->nodevalue;
}
}
