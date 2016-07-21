#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
//typedef enum {UNDIRECTED=0,DIRECTED} graph_type_e;

/* Adjacency list node*/
typedef struct adjlist_node
{
    int vertex;                /*Index to adjacency list array*/    int price;
    char nm[6];
    struct adjlist_node *next; /*Pointer to the next node*/
}adjlist_node_t, *adjlist_node_p;/* Adjacency list */typedef struct adjlist{
    int num_members;           /*number of members in the list (for future use)*/
    adjlist_node_t *head;      /*head of the adjacency linked list*/
}adjlist_t, *adjlist_p;typedef struct graph{  //  graph_type_e type;        /*Directed or undirected graph */    int num_vertices;         /*Number of vertices*/    adjlist_p adjListArr;     /*Adjacency lists' array*/}graph_t, *graph_p;typedef struct
{
        char f_no[6];
        int pr;
}Flight;
#endif // GRAPH_H_INCLUDED
