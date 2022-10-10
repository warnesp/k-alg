#pragma once

#include <vector>

namespace kalg {

    /// Id of a vertex
    using VertexId = int;


    /**
     * \brief Directed Graph for computing Kahn's Algorithm topological sorting
     */
    class Graph {
        /// representation of a vertext (adjacent vertices)
        using Vertex = std::vector<VertexId>;

        /// internal representation of the graph, the VertextId is the index in the vector.
        std::vector<Vertex> adjancentGraph;

        public:

        /**
         * \brief Creates a graph with the specified number of vertices
         *
         * \param vertexCount The number of vertices to have in the graph
         */
        Graph(size_t vertexCount);

        Graph(Graph const & other);
        Graph(Graph && other) noexcept;
        Graph& operator=(Graph const & other);
        Graph& operator=(Graph && other) noexcept;

        /**
         * \brief The size of the graph.
         *
         * \return The size.
         */
        size_t size();

        /**
         * \brief Add a directed adjacentcy to the specified vertex
         *
         * \param vertex Vertex to add adjacentcy too 
         * \param adjacentVertex Vertex that is directionally adjacent
         */
        void addEdge(VertexId vertex, VertexId adjacentVertex);


        /**
         * \brief Sort the vertices with Kahn's algorithm. If the size of the result is less than the size of the Graph, 
         * then the Graph contains a dependency loop.
         *
         * \return The results of the sorting
         */
        std::vector<VertexId> sort();
    };

}

