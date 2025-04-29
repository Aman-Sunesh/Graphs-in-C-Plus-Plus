#pragma once

#include <map>
#include <set>
#include <string>

struct UndirectedGraph
{
    std::map<std::string,std::set<std::string>> adjList;  // Using sets help ensure that the edges in the graph are unique (as expected)

    void addEdge(const std::string& u, const std::string& v)
    {
        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    bool isAdjacent(const std::string& u, const std::string& v)
    {
        return adjList.at(u).count(v) > 0;
    }
};