#ifndef GRAPH_H
#define GRAPH_H
#include <cstdlib>  // Provides size_t
#include <set>      // Provides set

template <class Item>
class graph{
public:
    // MEMBER CONSTANTS
    //the maximum number of vertices that a graph can have.
    static const std::size_t MAXIMUM = 20;
    // CONSTRUCTOR
    graph( ) { many_vertices = 0; }
    // MODIFICATION MEMBER FUNCTIONS
    void add_vertex(const Item& label);
    void add_edge(std::size_t source, std::size_t target);
    void remove_edge(std::size_t source, std::size_t target);
    // to replace vertex values
    Item& operator [ ] (std::size_t vertex);
    // CONSTANT MEMBER FUNCTIONS
    std::size_t size( ) const { return many_vertices; }
    bool is_edge(std::size_t source, std::size_t target) const;
    std::set<std::size_t> neighbors(std::size_t vertex) const;
    // the same as [] but for const
    Item operator[ ] (std::size_t vertex) const;
private:
    bool edges[MAXIMUM][MAXIMUM];
    Item labels[MAXIMUM];
    std::size_t many_vertices;
};

#include "matrix_graph.cpp" // Include the implementation.
#endif