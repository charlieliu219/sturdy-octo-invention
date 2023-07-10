
#include <functional>
#include <vector>

#include "vlib/bag.h"
#include "vlib/min_pq.h"
#include "weighted_struct_digraph.h"

template <typename T>
std::vector<T> a_star(
    const WeightedStructDigraph<T>& sdg, const T& source, const T& dest,
    std::function<float(const WeightedStructDigraph<T>&, const T&, const T&)>
        heuristic) {
    // TODO: Implementieren Sie hier den A*-Algorithmus
    // Bedenken Sie das die Distamzmaße aus distances.h nicht in Stunden sind
    // und umgewandelt werden müssen und daher nicht _direkt_ genutzt werden
    // können.
    return std::vector<T>();
}