#ifndef __DISTANCES_H
#define __DISTANCES_H
#include <cmath>

#include "weighted_struct_digraph.h"

// In all of these cases I assume that a and b are of the same type
// and that a is the current node and b is the node I want to go to

const double EARTH_RADIUS =
    6371.0;  // Earth's radius in kilometers (use this one)

template <typename T>
float haversine(const WeightedStructDigraph<T> &g, const T &a, const T &b) {
    // I return the geodesic distance between a and b
    // Meaning the distance on a great circle.
    // I use the haversine formula for this.
    return 0.0;
}

template <typename T>
float euclidean(const WeightedStructDigraph<T> &sdg, const T &a, const T &b) {
    /*
    I return the euclidean distance between a and b
    S . . . .
    . \ . . .
    . . \ . .
    . . . Z .
    . . . . .
    */
    return 0.0;
};

template <typename T>
float manhattan(const WeightedStructDigraph<T> &g, const T &a, const T &b) {
    /*
    I return the manhattan distance between a and b
    S - - ┐ .
    . . . | .
    . . . | .
    . . . Z .
    . . . . .
    */
    return 0.0;
};

template <typename T>
float out_degree(const WeightedStructDigraph<T> &g, const T &a, const T &b) {
    // I return a heuristik which is dependend on the indegree of b
    // meaning the number of edges going out of b
    return 0.0;
};

#endif