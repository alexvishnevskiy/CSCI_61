#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

//         example graph
// { { inf, 4, inf, inf, inf, inf, inf, 8, inf },
//   { 4, inf, 8, inf, inf, inf, inf, 11, inf },
//   { inf, 8, inf, 7, inf, 4, inf, inf, 2 },
//   { inf, inf, 7, inf, 9, 14, inf, inf, inf },
//   { inf, inf, inf, 9, inf, 10, inf, inf, inf },
//   { inf, inf, 4, 14, 10, inf, 2, inf, inf },
//   { inf, inf, inf, inf, inf, 2, inf, 1, 6 },
//   { 8, 11, inf, inf, inf, inf, 1, inf, 7 },
//   { inf, inf, 2, inf, inf, inf, 6, 7, inf } };

pair<int, vector<int> > dijkstra(vector< vector<int> > graph, int source, int destination);
pair<int, vector<int> > dijkstra_heap(vector< vector<int> > graph, int source, int destination);
int findSmallest(vector<int> distance, vector<bool> visited);


int main(){
    vector<vector<int> > graph = 
    { {INT_MAX, 3, 4, 10},
      {3, INT_MAX, INT_MAX, 2},
      {4, INT_MAX, INT_MAX, 3},
      {10, 2, 3, INT_MAX} };

    // pair<int, vector<int> > res = dijkstra(graph, 0, 3);
    pair<int, vector<int> > res = dijkstra_heap(graph, 0, 3);
    cout << "distance: " << res.first << endl;
    for (auto x: res.second){
        cout << x << ' ';
    }
    return 0;
}


// return the min path
// Implementation O(E + V^2), E-edges, V-vertices
pair<int, vector<int> > dijkstra(vector< vector<int> > graph, int source, int destination){
    // graph vertices: 0, 1, 2, 3, 4, ...
    // weight should be >= 0
    // assert there are source and destination in the graph
    int n = graph.size();
    vector<int> distance(n, INT_MAX);
    vector<bool> visited(n, false);
    vector<int> parents(n); // in order to print path
    pair<int, vector<int> > res;
    distance[source] = 0;

    // initialize parents
    for (int i = 0; i < parents.size(); i++){
        parents[i] = i;
    }

    for (int i = 0; i < n - 1; i++){
        int index = findSmallest(distance, visited); // find smallest "available" vertex
        visited[index] = true; // mark vertex as unavailable
        for (int i = 0; i < graph[index].size(); i++){ // update the distance array
            if (!visited[i] && graph[index][i] != INT_MAX && distance[i] > distance[index] + graph[index][i]){ // update the distances using neighbours
                distance[i] = distance[index] + graph[index][i];
                parents[i] = index;
            }
        }
    }

    // iterate over parents in reverse order and push back to result
    res.first = distance[destination];
    while (destination != source){
        res.second.push_back(destination);
        destination = parents[destination];
    }
    res.second.push_back(source);
    reverse(res.second.begin(), res.second.end());
    return res;
}

int findSmallest(vector<int> distance, vector<bool> visited){
    // could be done with heap
    int min = INT_MAX, index_min = 0;
    for (int i = 0; i < distance.size(); i++){
        if ((distance[i] < min) && (!visited[i])){
            min = distance[i]; index_min = i;
        }        
    }
    return index_min;
}

// implementation using min-heap
// Implementation O(E + VlogV), E-edges, V-vertices
pair<int, vector<int> > dijkstra_heap(vector< vector<int> > graph, int source, int destination){
    // graph vertices: 0, 1, 2, 3, 4, ...
    // weight should be >= 0
    // assert there are source and destination in the graph
    int n = graph.size();
    vector<int> distance(n, INT_MAX);
    vector<bool> visited(n, false);
    vector<int> parents(n); // in order to print path
    pair<int, vector<int> > res;
    // distance, index
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    distance[source] = 0;
    pq.push( {0, source} );

    // initialize parents
    for (int i = 0; i < parents.size(); i++){
        parents[i] = i;
    }

    for (int i = 0; i < n - 1; i++){
        // find smallest
        pair<int, int> p = pq.top(); pq.pop();
        int index = p.second;

        visited[index] = true; // mark vertex as unavailable
        for (int i = 0; i < graph[index].size(); i++){ // update the distance array
            if (!visited[i] && graph[index][i] != INT_MAX && distance[i] > distance[index] + graph[index][i]){ // update the distances using neighbours
                distance[i] = distance[index] + graph[index][i];
                pq.push( {distance[i], i} );
                parents[i] = index;
            }
        }
    }

    // iterate over parents in reverse order and push back to result
    res.first = distance[destination];
    while (destination != source){
        res.second.push_back(destination);
        destination = parents[destination];
    }
    res.second.push_back(source);
    reverse(res.second.begin(), res.second.end());
    return res;
}