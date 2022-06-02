## Dijkstra's algorithm

The algorithm to find the shortest path between two vertices with weighted graph. (Greedy technique)

### The algorithm

1. Distance array/vector

The same length as number of vertices. Initialize everything to infinity except the source, source = 0.

2. Find the smallest "available" vertex.

"Available" - not infinity, not marked as unavailable.
vertex a -> look at all neightbours

3. Update the distance array/vector using the neighbours.

4. Mark the vertex as unavailable(visited).

5. Repeat 2-4 until N-1 iteration, N - number of vertices.