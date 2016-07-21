#include <stdio.h>#include <stdlib.h>#include<string.h>
#include "graph.h"
char *cities[]={"Sangli","Pune","Mumbai","Kolhapur","Delhi","Chennai","Kolkata",};
/* Function to create an adjacency list node*/adjlist_node_p createNode(int v){    adjlist_node_p newNode = (adjlist_node_p)malloc(sizeof(adjlist_node_t));    newNode->vertex=v;    newNode->next = NULL;    return newNode;}/* Function to create a graph with n vertices; Creates both directed and undirected graphs*/graph_p createGraph(int n, graph_type_e type){    int i;    graph_p graph = (graph_p)malloc(sizeof(graph_t));    graph->num_vertices = n;    graph->type = type;    /* Create an array of adjacency lists*/    graph->adjListArr = (adjlist_p)malloc(n * sizeof(adjlist_t));    for(i = 0; i < n; i++)    {        graph->adjListArr[i].head = NULL;        graph->adjListArr[i].num_members = 0;    }    return graph;}/*Destroys the graph*/void destroyGraph(graph_p graph){    if(graph)    {        if(graph->adjListArr)        {            int v;            /*Free up the nodes*/            for (v = 0; v < graph->num_vertices; v++)            {                adjlist_node_p adjListPtr = graph->adjListArr[v].head;                while (adjListPtr)                {                    adjlist_node_p tmp = adjListPtr;                    adjListPtr = adjListPtr->next;                    free(tmp);                }            }            /*Free the adjacency list array*/            free(graph->adjListArr);        }        /*Free the graph*/        free(graph);    }}/* Adds an edge to a graph*/void addEdge(graph_t *graph, int src, int dest,char no[],int pr){    /* Add an edge from src to dest in the adjacency list*/    adjlist_node_p newNode = createNode(dest);    strcpy(newNode->nm,no);
    newNode->price=pr;
    newNode->next = graph->adjListArr[src].head;
    graph->adjListArr[src].head = newNode;    graph->adjListArr[src].num_members++;    if(graph->type == UNDIRECTED)    {       /* Add an edge from dest to src also*/        newNode = createNode(src);        strcpy(newNode->nm,no);
        newNode->price=pr;
        newNode->next = graph->adjListArr[dest].head;        graph->adjListArr[dest].head = newNode;        graph->adjListArr[dest].num_members++;    }}/* Function to print the adjacency list of graph*/void displayGraph(graph_p graph){    int i;
    for (i = 0; i < graph->num_vertices; i++)    {        adjlist_node_p adjListPtr = graph->adjListArr[i].head;        printf("\n%s: ",cities[i]);        while (adjListPtr)        {            printf("%s->",cities[adjListPtr->vertex]);            adjListPtr = adjListPtr->next;        }        printf("\b\b");
    }}Flight findFlight(graph_p graph,char src[],char dest[])
{
    Flight p;
    int i;
    for (i = 0; i < graph->num_vertices; i++)    {        adjlist_node_p adjListPtr = graph->adjListArr[i].head;
        if(!strcmp(cities[i],src))        {
            while (adjListPtr)            {                if(!strcmp(dest,cities[adjListPtr->vertex]))
                {
                    strcpy(p.f_no,adjListPtr->nm);
                    p.pr=adjListPtr->price;
                    return p;
                }
                adjListPtr = adjListPtr->next;            }
            printf("\n Invalid Destination");
            p.pr=0;
            return p;
        }    }
    p.pr=0;
    printf("\n Invalid Source");
    return p;
}
int main(){    int opt=1;
    char src[10],dest[10];
    Flight f;
    graph_p undir_graph = createGraph(7,UNDIRECTED);    addEdge(undir_graph, 0, 1, "13120", 1750);    addEdge(undir_graph, 0, 2, "31420", 3000);
    addEdge(undir_graph, 0, 3, "14310", 1300);    addEdge(undir_graph, 0, 4, "25630", 5700);
    addEdge(undir_graph, 0, 5, "37820", 9000);
    addEdge(undir_graph, 0, 6, "26110", 9000);    addEdge(undir_graph, 1, 2, "41800", 1200);    addEdge(undir_graph, 1, 3, "20010", 1500);
    addEdge(undir_graph, 1, 4, "14330", 6880);
    addEdge(undir_graph, 1, 5, "60070", 8750);
    addEdge(undir_graph, 1, 6, "14330", 9500);    addEdge(undir_graph, 2, 3, "52840", 2500);    addEdge(undir_graph, 2, 4, "71900", 5500);    addEdge(undir_graph, 2, 5, "91130", 7500);
    addEdge(undir_graph, 2, 6, "76340", 8000);
    addEdge(undir_graph, 3, 4, "43670", 5000);
    addEdge(undir_graph, 3, 5, "24130", 9000);
    addEdge(undir_graph, 3, 6, "36520", 6000);
    addEdge(undir_graph, 4, 5, "12110", 7000);
    addEdge(undir_graph, 4, 6, "27090", 8000);
    addEdge(undir_graph, 5, 6, "25050", 3000);
    while(opt)
    {
        printf("\nAvailable Cities For Flight:\n\n1.Sangli\n2.Pune\n3.Mumbai\n4.Kolhapur\n5.Delhi\n6.Chennai\n7.Kolkata");
        printf("\n\nEnter Current City : ");
        scanf("%s",src);
        printf("\nEnter Destination : ");
        scanf("%s",dest);
        f=findFlight(undir_graph,src,dest);
        if(f.pr)
            printf("\nFlight No: %s \tTicket Price: RS %d /-",f.f_no,f.pr);
        printf("\nPress 1 to continue and 0 to exit......");
        scanf("%d",&opt);
    }    destroyGraph(undir_graph);    return 0;}
