#include<iostream.h>
#include<conio.h>
#include<malloc.h>

/*1. Struct Definition
- Defines a structure node which contains an integer info, and two pointers: next points to the next node in the list, and back points to the previous node, forming a doubly linked list.
*/

struct node
{
    int info;
    struct node *next, *back;
};

/* 2. Class Definition (list)
- list is a class that encapsulates operations on a doubly linked list.
- root points to the first node in the list, and end points to the last node.
*/
class list
{
    struct node *root, *end;
public:
    void createinfo();
    void insert();
    void delet();
    void display();
};

/* 3. Method Definitions - a. createinfo()
- createinfo initializes the doubly linked list.
- It prompts the user to input nodes until -999 is entered.
- Each node is dynamically allocated (malloc) and linked sequentially.
*/
void list::createinfo()
{
    struct node *p, *n;
    int t, s;
    root = p = NULL;
    s = sizeof(struct node);
    cout << "\n enter -999 to stop";
    cin >> t;
    while (t != -999)
    {
        n = (struct node *)malloc(s);
        n->info = t;
        n->next = NULL;
        n->back = NULL;
        
        if (root == NULL)
            root = n;
        else
        {
            p->next = n;
            n->back = p;
        }
        
        p = n;
        cout << "\n enter -999 to stop";
        cin >> t;
    }
    end = n;
}

/* b. display()
- display prints the contents of the doubly linked list.
- It traverses the list forward from root and backward from end, printing each node's info value.
*/

void list::display()
{
    struct node *x = root;
    cout << "\n start -> ";
    while (x != NULL)
    {
        cout << x->info << " -> ";
        x = x->next;
    }
    cout << "end\n";
    
    x = end;
    cout << " back -> ";
    while (x != NULL)
    {
        cout << x->info << " -> ";
        x = x->back;
    }
    cout << "end\n";
}

/* b. display()
- display prints the contents of the doubly linked list.
- It traverses the list forward from root and backward from end, printing each node's info value.
*/
void list::insert()
{
    struct node *temp, *ex = root;
    int value, pos, i = 2;
    cout << "\n enter the value & position to insert :";
    cin >> value >> pos;
    
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = value;
    temp->next = NULL;
    temp->back = NULL;
    
    if (pos == 1)
    {
        temp->next = root;
        root->back = temp;
        root = temp;
    }
    else
    {
        while (ex->next != NULL && i < pos)
        {
            ex = ex->next;
            i++;
        }
        
        temp->next = ex->next;
        temp->back = ex;
        
        if (ex->next != NULL)
            ex->next->back = temp;
        
        ex->next = temp;
        
        if (temp->next == NULL)
            end = temp;
    }
}

/* d. delet()
- delet deletes a node from a specified position in the doubly linked list.
- It handles deletion at the beginning (p == 1), middle, and end positions accordingly.
*/
void main()
{
    clrscr();
    cout << "\n\t\t OUTPUT\n";
    list one;
    one.createinfo();
    one.display();
    one.insert();
    one.display();
    one.delet();
    one.display();
    getch();
}

/* 4. main() Function
- Main() function initializes the program.
- It creates an instance of list (one) and calls methods to perform creation, insertion, deletion, and display operations on the doubly linked list.
- Outputs are displayed to show the state of the list after each operation.
*/
void main()
{
    clrscr();
    cout << "\n\t\t OUTPUT\n";
    list one;
    one.createinfo();
    one.display();
    one.insert();
    one.display();
    one.delet();
    one.display();
    getch();
}

/*
Notes:
Memory Management: The program uses malloc for dynamic memory allocation.
User Interaction: User inputs are taken directly from the console (cin).
Compatibility: The program appears to be designed for older environments like DOS, using functions like clrscr() and getch().
This program effectively demonstrates the implementation and operations of a doubly linked list in C++. For modern applications, consider using C++ standard library containers (std::list, std::deque, etc.) and smart pointers (std::unique_ptr, std::shared_ptr) for memory management.
*/


