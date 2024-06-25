#include<iostream.h>
#define INFINITY 9999
#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 10
typedef struct node
{
struct node *next;
int vertex,weight;
}node;
node *G[10];//adjacency list
int n,t;// Number of vertices
void readgraph();
void insert(int vi,int vj,int w);
void dijkstra(int startnode);
void main()
{
int u,u1;
clrscr();
readgraph();
cout<<“\nEnter the starting node : “;
cin>>u;
dijkstra(u);
}
void dijkstra( int startnode)
{
int distance[MAX],pred[MAX];
int visited[MAX],count,mindistance,nextnode,i,j;
//pred[] stores the predecessor of each node
//count gives the number of nodes seen so far
// A node picked up for expansion is marked as visited[node no.]=1
 //initialize
node *p;
for(i=0;i<n;i++)
{
distance[i]=INFINITY;
pred[i]=startnode;visited[i]=0;
}
distance[startnode]=0;
count=0;
while(count<=n)
{
mindistance=INFINITY ;
// nextnode is the node at minimum distance
for(i=0;i<n+1;i++)
if(distance[i] < mindistance && !visited[i])
 {
mindistance=distance[i];
nextnode=i;
 }
//check if a better path exist through nextnode
visited[nextnode]=1;
for(p=G[nextnode];p!=NULL;p=p->next)
if(!visited[p->vertex])
if(mindistance+p->weight<distance[p->vertex])
 {
distance[p->vertex]=mindistance+p->weight;
pred[p->vertex]=nextnode;
 }
count++;
}
 //print the path and distance of each node
for(i=0;i<n;i++)
if(i!=startnode)
{
cout<<“\n Distance of”<<i<<“=”<<distance[i];
cout<<“ Path = “<<i;
j=i;
do
{
j=pred[j];
cout<<“<- “<<j;
}while(j!=startnode);
}
}
void readgraph()
{ int i,j;
int adj[10][10];
cout<<“\nEnter no. of vertices :”;
cin>>n;
for(i=0;i<n;i++)
 {
for(j=0;j<n;j++)
{
cout<<“\nEnter the distance for”<<i<<“to”<<j<<“:”;
cin>>adj[i][j];
}
}
//initialise G[] with NULL
for(i=0;i<n;i++)
G[i]=NULL;
for(i=0;i<n;i++) //create adjacency list
for(j=0;j<n;j++)
 if(adj[i][j]!=0)
insert(i,j,adj[i][j]);
}
void insert(int vi,int vj,int w)
{
node *p,*q;
//acquire memory for the new node
q=(node *)malloc(sizeof(node));
q->vertex=vj;
q->next=NULL;
q->weight=w;
//insert the node in the linked list for the vertex no. vi
if(G[vi]==NULL)
G[vi]=q;
else
{
// go to the end of linked list
p=G[vi];
while(p->next!=NULL)
p=p->next;
p->next=q;
}
}
