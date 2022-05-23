#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// At the beginning of the algorithm, only the starting vertex is known.
// As a vertex is visited, its neighboring vertices are known, and these vertices will be
// visited after all the previously known vertices are visited. The vertices are visited in a last-in last-out order.
// Hence a queue is the ideal data structure to hold the to-be-visited vertices.
// Also, a vertex needs to be visited only once, another data structure is need to indicate that the vertex is already visited.

inline void f(){return;}

template <typename T>
void graph<T>::visit(unsigned int sVertex, void func() = f){
    std::queue<unsigned int> q; // vertices to be visited
    std::vector<bool> visited(nVertex(), false); // merker for visited
    q.push(sVertex); visited[sVertex] = true; // add starting vertex to queue
    while (!q.empty()){
        unsigned int v = q.front(); q.pop(); // about to be visited
        func(v);
        for (auto aV: edges[v]){ // neighboring vertices
            if (!visited[aV]){ // vertex hasn't been
                q.push(aV); visited[aV] = true; // add vertex to queu
            }
        }
    }
}

template <typename T> 
void graph<T>::print(unsigned int sVertex){
    visit(sVertex, printVertex); // traverse and print
} 

// Determine the number of connected component
template <typename T>
unsigned int graph<T>::nConnectedComponent(){
    std::queue<unsigned int> q;
    std::vector<bool> visited(nVertex(), false);
    unsigned int count = 0;
    for (unsigned int i = 0; i < nVertex(); i++){
        if (!visited[i]){
            count++;
            visit(i);
        }
    }
}
