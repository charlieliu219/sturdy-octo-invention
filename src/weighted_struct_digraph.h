/******************************************************************************
 *
 * A directed graph, where the vertex names are arbitrary strings.
 *
 * Based on the source code from Robert Sedgewick and Kevin Wayne at
 *https://algs4.cs.princeton.edu/
 *
 ******************************************************************************/

#ifndef __STRUCT_DIGRAPH_H__
#define __STRUCT_DIGRAPH_H__

#include <string>
#include <vector>

#include "vlib/edge.h"
#include "vlib/redblack_bst.h"
#include "vlib/weighted_digraph.h"

using namespace std;

// Implements a class representing a directed graph, where the vertex names are
// arbitrary strings
// each vertex itself is a struct defined by user
template <typename Node>
class WeightedStructDigraph {
    // store all the nodes
    vector<Node> Airports;
    // store all the weighted edges using Node indexes
    EdgeWeightedDigraph* Routes;
    // airport nodes -> graph index
    RedBlackBST<Node, int>* st;
   
public:
    // // default constructor
    // WeightedStructDigraph(){
    //     Routes = new EdgeWeightedDigraph;
    //     st = new RedBlackBST<Node, int>;
    // }
    // vector constructor
    WeightedStructDigraph(vector<Node> airport_list){
        // copy nodes into Airports
        Airports = airport_list;

        int V = airport_list.size();
        Routes = new EdgeWeightedDigraph(V);

        // create a BST of nodes - index (st is pointer to the root node)
        st = new RedBlackBST<int, Node>;
        // st pairs all the nodes with 0, ... v-1
        for (auto )
        cout << "I'm in the vector constructor!" << endl;
    }

    // copy constructor
    WeightedStructDigraph(const WeightedStructDigraph& other){
        Airports = other.Airports;
        Routes = other.Routes;
        st = other.st;
    }
    // move constructor
    // When the move constructor is called, the default move constructor of std::vector will be automatically invoked, which efficiently transfers the contents and ownership of the Airports vector from the other object to the new object being constructed.
    WeightedStructDigraph(WeightedStructDigraph&& other) :
        Airports(other.Airports),
        Routes(other.Routes),
        st(other.st)             
    {
        other.Routes = nullptr;
        other.st = nullptr;
    }
    // copy assignment
    WeightedStructDigraph& operator=(const WeightedStructDigraph& other){
        delete Airports;
        delete Routes;
        delete st;

        // copy
        Airports = new vector<Node>(other.Airports);
        Routes = new EdgeWeightedDigraph(other.Routes);
        st = new RedBlackBST<Node, int>(other.st);
        return (*this);
    }
    // move assignment
    WeightedStructDigraph& operator=(WeightedStructDigraph&& other){
        delete Airports;
        delete Routes;
        delete st;

        Airports = other.Airports;
        Routes = other.Routes;
        st = other.st;

        other.routes = nullptr;
        other.st = nullptr;
    }
    // destructor
    ~WeightedStructDigraph(){
        // delete Airports;
        delete Routes;
        delete st; 
    }

    // Implementieren Sie die folgenden Methoden aus SymbolGraph:
    // - contains
    bool contains(const Node& Airport) const { return (st->contains(Airport)); }

    // - index_of
    int index_of(const Node& Airport) const { return (*(st->get(Airport))); }

    // - name_of
    Node name_of(const int v) const { return (Airports[v]); }

    // - get_graph: get Routes?
    const EdgeWeightedDigraph* get_graph() const { return (Routes); }

    // Zusätzlich brauchen wir:
    // - add_edge
    // Edges will be realized after construction using an add_edge function that calls the corresponding function on the inner graph.
    // reuse the Edge class from the lecture for our weighted edges. To do this, you should reuse the EdgeWeightedDigraph
    // The add_edge function will take the two nodes and the weight of the edge between them as arguments

    // add edge from a -> b
    void add_edge(const Node a, const Node b, float weight){
        int v = this->index_of(a); // from v
        int w = this->index_of(b); // to w
        Edge e(v, w, weight);
        Routes->add_edge(e);
        return;
    }

};


#endif
