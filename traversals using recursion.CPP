#include<iostream.h>    // for input-output
#include<alloc.h>       // for memory allocation
#include<stdlib.h>      // for exit function
#include<conio.h>       // for console input-output.

/* 1. Typedef and Structure Definition
Defines a typedef for struct tree* as node.
Function prototypes for create(), inorder(), preorder(), and postorder().
Defines a structure tree:
    nodevalue: Holds the integer value of the node.
    right, left: Pointers to the right and left children of the node.
    root: Global variable representing the root of the binary tree.
*/
typedef struct tree *node;
node create(int , node NODE);
void inorder(node NODE);
void preorder(node NODE);
void postorder(node NODE);

struct tree
{
    int nodevalue;
    struct tree *right, *left;
}*root;

/* 2. main() Function
Main() function initializes variables, reads the number of nodes (num), and constructs the binary tree using create() function.
Displays a menu for traversal options (1: Inorder, 2: Preorder, 3: Postorder, 4: Exit).
Uses a do-while loop to repeatedly prompt for user input until the user chooses to exit.
Depending on the user's choice, invokes corresponding traversal functions (inorder(), preorder(), postorder()).
*/
void main()
{
    node NODE = NULL;
    int nodevalue, choice, i = 0, num;
    clrscr();
    
    cout << "\t\t\t**** BINARY TREE TRAVERSAL****\nEnter the number of Nodes to form a Tree: ";
    cin >> num;
    
    cout << "\n Enter the values for nodes\n";
    for (i = 1; i <= num; i++)
    {
        cin >> nodevalue;
        NODE = create(nodevalue, NODE);
    }
    
    cout << "\n\t\t\t1. INORDER\n\t\t\t2. PREORDER\n\t\t\t3. POSTORDER\n\t\t\t4. EXIT\n";
    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                cout << "Inorder Traversal\n";
                inorder(NODE);
                break;
            case 2:
                cout << "Preorder Traversal\n";
                preorder(NODE);
                break;
            case 3:
                cout << "Postorder Traversal\n";
                postorder(NODE);
                break;
            default:
                cout << "Exit";
                exit(0);
        }
    } while (choice != 4);
    
    getch();
}

/* 3. create() Function
create() function recursively creates nodes in the binary tree.
Allocates memory for a new node (new1) and assigns nodevalue, left, and right pointers.
Recursively calls itself based on whether X is less than or greater than the current node's value (NODE->nodevalue).
Returns the modified NODE pointer.
*/
node create(int X, node NODE)
{
    struct tree *new1;
    new1 = (tree*)malloc(sizeof(struct tree));
    
    if (new1 == NULL)
        cout << "No Nodes are here\n";
    else
    {
        if (NODE == NULL)
        {
            new1->nodevalue = X;
            new1->left = NULL;
            new1->right = NULL;
            NODE = new1;
        }
        else
        {
            if (X < NODE->nodevalue)
                NODE->left = create(X, NODE->left);
            else
                NODE->right = create(X, NODE->right);
        }
    }
    return NODE;
}

/* Traversal Functions (inorder(), preorder(), postorder()):
inorder(), preorder(), and postorder() are recursive functions to perform inorder, preorder, and postorder traversals, respectively.
Each function checks if NODE is not NULL, then recursively calls itself to traverse the left subtree, prints the current node value (NODE->nodevalue), 
and then traverses the right subtree.
*/
void inorder(node NODE)
{
    if (NODE != NULL)
    {
        inorder(NODE->left);
        cout << "\t" << NODE->nodevalue;
        inorder(NODE->right);
    }
}

void preorder(node NODE)
{
    if (NODE != NULL)
    {
        cout << "\t" << NODE->nodevalue;
        preorder(NODE->left);
        preorder(NODE->right);
    }
}

void postorder(node NODE)
{
    if (NODE != NULL)
    {
        postorder(NODE->left);
        postorder(NODE->right);
        cout << "\t" << NODE->nodevalue;
    }
}

/*
Summary:
This program demonstrates the creation of a binary tree based on user input, 
followed by various traversals of the tree (inorder, preorder, postorder) using recursive functions. 
Each traversal function recursively visits nodes in different orders to achieve the desired output.
*/