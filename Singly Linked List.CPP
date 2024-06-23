#include<iostream.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>

/*1. Struct Definition*/
/*Defines a structure link which contains an integer info and a pointer next to another link structure. This forms the nodes of the singly linked list.*/
struct link 
{
 int info;
 struct link *next;
};
/*2. Class Definition (Slink)*/
/*
Slink is a class that encapsulates operations on a singly linked list (link).
start is an instance of link serving as the starting node of the linked list.
previous and new1 are pointers to link structures used in various operations.
*/
class Slink 
{
 private:
 int i,number;
 link start,*previous,*new1;
 public:
 void insertion(link *);
 void create(link *);
 void display(link *);
 void delet(link *);
};

/*3. Method Definitions*/
/* A. create(link *node)
create initializes the linked list starting from start.
It prompts the user to input nodes until 'n' is entered.
Each node is dynamically allocated (malloc) and linked sequentially.
*/
void Slink::create(link *node)
{
 start.next=NULL;
 node=&start;
 i=0;
 cout<<“\nInput Choice n for break:”;
 char ch=getche();
 while(ch!=’n’)
 {
 node->next=(struct link *)malloc(sizeof(struct link));
node=node->next;
 cout<<“\nInput the node:”<<(i+1)<<“:”;
 cin>>node->info;
 node->next=NULL;
 cout<<“\n Input Choice n For Break:”;
 ch=getche();
 i++;
 }
}
/*B. insertion(link *node)*/
/*
insertion inserts a new node at the beginning of the linked list.
It allocates memory for new1, assigns its info and adjusts pointers to link it correctly.
*/
void Slink::insertion(link *node)
{
 node=start.next;
 previous=&start;
 new1=(struct link*)malloc(sizeof(struct link));
 new1->next=node;
 previous->next=new1;
 cout<<“\nInput the first node value:”;
 cin>>new1->info;
}
/*C. display(link *node)
display prints the contents of the linked list starting from start.next.
It traverses the list and prints each node's address and info value.
*/
void Slink::display(link *node)
{
 node=start.next;
 cout<<“\nAfter inserting a node list is as follows:\n”;
 cout<<“Address\t\tValue”;
 while(node)
 {
 cout<<“\n”<<node;
 cout<<“”<<node->info;
 cout<<“\t”<<node->info;
 node=node->next;
 }
}
/*D. delet(link *node)
*/
void Slink::delet(link *node)
{
node=start.next;
previous=&start;
if(node==NULL)
 cout<<“\nUnder Flow\n”;
else
 {
 previous->next=node->next;
cout<<node->info<<“is deleted”;
 free(node);
 }
}
/* 4. main() Function
main() function initializes the program.
It creates an instance of Slink (S) and a pointer node for operations.
Uses a loop to repeatedly display a menu (Create, Insertion, Display, Delete, Exit) and executes corresponding methods based on user input (choice).
*/
void main()
{
char choice;
clrscr();
Slink S;
link *node=(link *)malloc(sizeof(link));
do
{
cout<<“\nCreate\tInsertion\tDisplay\tdElete\teXit\n”;
cout<<“\nSelect UR Choice:”;
choice=getch();
cout<<choice;
switch(choice)
{
case ‘C’:
S.create(node);
break;
case ‘I’:
S.insertion(node);
break;
case ‘D’:
S.display(node);
break;
case ‘E’:
S.delet(node);
break;
case ‘X’:
exit(0);
cout<<“\n”;
break;
}
}while(choice!=’X’);
getch();
}

/*NOTES:
Memory Management: The code uses malloc and free for dynamic memory allocation and deallocation, respectively.
User Interaction: User inputs are taken directly from the console (cin and getche).
Compatibility: The program appears to be designed for older environments like DOS, using functions like clrscr() and getch().
This code demonstrates basic operations on a singly linked list in C++, 
suitable for learning purposes, especially in environments like DOSBox. 
For modern applications, consider using C++ standard library containers (std::list, std::vector, etc.) and smart pointers (std::unique_ptr, std::shared_ptr) for memory management.
*/