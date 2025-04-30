#pragma once

#include <iostream>
#include <map>
#include <set>
#include <string>

struct Vertex
{
    std::set<std::string> neighbor_set;   // Using sets help ensure that the edges in the graph are unique (as expected)
    bool visited = false;
};


struct UndirectedGraph
{
    std::map<std::string, Vertex> adjList;   // Maps city name to Vertex data

    void addEdge(const std::string& u, const std::string& v)
    {
        adjList[u].neighbor_set.insert(v);
        adjList[v].neighbor_set.insert(u);
    }

    bool isAdjacent(const std::string& u, const std::string& v) const
    {
        auto it = adjList.find(u);
        return it != adjList.end() && it->second.neighbor_set.count(v);
    }

    void print() const
    {
        std::cout << "------- Adjacency Lists -------\n\n";

        for (const auto& node : adjList)    
        {
            const std::string& city = node.first;
            const Vertex& vert = node.second;
    
            std::cout << city << ":";

            for (const auto& nb : vert.neighbor_set)
                std::cout << ' ' << nb;

            std::cout << "\n\n";
        }
    }
};