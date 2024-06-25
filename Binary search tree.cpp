#include<iostream.h>
#include<conio.h>
enum boolean { false=0,true=1};
struct node
{
int ele;
node *left,*right;
}*root=NULL;
class BST {
node *par,*temp,*temp1;
node* newnode(int);
public:
void insert(int,node*,int);
boolean search(int,node*);
node* deletemin(node**);
void del(int,node**);
void display(node*);
};
node* BST::newnode(int x) {
node *nod=new node;
nod->ele=x;
nod->left=nod->right=NULL;
return(nod); }
void BST::insert(int x,node *cur,int pos) {
if(cur == NULL) {
 cur=newnode(x);
 if(pos==1)
 par->left=cur;
 else if (pos==2)
 par->right=cur;
if(root==NULL)
root=cur;
}
else
{
par=cur;
if(x < cur->ele)
insert(x,cur->left,1);
else if(x > cur->ele)
insert(x,cur->right,2);
}}
boolean BST::search(int x,node *cur)
{
if(root == NULL)
return false;
else if(x == cur->ele)
return true;
else if(x < cur->ele && cur->left != NULL)
return (search(x,cur->left));
else if(x > cur->ele && cur->right != NULL)
return (search(x,cur->right));
return false;
}
node* BST::deletemin(node **cur)
{
if((*cur)->left==NULL)
{
temp=(*cur);
(*cur)=(*cur)->right;
}
else
temp=deletemin((&(*cur)->left));
return(temp);
}
void BST::del(int x,node **cur)
{
if((*cur)!=NULL)
{
if(x<(*cur)->ele)
del(x,(&(*cur)->left));
else if(x>(*cur)->ele)
del(x,(&(*cur)->right));
else // x == (*cur)->ele
{
if( ((*cur)->left==NULL) && ((*cur)->right==NULL) )
{
delete((*cur));
(*cur)=NULL; //must
}
else if((*cur)->left==NULL)
(*cur)=(*cur)->right;
else if((*cur)->right==NULL)
(*cur)=(*cur)->left;
else
{
temp1=(*cur)->left;
(*cur)=deletemin((&(*cur)->right));
(*cur)->left=temp1;
}
}
}
}
void BST::display(node *cur)
{
if(cur != NULL)
{
display(cur->left);
cout<<“\t”<<cur->ele;
display(cur->right);
}
}
void main()
{
int no,x,p;
BST bst;
clrscr();
do
{
cout<<“\n1:Insert\t2:Delete\t3:Search\t4:Display\t5:Exit\nSelect your option :”;
cin>>no;
switch(no)
{
case 1:
cout<<“\nEnter the no. to be inserted:”;
cin>>x;
bst.insert(x,root,0);
break;
case 2:
cout<<“\nEnter the element to be deleted : “;
cin>>x;
bst.del(x,&root);
break;
case 3:
cout<<“\nEnter the element to be searched :”;
cin>>x;
p=bst.search(x,root);
if(p==true)
cout<<“The element is in the BST\n”;
else
cout<<“The element is not in the BST\n”;
break;
case 4:
cout<<“\nThe elements in the list are\n”;
bst.display(root);
}
}while(no<5);
}
