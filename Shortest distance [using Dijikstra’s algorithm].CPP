#include<iostream.h> 
#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 10         // MAX defines the maximum number of vertices in the graph.
#define INFINITY 9999  // Defines INFINITY as a large value to represent infinity in the context of shortest path calculations.

/* 1. Node Structure Definition:
Defines a structure node to represent nodes in the adjacency list.
Each node contains:
vertex: The adjacent vertex number.
weight: The weight (distance) of the edge to that vertex.
next: Pointer to the next node in the adjacency list.
*/
typedef struct node {
    struct node *next;
    int vertex, weight;
} node;

/*2. Global Variables
G[MAX]: Array of pointers to node structures, representing the adjacency list for each vertex.
n: Number of vertices in the graph.
*/
node *G[MAX]; // Array of pointers to nodes (adjacency list)
int n;        // Number of vertices

/* 3. Function Prototypes
readgraph(): Function to read the graph input and construct the adjacency list.
insert(int vi, int vj, int w): Function to insert an edge with weight w between vertices vi and vj into the adjacency list.
dijkstra(int startnode): Function to perform Dijkstra's algorithm starting from startnode to compute shortest paths.
*/ 
void readgraph();
void insert(int vi, int vj, int w);
void dijkstra(int startnode);

/* 4. main() Function
main(): Entry point of the program.
Clears the screen (clrscr()), reads the graph input (readgraph()), prompts the user to input the starting node, and then calls dijkstra(u) to compute and display shortest paths.
*/
void main() {
    int u;
    clrscr();
    readgraph();
    cout << "\nEnter the starting node: ";
    cin >> u;
    dijkstra(u);
    getch();
}

/* 5. readgraph() Function
readgraph(): Reads the number of vertices (n) and distances between vertices from the user.
Initializes adj[][] as an adjacency matrix to store distances between vertices.
Initializes G[] (adjacency list) with NULL for all vertices.
Calls insert(i, j, adj[i][j]) to populate the adjacency list based on user input.
*/
void readgraph() {
    int i, j;
    int adj[MAX][MAX];

    cout << "\nEnter number of vertices: ";
    cin >> n;

    // Initialize adjacency matrix with distances
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << "\nEnter the distance from " << i << " to " << j << ": ";
            cin >> adj[i][j];
        }
    }

    // Initialize adjacency list
    for (i = 0; i < n; i++)
        G[i] = NULL;

    // Create adjacency list from adjacency matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[i][j] != 0)
                insert(i, j, adj[i][j]);
        }
    }
}


/* 6. insert() Function
insert(int vi, int vj, int w): Inserts a new node with vertex vj and weight w into the adjacency list of vertex vi.
Uses dynamic memory allocation (malloc()) to create a new node (q) and inserts it at the end of the linked list for vertex vi.
*/
void insert(int vi, int vj, int w) {
    node *p, *q;

    // Allocate memory for new node
    q = (node *)malloc(sizeof(node));
    q->vertex = vj;
    q->next = NULL;
    q->weight = w;

    // Insert the node in the linked list for vertex vi
    if (G[vi] == NULL)
        G[vi] = q;
    else {
        // Go to the end of linked list
        p = G[vi];
        while (p->next != NULL)
            p = p->next;
        p->next = q;
    }
}


/* dijkstra() Function: 
dijkstra(int startnode): Implements Dijkstra's algorithm to compute the shortest paths from startnode to all other nodes.
Uses arrays distance[], pred[], and visited[] to keep track of distances, predecessors, and visited nodes.
Updates distances using adjacency list (G[]) and selects the next node with the smallest distance that has not been visited.
After computation, prints the shortest path and distance from startnode to each node in the graph.
*/

/*
SUMMARY:
This program effectively implements Dijkstra's algorithm using an adjacency list representation of a weighted graph. It allows the user to input the number of vertices and distances between vertices, computes the shortest paths from a specified starting node (startnode), and displays the results. 
The use of dynamic memory allocation, adjacency list, and iterative updating of distances ensures efficient computation of shortest paths in the graph.
*/