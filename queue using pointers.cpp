//Queue using pointers

#include<iostream.h>
#include<conio.h>
#include<malloc.h>

/* 1. Struct Definitions
- struct node: Represents a node in the queue with an integer data and a pointer link to the next node.
- struct queue: Defines a queue structure with pointers first and last indicating the front and rear of the queue, respectively.
- struct Q: Defines a class Q that encapsulates queue operations. It includes a queue object q, and a pointer qlink used for various operations.
*/
#include<iostream.h>
#include<conio.h>
#include<malloc.h>

struct node
{
    int data;
    node *link;
};

struct queue
{
    node *first;
    node *last;
};

struct Q {
    queue q;
    node *qlink;
public:
    void Initialise()
    {
        q.first=NULL;
        q.last=NULL;
    }
    void insertqueue();
    void deletequeue();
    void display();
};

/* 2. Method Definitions (Q Class) - a. Initialise()
- Initialise() initializes the queue by setting both first and last pointers to NULL, 
indicating an empty queue.
*/
void Q::Initialise()
{
    q.first = NULL;
    q.last = NULL;
}

/* b. insertqueue()
- insertqueue() inserts a new node with user-input data into the queue.
- Allocates memory for a new node using new.
- Handles insertion logic:
If last is NULL, sets first to the new node (qlink).
Otherwise, links the new node (qlink) to the end of the queue (last->link) and updates last to point to the new node.
*/

void Q::insertqueue()
{
    qlink = new(node);
    cout << "Enter the node data: ";
    cin >> qlink->data;
    cout << "Inserted node data: " << qlink->data;
    qlink->link = NULL;

    if (q.last == NULL)
        q.first = qlink;
    else
        q.last->link = qlink;

    q.last = qlink;
}

/* c. deletequeue()
deletequeue() removes the node at the front of the queue.
Checks if first is NULL to determine if the queue is empty.
If not empty, removes the node pointed to by first, updates first to point to the next node (first->link), and frees the memory of the deleted node (qlink).
*/
void Q::deletequeue()
{
    if (q.first == NULL)
    {
        cout << "\tQueue is Empty";
        q.last = NULL;
    }
    else
    {
        qlink = q.first;
        cout << "\tDeleted node data: " << q.first->data;
        q.first = q.first->link;
        free(qlink);
    }
}

/* d. display()
- display() prints all elements currently in the queue.
- Traverses through the queue starting from first and prints each node's data (qlink->data).
- Outputs "Queue is Empty" if first is NULL, indicating an empty queue.
*/
void Q::display()
{
    if (q.first == NULL)
    {
        cout << "Queue is Empty";
    }
    else
    {
        cout << "\nQueue Front";
        for (qlink = q.first; qlink != NULL; qlink = qlink->link)
        {
            cout << " ==> " << qlink->data;
        }
        cout << " ==> Queue Rear\n";
    }
}

/* 3. main() Function
main() function initializes the program.
Creates an instance of Q named mainqueue and initializes it using Initialise().
Displays a menu (Insert, Delete, View, Exit) and allows the user to interact with the queue by calling corresponding methods (insertqueue(), deletequeue(), display()).
Loops until the user chooses to exit (choice == 'E').
*/

void main()
{
    char choice;
    Q mainqueue;
    clrscr();
    mainqueue.Initialise();

    cout << "\t\tQUEUE USING POINTER\n";
    cout << "\n\tInsert\tDelete\tView\tExit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 'I': mainqueue.insertqueue();
                      break;
            case 'D': mainqueue.deletequeue();
                      break;
            case 'V': mainqueue.display();
                      break;
            case 'E': break;
            default: cout << "Invalid choice";
                     break;
        }
    } while (choice != 'E');

    getch();
}


/* 
Notes:
Memory Management: Uses new and free for dynamic memory allocation and deallocation.
User Interaction: Inputs and outputs are handled using cin and cout.
Pointers: Utilizes pointers (node *link, queue q) for managing nodes and queue structure.
Clearing Screen: Uses clrscr() from <conio.h> to clear the screen for a cleaner output.
*/