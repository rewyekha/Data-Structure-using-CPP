#include<iostream.h>  // for input-output 
#include<conio.h>     // for console input-output)
enum boolean { false=0,true=1}; // Defines an enum boolean with false and true values for representing boolean conditions.

/* 1. Node Structure and BST Class Definition:
node structure defines a binary tree node with an integer data (ele), and pointers to left and right children (left, right).
root is a global pointer to the root of the BST.
BST class encapsulates methods (insert, search, deletemin, del, display) to perform operations on the BST.
*/
struct node
{
    int ele;
    node *left, *right;
} *root = NULL;

class BST {
    node *par, *temp, *temp1;
    node* newnode(int);
public:
    void insert(int, node*, int);
    boolean search(int, node*);
    node* deletemin(node**);
    void del(int, node**);
    void display(node*);
};

/* 2. newnode() Function:
newnode() allocates memory for a new node, initializes its data (ele) to x, 
and sets both children pointers (left, right) to NULL.
*/
node* BST::newnode(int x) {
    node *nod = new node;
    nod->ele = x;
    nod->left = nod->right = NULL;
    return nod;
}

/* 3. Insertion (insert() Function)
insert() recursively inserts a new node with value x into the BST.
It traverses the tree based on the comparison of x with the current node's value (cur->ele).
par keeps track of the parent node during traversal to properly link the new node (cur) as the left or right child.
*/
void BST::insert(int x, node *cur, int pos) {
    if (cur == NULL) {
        cur = newnode(x);
        if (pos == 1)
            par->left = cur;
        else if (pos == 2)
            par->right = cur;
        if (root == NULL)
            root = cur;
    } else {
        par = cur;
        if (x < cur->ele)
            insert(x, cur->left, 1);
        else if (x > cur->ele)
            insert(x, cur->right, 2);
    }
}

/* 4. Searching (search() Function)
search() recursively searches for a value x in the BST.
Returns true if x is found in the tree, otherwise continues searching in the appropriate subtree (left or right) until a leaf node or NULL is encountered.
*/
boolean BST::search(int x, node *cur) {
    if (root == NULL)
        return false;
    else if (x == cur->ele)
        return true;
    else if (x < cur->ele && cur->left != NULL)
        return search(x, cur->left);
    else if (x > cur->ele && cur->right != NULL)
        return search(x, cur->right);
    return false;
}


/* 5. Deletion (del() and deletemin() Functions)
deletemin() finds and deletes the minimum node in a subtree.
del() recursively deletes a node with value x from the BST, handling different cases such as no children, one child, and two children.
*/

node* BST::deletemin(node **cur) {
    if ((*cur)->left == NULL) {
        temp = (*cur);
        (*cur) = (*cur)->right;
    } else
        temp = deletemin((&(*cur)->left));
    return temp;
}

void BST::del(int x, node **cur) {
    if ((*cur) != NULL) {
        if (x < (*cur)->ele)
            del(x, (&(*cur)->left));
        else if (x > (*cur)->ele)
            del(x, (&(*cur)->right));
        else {
            if (((*cur)->left == NULL) && ((*cur)->right == NULL)) {
                delete((*cur));
                (*cur) = NULL; // must
            } else if ((*cur)->left == NULL)
                (*cur) = (*cur)->right;
            else if ((*cur)->right == NULL)
                (*cur) = (*cur)->left;
            else {
                temp1 = (*cur)->left;
                (*cur) = deletemin((&(*cur)->right));
                (*cur)->left = temp1;
            }
        }
    }
}

/* 6. Display (display() Function):
display() performs an inorder traversal to print the elements of the BST in sorted order.
*/
void BST::display(node *cur) {
    if (cur != NULL) {
        display(cur->left);
        cout << "\t" << cur->ele;
        display(cur->right);
    }
}

/* 7. main() Function:
main() function provides a menu-driven interface for users to insert, delete, search, or display elements in the BST.
Utilizes BST class methods (insert, del, search, display) to perform corresponding operations based on user input.
*/

void main() {
    int no, x, p;
    BST bst;
    clrscr();
    
    do {
        cout << "\n1: Insert\t2: Delete\t3: Search\t4: Display\t5: Exit\nSelect your option: ";
        cin >> no;
        
        switch (no) {
            case 1:
                cout << "\nEnter the number to be inserted: ";
                cin >> x;
                bst.insert(x, root, 0);
                break;
            case 2:
                cout << "\nEnter the element to be deleted: ";
                cin >> x;
                bst.del(x, &root);
                break;
            case 3:
                cout << "\nEnter the element to be searched: ";
                cin >> x;
                p = bst.search(x, root);
                if (p == true)
                    cout << "The element is in the BST\n";
                else
                    cout << "The element is not in the BST\n";
                break;
            case 4:
                cout << "\nThe elements in the list are\n";
                bst.display(root);
                break;
        }
    } while (no < 5);
}

/*
Summary
This program demonstrates a complete implementation of a Binary Search Tree in C++, including insertion, deletion, search, and display operations. 
The use of classes (BST) and recursive methods (insert, del, search, display) makes the implementation efficient and organized for managing BST operations.
*/

