#include <iostream>
#include <string>
#include <set>
#include <map>
#include <queue>

using std::cout;
using std::string;

struct Node
{
    string name;
    std::set<string> edges;
    bool on = false;
};

// undirected rooted graph
class Graph
{
        std::map<string, Node> m;
        string root;

    public:

        void setRoot(string r);
        string getRoot() const;
        void addEdge(string a, string b);

        template<class T> void visitDF(T f);
        template<class T> void recVisitDF(Node & N, T & f); //f(N)
        template<class T> void visitBF(T f);

        void resetAll();
};

// class functions implementations

void Graph::setRoot(string r)
{
    root = r;
}

string Graph::getRoot() const
{
    return root;
}

void Graph::addEdge(string a, string b)
{
    m[a].name = a;
    m[b].name = b;
    m[a].edges.insert(b);
    m[b].edges.insert(a);
}

template<class T> void Graph::visitDF(T f)
{
    m[root].on = true;
    f(m[root]);
    recVisitDF(m[root], f);
}

template<class T> void Graph::recVisitDF(Node & N, T & f)
{
    for (const string& neighbour_name : N.edges)
    {
        Node& neighbour = m[neighbour_name];

        if (neighbour.on == false)
        {
            neighbour.on = true;
            f(neighbour);
            recVisitDF(neighbour, f);
        }
    }
}

template<class T> void Graph::visitBF(T f)
{
    Node& first = m[root];
    first.on = true;
    f(first);

    std::queue<Node*> visited;
    visited.push(&first);

    while(!visited.empty())
    {
        Node* current = visited.front();
        visited.pop();

        for (const auto& neighbour_name : current->edges)
        {
            Node& neighbour = m[neighbour_name];
            
            if (neighbour.on == false)
            {
                neighbour.on = true;
                f(neighbour);
                visited.push(&neighbour);
            }
        }
    }
}

void Graph::resetAll()
{
    // iterate through the nodes of the map and set the nodes.on to false
    for (auto& n : m)    
    {
        Node& node = n.second;
        node.on = false;
    }
}

int main()
{
    Graph g;

    {
        int d;
        string a, b;
        while (std::cin >> a >> b >> d && (a != "end" || b != "of" || d != -99)) g.addEdge(a, b);
    }

    auto print = [](const Node & n) {cout << ' ' << n.name;};

    g.setRoot("Adelaide");
    cout << "Visiting DF 1:"; g.visitDF(print); cout << '\n';
    g.resetAll();

    g.setRoot("Tokyo");
    cout << "Visiting DF 2:"; g.visitDF(print); cout << '\n';
    g.resetAll();

    g.setRoot("Dubai");
    cout << "Visiting DF 3:"; g.visitDF(print); cout << '\n';
    g.resetAll();

    cout << "Visiting BF 4:"; g.visitBF(print); cout << '\n';
    g.resetAll();

    g.setRoot("Adelaide");
    cout << "Visiting BF 5:"; g.visitBF(print); cout << '\n';
    g.resetAll();
}

