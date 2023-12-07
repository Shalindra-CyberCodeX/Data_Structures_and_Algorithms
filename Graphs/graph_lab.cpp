#include <iostream>
#include <list>
using namespace std;

//list is STL library in C++ whuch uses linked list to store data
struct Node {
    // A node will 2 entities
    //1. data type int called label
    //2. a int type list called neighbours
    int label;
    list<int> neighbours;
};

struct Graph {
    //graph will have an array of type "node" with length specified by n
    int n = 9;
    Node* nodes = new Node[n];

    void initializeNodes() {
        for (int i = 0; i < n; i++) {
            nodes[i].label = i;
        }
    }

    void addEdge(int u, int v) {
        //select node u and push v into u's neighbour
        nodes[u].neighbours.push_back(v);
        //select node v and push u into v's neighbour
        nodes[v].neighbours.push_back(u);
    }

    void print() {
        //lets iterate through each node and print its neighbours
        for (int i = 0; i < n; i++) {
            cout <<nodes[i].label << "|";
            for (int neighbour : nodes[i].neighbours) {
                cout << neighbour << "->";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph* g = new Graph;
    g->initializeNodes();
    
    // Add edges for the graph here
    g->addEdge(1,2);
    g->addEdge(1,3);
    g->addEdge(1,4);
    g->addEdge(1,5);
    g->addEdge(2,3);
    g->addEdge(2,6);
    g->addEdge(4,6);
    g->addEdge(4,7);
    g->addEdge(4,8);
    g->addEdge(5,6);
    g->addEdge(5,7);
    g->addEdge(5,8);
    
    
    
   
   
    

    // Print the graph adjacency list
    g->print();

    return 0;
}
