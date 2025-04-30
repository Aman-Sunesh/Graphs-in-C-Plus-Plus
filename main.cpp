#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "UndirectedGraph.h"

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("data.txt");

    if (inFile.fail()) 
    {
        cerr << "File data.txt could not be opened";
        exit(1); 
    }

    UndirectedGraph graph;
    string city1, city2;
    int distance;

    while (inFile >> city1 >> city2 >> distance) 
    {
        graph.addEdge(city1, city2);
    }

    // Print out every adjacency list
    graph.print();

    cout << "\n";
    cout << "\n";

    // Test Cases
    cout << "------ Test Cases -------" << "\n\n"
    << "Adelaide–Sydney: "  <<   (graph.isAdjacent("Adelaide","Sydney")  ? "Adjacent\n" : "Not Adjacent\n")  << "\n"
    << "Frankfurt–Dubai: "  <<   (graph.isAdjacent("Frankfurt","Dubai")  ? "Adjacent\n" : "Not Adjacent\n")  << "\n"
    << "Sydney–Frankfurt: " <<   (graph.isAdjacent("Sydney","Frankfurt") ? "Adjacent\n" : "Not Adjacent\n")  << "\n"
    << "Doha–Adelaide: "    <<   (graph.isAdjacent("Doha","Adelaide")    ? "Adjacent\n" : "Not Adjacent\n")  << "\n"
    << "Tokyo–Doha: "       <<   (graph.isAdjacent("Tokyo","Doha")       ? "Adjacent\n" : "Not Adjacent\n")  << "\n";

    return 0;
}