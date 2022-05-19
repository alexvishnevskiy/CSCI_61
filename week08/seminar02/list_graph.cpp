// A C++ program to demonstrate adjacency list
// representation of graphs using lists
#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    node * next;
    node(int d, node * n = nullptr): data(d), next(n) {};
};

struct Graph {
	int V; // maximum number of vertices
	node* *adjList;
};

// A utility function that creates a graph of V vertices
Graph* createGraph(int V){
	Graph* graph = new Graph;
	graph->V = V;

	// Create an array of sets representing
	// adjacency lists. Size of the array will be V
	graph->adjList = new node* [V];

	return graph;
}

// Adds an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest){
	// Add an edge from src to dest. A new
	// element is inserted to the adjacent
	// list of src.

    //insert to head
	graph->adjList[src] = new node(dest, graph->adjList[src]);

	// Since graph is undirected, add an edge
	// from dest to src also
	graph->adjList[dest] = new node(src, graph->adjList[dest]);
}

void _remove(node * t, int val){
    while (t && t->next->data != val){
        t = t->next;
    }

    if (t){
        node * temp = t->next;
        t->next = temp->next;
        delete temp;
    }
}

void removeEdge(Graph* graph, int src, int dest){
    // remove an edge from src to dest
    _remove(graph->adjList[src], dest);

	// Since graph is undirected, add an edge
	// from dest to src also
	_remove(graph->adjList[dest], src);
}

// Searches for a given edge in the graph
void searchEdge(Graph* graph, int src, int dest){
    bool found = false;
    node * head = graph->adjList[src];

    while (!found && head && head->data != dest){
        head  = head->next;
        if (head->data == dest) found = true;
    }

	if (found)
		cout << endl << "Edge from " << src
			<< " to " << dest << " found."
			<< endl;
	else
		cout << endl << "Edge from " << src
			<< " to " << dest << " not found."
			<< endl;
}