#include <stack>
#include <vector>
using namespace std;


// Depth first traversal
template <typename T> void graph<T>::print(unsigned int sVertex){
    stack<unsigned int> s; //vertices to be visited
    vector<bool> visited(nVertex(), false); //marker for visited
    s.push(sVertex); visited[sVertex] = true; //add starting vertex to stack

    while (!s.empty()){
        unsigned int v = s.top(); s.pop(); //about to be visited vertex
        printVertex(v);
        set<unsigned int>::reverse_iterator iA;
        for (iA = edges[v].rbegin(); iA != edges[v].rend(); iA++){ //neighbouring vertices
            if (!visited[*iA]){ //vertex hasn't been
                q.push(*iA); visited[*iA] = true; //add vertex to stack
            }
        }
    }
}

// Depth first traversal
template <typename T> void graph<T>::print(unsigned int sVertex, vector<bool>& visited){
    printVertex(edges[sVertex]);

    set<unsigned int>::reverse_iterator iA;
    visited[sVertex] = true;
    for (iA = edges[sVertex].rbegin(); iA != edges[sVertex].rend(); iA++){ //neighbouring vertices
        if (!visited[*iA]){ //vertex hasn't been
            print(*iA, visited);
        }
    }
}

// Depth first traversal
template <typename T> void graph<T>::print(unsigned int sVertex){
    vector<bool> visited(nVertex(), false); 
    print(sVertex, visited);
}