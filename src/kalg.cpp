#include "kalg.h"

#include <algorithm>
#include <queue>

using namespace kalg;

Graph::Graph(size_t vertexCount) 
    : adjancentGraph(vertexCount) { }

Graph::Graph(Graph const & other)
    : adjancentGraph(other.adjancentGraph) {
}

Graph::Graph(Graph && other) noexcept 
    : adjancentGraph(std::move(other.adjancentGraph)) { }

Graph& Graph::operator=(Graph const & other) {
    return *this = Graph(other);
}

Graph& Graph::operator=(Graph && other) noexcept {
    std::swap(adjancentGraph, other.adjancentGraph);
    return *this;
}

size_t Graph::size() { return adjancentGraph.size(); }

bool Graph::addEdge(VertexId vertexId, VertexId adjacentId) {
    bool nodesExists = vertexId < adjancentGraph.size() 
        && adjacentId < adjancentGraph.size();

    // nodes out of range
    if(!nodesExists) { return false; }

    auto & vertex = adjancentGraph[vertexId];

    // check if the link already exists
    auto exists = std::find(vertex.begin(), vertex.end(), adjacentId) != vertex.end();
    if(exists) { return false; }

    vertex.push_back(adjacentId);
    return true;

}

std::vector<VertexId> Graph::sort() {

    // holds the current count of incoming dependencies at each vertex
    std::vector<int> incoming(adjancentGraph.size(), 0);

    // record the number of incoming dependencies at each vertex
    for(auto vertex : adjancentGraph) {
        for(auto adj : vertex) {
            incoming[adj]++;
        }
    }

    // holds vertices that have no dependencies left
    std::queue<VertexId> q;

    //add all vertices with incoming of 0 to initialize queue
    for(VertexId vId = 0; vId < incoming.size(); ++vId) {
        if(incoming[vId] == 0) {
            q.push(vId);
        }
    }

    // store the topological order (i.e. the results)
    std::vector<VertexId> topOrder;

    // when the queue is empty, there are no more items to add to the results
    while(!q.empty()) {
        // get next vertex from the queue
        VertexId vId = q.front();
        q.pop();
        // add next vertex to order
        topOrder.push_back(vId);

        // iterate through it's neighbors and decrease their incoming count
        for(auto a : adjancentGraph[vId]) {
            if(--incoming[a] == 0) {
                // node has no more dependencies
                q.push(a);
            }
        }
    }

    // return the result
    return topOrder;

}
