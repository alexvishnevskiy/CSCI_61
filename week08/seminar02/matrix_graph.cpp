//Graph implementations
// INVARIANT for the graph class:
//   1. The number of vertices in the graph is stored in the member variable
//      many_vertices.
//   1. These vertices are numbered from 0 to many_vertices-1.
//   2. edges is the adjacency matrix for the graph (with true in edges[i][j]
//      to indicate an edge from vertex i to vertex j).
//   3. For each i < many_vertices, labels[i] is the label of vertex i.

#include <cassert>    // Provides assert
#include <cstdlib>    // Provides size_t
#include <set>        // Provides set


template <class Item>
void graph<Item>::add_edge(std::size_t source, std::size_t target){
    assert(source < size( ));
    assert(target < size( ));
    edges[source][target] = true;
}

template <class Item>
void graph<Item>::add_vertex(const Item& label){
    std::size_t new_vertex_number;
    std::size_t other_number;

    assert(size( ) < MAXIMUM);
    // many_vertives - previous number of vertices
    new_vertex_number = many_vertices;
    many_vertices++;
    for (other_number = 0; other_number < many_vertices; ++other_number)
    {
        edges[other_number][new_vertex_number] = false;
        edges[new_vertex_number][other_number] = false;
    }
    labels[new_vertex_number] = label;
}

template <class Item>
bool graph<Item>::is_edge(std::size_t source, std::size_t target) const{
    assert(source < size( ));
    assert(target < size( ));
    return edges[source][target];
}

template <class Item>
Item& graph<Item>::operator[ ] (std::size_t vertex){
    assert(vertex < size( ));
    return labels[vertex];     // Returns a reference to the label
}

template <class Item>
Item graph<Item>::operator[ ] (std::size_t vertex) const{
    assert(vertex < size( ));
    return labels[vertex];     // Returns only a copy of the label
}

template <class Item>
std::set<std::size_t> graph<Item>::neighbors(std::size_t vertex) const{
    std::set<std::size_t> answer;
    std::size_t i;

    assert(vertex < size( ));

    for (i = 0; i < size( ); ++i)
    {
        if (edges[vertex][i])
            answer.insert(i);
    }
    return answer;
}

template <class Item>
void graph<Item>::remove_edge(std::size_t source, std::size_t target){
    assert(source < size( ));
    assert(target < size( ));
    edges[source][target] = false;
}